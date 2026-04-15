# Project 6

## Intro

Project 6 is a fairly simple program to implement. You don't have to do it this way but I recommend doing it in 2 steps. 

1) Implement a single threaded version where you implement a function is_prime()  
2) Multithread it  

Multithreading is a slightly tough topic because it is one of those features where you have to have it in mind while you build your project.

Think about it: A thread takes some function and all of its necessary parameters as its own constructor arguments. The thread has a pointer to the function, does some magic under the hood, and invokes that function with the arguments. This means, that any work we want done has to have some function as an entry point. In other words, it's not really a good idea to make a monolithic procedural section that does all of our work for us. 

## Single Thread Version

The main function that's important is some function called is_prime(). is_prime should be a predicate (boolean) function that simply takes a number, and calculates if it's prime or not. The instructions lay it out but for clarity, I'll provide a solution:

```cpp
bool is_prime(int num){
	int candidate = num / 2;
	for(int i = 2; i <= candidate; i++){
		if(num % i == 0){
			return false;
		}
	}
	return true;
}
```
The instructions for Project6 say to stop when you get to the target number divided by 2. In other words, if we want to check if 1000 is prime, we keep dividing it by numbers until we hit 500. We simply iterate for every number up until that candidate point, looking for a number that will cleanly divide the target number.

Now, in our main function, we can simply do a loop calculating every number up to a million to see if each number is prime.  This is a basic for loop or whatever just going up to some const TARGET = 1'000'000 or however you want to do it.

## Multi Thread Version

Now we need to multi thread it. But first let's think about the work that needs to be done from a thread's perspective.

1) A Thread needs some function to work on. This means, if we're calculating if a number is prime for a million numbers, we need a function that can loop over a million numbers.

2) If we have a function that loops over a million numbers, we need a way for each thread to know the correct number to work on. Otherwise, we're just gonna have threads working on the same numbers just at different times. What we REALLY want is for each thread to work on a unique number out of the million numbers. We're splitting up the work to be done with threads.

3) We also need to print out to a file or to console at least. In both of these scenarios, we need a way to make sure that the counter we're accessing, and the io device that we're accessing is protected while the thread is using it. So, we need a mutex (mutual exclusion) and lock for critical sections.

So, let's create a helper function that will be the main entry point for each thread. Our helper will be passed to a thread's constructor, and it'll have sections to check a global counter that all the threads will use to see which number needs to be calculated next using is_prime. We'll also have a section where we can write our output. IO devices need to be accessed one at a time, so this section will also be protected with a lock and mutex. We also need to update the global count of prime numbers, so this should be protected as well.

Remember, if there is some resource that is going to be shared by threads, you need to protect. This means isprime doesn't need to be protected, each thread will have its own instance of is_prime, but if a thread is reading from or writing to something like a shared counter, that counter needs to be protected with a mutex and its lock.

Here's a version from class that's slightly different from what the project requires. Don't just copy paste this, because the requirements for the project are slightly different.

```cpp
void find_primes()
{
    size_t local_current = 0;
    bool flag = true;
    while(flag)
    {
        { //we've created a block here so that we can create a guard
          //and then we leave the scope, immediately freeing the mutex
            lock_guard<mutex> first_guard(current_mutex);
            local_current = current_number++;
            if(local_current > TARGET){
                flag = false;
                break;
            }
            cout << "Checking number: " << local_current << endl;
        }
        if(is_prime(local_current))
        {
            lock_guard<mutex> second_guard(write_mutex);
            out << local_current << endl;
            counter++;
        }
    }
}
```

Finally in main, you just need to create threads to do the job. Note: I have not included the globals you need. You'll need a global mutex or two. You'll need a global current_number that each thread will check. You'll need a global counter that will count the total number of primes found. You'll also need a global ofstream to write to (primes.dat).

Each function will have its own non-shared local_counter that you can use for reporting how many primes that thread found. 

In main you can do the threads like so:

```cpp
thread t1(find_primes);
thread t2(find_primes);
...
t1.join();
t2.join();
```

OR you can use a loop 

```cpp
for(auto i = 0; i < num_threads; i++){
    threads.push_back(thread(find_primes));
}
for(auto& t : threads){
    t.join();
}
```

Slightly more elegant.

### Links

https://cplusplus.com/reference/multithreading/

https://www.geeksforgeeks.org/multithreading-in-cpp/

### Thread

Threads are you start a process. This is the easiest part of multithreading. All you do is create a new thread from the \<thread\> library and you're set.

```c++
#include <thread>

...

some_function(param1, param2, ...){...}

std::thread th1(some_function, param1, param2, ...)

th1.join;
```

There's a common theme in c++ where if you start something, you need to end it. When we create a thread, we end it by calling join. Join sits somewhere toward the end of our code and kind of catches our thread and rejoins it to the main process. Think of threading as a branching of execution, and joining is pulling the thread back together.

### Mutex

This is the important part. This is the resource that's actually responsible for managing a shared resource.

Some resources, like IO are shared. What this means is the OS manages it, and anyone who wants to write (console, text file, whatever) needs to ask for permission. If IO is computer speech, then in computer land, we use a talking stick and can only speak when it's our turn. If we don't manage the talking stick (IO), then effectively, we have a bunch of people yanking on the stick, being rude, and next thing you know we have societal collapse on our hands.

So a Mutex is a lockable object that basically wraps a section of code. It says, "Hey, I am about to speak, this section is critical, do not interrupt me." It gets exclusive access to resources when locked. It's basically all the same talking stick rules, now being enforced with a body guard. Whoever holds the stick is protected, and anyone that tries to grab the stick will get punched in the face.

Generally the mutex needs to be accessible globally or statically.

```C++

#include <mutex>

std::mutex mtx1;

```

### Locks

A mutex has methods lock, and unlock. There are also objects that provide advanced locking functionality.

The Locks are the bodyguard's tools. They ensure that the body guard can do its job safely. 

```C++

std::mutex mtx;

//critical section
mtx.lock();
for(int i : some_collection){
	std::cout << i << endl;
}
mtx.unlock;

```

In c++, it's a common trend that if you make something, you need to destroy it when you're done. When you open something, you've gotta close it. Same deal with locks. If you lock it, you gotta unlock it.

Similarly, we have smart pointers that gives us unique_ptr, we have unique_lock. It handles the locking and unlocking for us.

```C++
std::mutex mtx;

void print_block (int n, char c) {
  // critical section (exclusive access to std::cout signaled by lifetime of lck):
  std::unique_lock<std::mutex> lck (mtx);
  for (int i=0; i<n; ++i) { std::cout << c; }
  std::cout << '\n';
}
```

Here we have a unique_lock of template type mutex. It's called lck, and it takes an existing mutex as its constructor argument. It will now manage that mutex. It's like the boss of the bodyguard. Now we don't have to worry about locking and unlocking. 

### Condition Variable

A condition variable is an object that receives a lock object like a unique_lock, and blocks access, or stops it from executing. It's the big boss. This thing basically says, hey, I have a signal to wait, and I have a signal to notify you to go. Generally, when we spin up a bunch of threads, they start ripping as soon as they're active. So, we can make those threads wait until we're ready to start. Once we're ready, we can send a notify_all, and then the threads will all start going ham trying to get their jobs done. You use std::condition_variable, call it cv, and use cv.wait() and cv.notify_all().

https://cplusplus.com/reference/condition_variable/condition_variable/

### Atomic

Atomic types are types that geared specifically toward multithreading. They won't cause race conditions. Basically if you have a bool, use atomic_bool, etc. There are atomic versions of most types. If you need a data type to be shared, then make it atomic.

### Videos and Extra Materials

https://www.youtube.com/watch?v=7ENFeb-J75k&t=82s
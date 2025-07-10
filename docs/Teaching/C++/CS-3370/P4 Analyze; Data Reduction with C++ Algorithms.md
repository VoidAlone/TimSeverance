In this program you will analyze digitized data for pulses. The data comes from an actual digitizer that reports voltages (except all the data has been reversed by the hardware – you must negate all values before proceeding).

The data is quite jagged, so for finding pulses we will use a smooth version instead. In a new vector, copy the first 3 numbers from the original, negated data. Then, starting with the 4th point of the file (position [3], of course), and ending with the 4th from the last, replace each of those points with the following weighted average of its neighbors (the current point in question is pointed to by “iter”):

(iter[-3] + 2\*iter[-2] + 3\*iter[-1] + 3\*iter[0] + 3\*iter[1] + 2\*iter[2] + iter[3]) / 15

Then copy the last 3 numbers over to fill out the smoothed vector.
The smooth data will be better for detecting pulses

You detect a pulse by looking for a rise over three consecutive points. If the rise (y<sub>(i + 2)</sub> - yi) exceeds vt, (for “voltage threshold” – supplied by an input parameter), then a pulse begins at position i. After finding a pulse, move forward through the data starting at yi+2 until the samples start to decrease before looking for the next pulse.

Write a program that process all files with a “.dat” extension in the current directory. There can be an arbitrary number of such files, and an arbitrary number of sample data values within each file. Print out where pulses are found and the “area” underneath the pulses. The area is merely the sum of the values starting at the pulse start and going for width samples (another input parameter), or until the start of the next pulse, whichever comes first. Use the original, unsmoothed data to compute the area, however. (The smooth data is just for detecting pulses.)

There is one “gotcha”. Sometimes it is hard to distinguish “piggyback” pulses (where a pulse is adjacent to another) from a wide pulse with some variation to it. To distinguish these, we use the following parameters:

| Parameter        | Description                                  |
| ---------------- | -------------------------------------------- |
| drop_ratio       | A number less than 1                         |
| below_drop_ratio | The number of values less than drop_ratio    |
| pulse_delta      | The gap between pulses to look for piggyback |
After you have found where pulses begin, check to see if the start of a pulse is followed by another pulse that starts within (<=) pulse_delta positions of it. If this occurs, find how many points between the peak of the first pulse and the start of the second pulse (non-inclusive; only look at point strictly inside this interval) are strictly less than drop_ratio times the height of the peak of the first pulse. If the number exceeds below_drop_ratio, omit the first pulse from further consideration (it is not a pulse of interest).

Read all parameters from an .ini file like the following at program startup (specified in argv/argc; don’t hard-code them):

```
# Pulse parameters 
vt=100 
width=100 
pulse_delta=15 
drop_ratio=0.75 
below_drop_ratio=4
```

All parameters are necessary and no others are allowed. Enforce this. Lines beginning with ‘#’ are comments so ignore them. Blank lines are allowed and should also be ignored.

If a .dat file has no pulses, ignore it. For those that do, report the pulse start positions and their areas in the following format (you should get these same answers):

```
as_ch01-0537xx_Record1042.dat: 
Found piggyback at 1020 
Found piggyback at 1035 
1050 (8228) 

Invalid file: test.dat 

2_Record2308.dat: 
1019 (3540) 
1030 (22916) 

2_Record3388.dat: 
1020 (43272) 
1035 (41264)
```

The second .dat file has pulses of interest at (zero-based) positions 1019 and 1030, with respective areas 3540 and 22916. The order of appearance of the .dat files is not important.

### <u>Implementation Notes </u>
First get the program working, and then consider using [lambda expressions](https://en.cppreference.com/w/cpp/language/lambda) and [algorithms](https://en.cppreference.com/w/cpp/algorithm) such as copy, transform, and accumulate, along with istream_iterators to avoid some loops and make the code shorter and more readable. How are you going to discover all the .dat files in the current directory? Use the std::filesystem. Also, verify that the .ini file is present and valid. Here are some sample runs for the invalid .ini files:

```
Charless-MacBook-Pro:prog-analyze chuck$ ./a.out error1.ini 
Invalid value for vt in error1.ini 
Charless-MacBook-Pro:prog-analyze chuck$ ./a.out error2.ini 
Invalid INI file: missing one or more keys 
Charless-MacBook-Pro:prog-analyze chuck$ ./a.out error3.ini 
Invalid or duplicate INI key: foo
```

1. Piecemeal growth. Get little pieces to work, one at a time 
2. You may start with loops: If you don’t know how to do it with an algorithm, do it with a loop first. 
3. To smooth using a transform, you have to get the index (“iter”) in the example. If you use a lambda expression, pass the integer by reference. Then you can get the address of it, and assign it to a pointer (something like: (int& i) { int* iter = &I; …} Then you can use the pointer as if it’s an array, as in the example smoothing code. (If you don’t use a lambda, it’s the same thing.) 
4. You do a lot with the index, or the position number. When you first find the index of the start of each pulse, you can do it with a for_each, but you have to go through some gyrations to get the index. But if you use a for-loop, you have the index already. So USE A FOR LOOP. The code is cleaner. 
5. I found it useful to build a little struct that holds things like the index and value of the start of a pulse, and the same thing for its peak. 
6. I found it useful to first find all the possible pulses, and then throw away the ones that happen before the peak of the previous one. To do so, I used uniq – but note that uniq reorders, but does not resize. 
7. In finding piggyback pulses, since you are looking at adjacent pulses, I used adjacent_find, because it gives me both pulses. (Just have it return false always.) 
8. Don’t hard-code path names (“.” Should work)
### Rubric
#### File I/O 
Clean Code 
No repeated code (refactor); 
No unnecessary code. 
Use std::filesystem.
Simplest possible logic to fulfill program requirements; use algorithms and iterator adaptors to avoid needless loops (I only have 4 loops) to make code more readable; use lambdas and/or standard function objects to avoid writing needless function bodies; use std::accumulate to compute the area. 

#### Defensive Programming
Exceptions thrown as requested 

#### Other 
Proper use of command-line arguments as assigned. 
Reasonable error checking when processing .ini file
### Logistics
- Having issues with zybooks. Don't worry, we'll still be able to function
- Get pytest installed, I think we're gonna do the pytest way.

### Project 1 overview
Project 1 is just a simple introduction to implementing, testing, and submitting your projects. You'll do some way easy stuff, get some free points, and submit it. Seriously, it's 4 arithmetic functions and you get 100 points.
### Project 2 overview
Project 2 is the real start. We have 8 projects, but really it's 7. Every week, we'll start by going over the project requirements, loading up the idea in our minds, and then hitting the material with the project in mind.

## Notes for Module 1

### Intro to algorithms
Algorithms describe steps to solve some problem. Baking a cake, directions to CS401, or sorting lists can all use algorithms. Algorithms can be expressed in natural language, pseudocode, formal languages, whatever.

Computational problems are problems that can be solved with computers given some input. We use algorithms to help solve these. Some algorithms are more efficient than others, as in they take less time or space to solve a problem, or they might be inefficient but easy to implement. There are lots of different ways to solve problems, some are better than others, but most of the time they have different pros and cons.

### NP - Complete problem (Nondeterministic Polynomial time)
1. No efficient [[#algorithm]] has been found to solve it
2. No one has proven that an efficient algorithm is impossible to find
3. If it exists for one problem, then all NP-complete problems can be solved efficiently

If it's NP-Complete, don't focus on the perfect solution, just a good inefficient one.

### How Data Structures and Algorithms relate to eachother

#### Algorithms for data structures

Data structures are a way to organize, store, and perform operations on data.

Data structures require specific operation to be performed on their data. This means that there are algorithms specific to different data structures. 

For example, inserting an item into a linked list for example requires a very different algorithm than inserting into an array.  

Array insertion generally requires some variation of the following
1. Create new array\[size + 1\]
2. Copy items from old array to new array
3. Shift all items in the array forward from the position to be inserted
4. Insert item into now empty position

Linked list insertion generally requires some variation of the following

1. Nodes contain pointers to next node
2. Create new object to be inserted
3. Get "next" pointer of left node and assign to new object's "next" pointer
4. Set next pointer of left node to new object to be inserted. 
5. Objects are now linked 

#### Data structures for algorithms

Book mentions an algorithm that determines top employees, might use an array to store employee data.

### Abstract Data Types (ADT)

Abstraction is a really common theme that you'll see throughout your courses. It's one of the main ways that we grapple with difficult concepts and engage with "reality" as humans. In the context of ADTs, I like to think of abstraction as the degree of scope or resolution that we view a certain problem with.

ADTs focus more on the what rather than the how.

Stacks, Heaps, Lists etc are examples of ADTs. When we talk about using a stack, an idea comes to mind of how data will be stored and handled without worrying about the concrete implementation. Stacks are FILO and so we understand that data coming in will be pushed to the bottom of a stack, and new data will pile on top of it. In order to reach information at the bottom, we have to remove stuff on top to get there.

What we're not thinking about is the actual programmatic implementation of how a particular stack might work. A stack can be implemented with lots of different data types.

https://cplusplus.com/reference/stack/stack/
### Efficiency

Computational Complexity can consist of time T(N) and space S(N) complexity (how fast it goes, and how much space it takes up) where N is the input. 

Algorithms are typically measured by their best, average, and worst case scenarios. Best is minimum operations, worst is max.

Space complexity include input data and additional memory allocation. Auxillary space complexity is just the additional memory allocation.

N represents input
k represents some constant number

### About me
- I'm 30
- Background, WV, SP-BR, BYU-I, UVU, etc.
- I play guitar, enjoyer of death metal. Fallujah, rivers of nihil, ulcerate, aegaeon, cynic, death
- I love sushi, but really any dishes with rice I usually go crazy for
- Slight anime nerd. Eva, HxH, Trigun, .hack, Akira, Ghost in the Shell, CSM, JJK, etc
- R6 Siege, Elden Ring
- Reading, movies, hobby collection
### Class Structure
- Each week, on the first day, we'll go over the project spec together, and start to think about the problems we'll need to solve. We might look at the test cases, potential pain points, function names, etc.
- After reviewing the projects, we'll move on to the course material with the project details in mind. 
- Each day, we'll have a 10-15 minute break in the middle to stretch our legs, get a drink, catch our breath.
- If we have enough time, we'll do an in-class activity going over classic data structure / algorithm interview questions

### Warnings
- I do not make the coursework. I am an adjunct, not a mentor. Let me repeat that, I don't make the coursework, or any of the material. I'm here to deliver it to you, help you understand it, and guide you through the work. Someone had the audacity to complain about the fact that I didn't create my own material when I explained that day 1 a few semesters ago. I'm also not in control of zybooks. If there are issues, it's an administrative issue that comes from zybooks or the department. All I can do to fix things is send emails and hope people respond quickly. So let it be written, that I don't make the material.
- I can't be your debugger. I can offer support in the way of tips and tricks to have a better debugging experience. I can guide you in terms of understanding different algorithms, and data structures, and generally what to do. I can sympathize with you when you say that finding your bug took a long time. What I can't do is sit down with your code and step through it and identify what's wrong for you. 
- Summer semester is FAST. I'm gonna try and ease the pain as much as I can. We might have to cram some things in here and there, but generally, I understand it's a lot to learn in a small amount of time. You all probably have other stuff going on too, so I get it. Let me know if you're struggling, and we can hash it out. 
- If attendance gets too low, I will enforce an attendance policy. I hate basing grades off attendance, but the overall class experience diminishes greatly if people aren't coming to class. Class is better with you there. 

### Success
- Get your sleep. Seriously, this is probably the most important thing. Staying awake burning the midnight oil might feel like what you're supposed to do, and with how fast things go, you might have to stay up a bit. But seriously, get your 8 hours, make sure you're rested. Take mental breaks. Come back to it if it's not clicking. If it comes down to you not sleeping so that you can get your project in on time, let me know, get your rest, and I'll flex the date by a day.
- Read. The CS major is really a reading and writing major. Yes, we're hitting algorithms and data structures, and we're sometimes doing math adjacent things, but more than anything, what you're doing is communication.
- Get used to drawing/writing. Honestly, the easiest way to grasp material in this class is often to draw things out and walk through problem steps on paper, whiteboard, onenote, whatever.
- Group up. We don't tolerate plagiarism. But we do love it when students get together, explain topics to eachother, suggest strategies for approaching a problem, help eachother succeed, and make friends. 
- Have fun. Realize that although this course will be fast, this is a real meat and potatoes course. This is one of the true CS classes that you'll take, with topics that'll be useful to you whether you're building a compiler, implementing a social media website, or making a video game. Look ahead to the future, and get pumped for the cool stuff you'll learn!
- Get ahead of the work. Don't lose the basically free points that come from the reading. Get those in on time. Even if you need to skim ahead, get your PA points. It's the freest way to get points, which will potentially give you more wiggle room on the exams and projects. They can be the deciding factor between matriculation or not.
- Engage during class-time. I know it's tough sometimes to speak up, and sometimes there might be someone who appears to know a lot, so you don't want to embarrass yourself. It's really fine though, we're all in different places, and chances are, a lot of other people are wondering the same thing you are, and big chances are, someone may not even realize they have a question (very dangerous). So pipe up, ask questions, and be engaged. We'll have a lot better of a time if everyone has fun and talks during class!


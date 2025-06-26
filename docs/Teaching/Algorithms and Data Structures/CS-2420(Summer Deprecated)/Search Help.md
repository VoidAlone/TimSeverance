
[Firstly, here's a geeksforgeeks article on the jump search](https://www.geeksforgeeks.org/jump-search/#)
### Jump Search

**Jump search works a lot like linear search. Where linear search walks through an array one item at a time, jump search walks through an array one block at a time. There are several ways you can handle back tracking, but here's the general approach to the jump search.**

#### Algorithm
`Set your jump size equal to some number, ideally int(sqrt(len(lyst)))`
`Iterate through your list by intervals of jump size`
`If the current index is equal to the target, return True or whatever`
`If the current index is greater than your target, you'll need to backtrack`

`To backtrack, set a start point equal to the index of your previous iteration, and an end point equal to the current index.`
`Linear search from start point to end point`

Jump Size = int(sqrt(len(lyst))) = 3

Target = 8

| Index     | 0   | 1   | 2   | 3   | 4   | 5   | 6    | 7      | 8   | 9       |
| --------- | --- | --- | --- | --- | --- | --- | ---- | ------ | --- | ------- |
| Value     | 1   | 2   | 3   | 4   | 5   | 6   | 7    | 8      | 9   | 10      |
| Jump      | 1st |     |     | 2nd |     |     | 3rd  | Target |     | 4th     |
| Iteration |     |     |     |     |     |     | prev |        |     | current |

If we use a for loop
`for i in range (0, len(lyst), jump_size)`

We'll start at index 0, jump ahead to index 3, jump ahead to 6, and jump ahead to 9

If our target is 8, by the time we're on our 4th jump, we can see that the value at our index is greater than our target i.e. (lyst[i] > target)

So, we know that we'll want to search between our previous jump index, and our current jump index. That's where we can linear search (or whatever search really)

#### Edge Cases
We have problems to look out for. Making sure we don't go out of bounds when jumping, and keeping track of the previous jump point.

##### Out of Bounds
How we check OoB may vary if you're doing a while loop or for loop. To check for OoB with a for loop approach, the check should be done towards the end of the iteration after we've already decided that our current index value isn't greater than our target. 

If we know that the next jump will put us out of bounds, we know we're close to the end of the list. So, we can go ahead and linear search here. We'll likely need to do it this way since the step size is only evaluated once at the beginning of a for loop statement (we'll see why exactly when we implement our linked lists), so we can't change the step size of our for loop.

If we do it with a while loop, we can go ahead and modify the step size to be equal to the remaining space, jump to the very last index of the array, and perform a check. Is our index value equal to the target? Is our index value greater than the target? etc.

##### Previous Interval
In a for loop implementation, I simply keep track of the previous index by setting previous equal to the current index at the very end of the loop

prev = 0

for i in ...:
- check stuff
- do stuff
- prev = i

This way, in the second iteration, i = 3, prev = 0. 


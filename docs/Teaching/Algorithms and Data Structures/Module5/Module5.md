# Stacks

## Stack ADT  

A stack is a FILO (First in, last out) data structure.

*Typical Operations*

|    |    |
| -- | -- |
| Push | Appends an item to the "top" (top is just conceptual)|
| Pop | Removes an item from the top, sometimes returns the item |
| Peek | Checks what an element is at a given index |
| Top | Checks the top element |

Stacks work by putting one item on top of the other. While technically you can yank something out from under a stack, you can think of trying to remove a pancake from the middle of a stack, or a plate of dishes. Screws the whole thing up.

Stacks can be implemented using any underlying container you want. So why use a stack instead of a list or something similar? It's all about creative constraints.

## Stack Applications  

You're surrounded by constraints. Rooms are defined in terms of walls at specific angles and lengths, recipes are defined by ingredients, diet, and flavor; In short, complex structures and algorithms are defined by constraints all around us. Constraints provide us with useful guardrails and boundaries for creating useful objects.

So why not use a list? Let's look at some applications of a stack, and some of its benefits, and the natural structrues that we use for abstractions.

### Real life

Stacks appear everywhere in daily life, often without us noticing. Consider a stack of dishes: you place the clean plate on top, and when you need one, you take from the top. The last plate placed is the first one removed. This natural LIFO (Last In, First Out) behavior mirrors how many processes unfold over time.

Think of a stack of papers on your desk: you add new documents to the top and work through them from the top down. Or consider an undo stack in software: each action you take is pushed onto a stack, and when you hit "undo," the most recent action is popped off and reversed.

What makes stacks profound is that they encode *process*—the order in which things happened. A stack doesn't just store data; it stores the *history* of how that data was added. This temporal dimension is what makes stacks naturally suited for tracking sequences of operations, whether in computing, logistics, or everyday decision-making. The constraint of only accessing the top isn't a limitation—it's a feature that enforces orderly progression through a sequence.

### Stack Frame

When a function is called in most programming languages, a new *stack frame* is pushed onto the call stack. This frame is a block of memory that contains:

- **Local variables**: Variables declared within the function
- **Parameters**: The arguments passed to the function
- **Return address**: Where execution should continue after the function returns
- **Saved registers**: CPU registers that need to be preserved

The call stack operates as a literal stack of these frames. When function A calls function B, which calls function C, the stack grows: A's frame is at the bottom, B's frame is on top of it, and C's frame is at the very top. When C returns, its frame is popped, and execution resumes in B with its state intact. When B returns, the same happens, and A continues.

This stack-based execution model is fundamental to how computers manage function calls, recursion, and local scope. Each frame represents a snapshot of a function's state at a particular point in execution. The stack of frames together forms a complete history of the computational process—which functions were called, in what order, and what their local state was at each step. Debugging tools use this information to produce stack traces, showing you exactly how the program arrived at its current point.

### Semantic Analysis

In compiler design, *semantic analysis* is the phase where the compiler verifies that your program makes sense beyond just syntax. Stacks play a crucial role in this process, particularly in evaluating expressions and managing context.

**AST Evaluation**: An Abstract Syntax Tree (AST) represents the hierarchical structure of an expression. To evaluate an AST, you can use a stack-based approach:
1. Traverse the tree (often post-order: left, right, root)
2. When you encounter a leaf node (a number), push it onto the stack
3. When you encounter an operator, pop the required operands, perform the operation, and push the result back

For example, to evaluate `3 + 4 * 2`:
- Push 3 → Stack: [3]
- Push 4 → Stack: [3, 4]
- Push 2 → Stack: [3, 4, 2]
- Encounter `*`: pop 2 and 4, compute 4 * 2 = 8, push 8 → Stack: [3, 8]
- Encounter `+`: pop 8 and 3, compute 3 + 8 = 11, push 11 → Stack: [11]

**Recursive Descent Parsing**: This parsing technique mirrors the structure of the grammar itself. Each function call implicitly uses the call stack to track where it is in the parsing process. When parsing nested expressions like `(1 + (2 * 3))`, the call stack naturally handles the nesting:
- `parseExpression()` calls `parseTerm()` for the inner `2 * 3`
- `parseTerm()` calls `parseFactor()` for the `3`
- As each function returns, the stack unwinds, building the result from the inside out

The stack provides the mechanism for both managing the depth of nested structures and tracking the state of evaluation at each level.

### Shunting Yard Algorithm 

The *Shunting Yard Algorithm*, invented by Edsger Dijkstra, converts infix expressions (like `3 + 4 * 2`) into postfix notation (also called Reverse Polish Notation, or RPN: `3 4 2 * +`). This conversion is essential because computers evaluate postfix expressions much more efficiently than infix.

**Why convert to postfix?** Infix notation requires knowing operator precedence and handling parentheses to determine evaluation order. Postfix notation eliminates these complications entirely—it can be evaluated with a simple stack-based algorithm without any ambiguity.

**How it works**: The algorithm uses two data structures:
- An **output queue** for the final postfix expression
- An **operator stack** for temporarily holding operators and parentheses

The basic rules:
1. **Numbers**: Always go directly to the output queue
2. **Left parentheses `(`**: Push onto the operator stack
3. **Right parentheses `)`**: Pop operators from the stack to the output until a left parenthesis is found (discard both parentheses)
4. **Operators**: Pop operators from the stack to the output while the operator on top has greater or equal precedence, then push the current operator

**Example**: Converting `3 + 4 * 2` to postfix:
- `3` → output: `3`
- `+` → stack: [`+`]
- `4` → output: `3 4`
- `*` has higher precedence than `+`, so push → stack: [`+`, `*`]
- `2` → output: `3 4 2`
- End: pop remaining → output: `3 4 2 * +`

This algorithm is fundamental in calculators, compilers, and any system that needs to evaluate mathematical expressions.

## Shunting Yard  

**Implementation for basic arithmetic operators and parentheses**

Here's the simplest implementation of the Shunting Yard algorithm for `+`, `-`, `*`, `/`, and parentheses:

```python
def shunting_yard(expression):
    """Convert infix expression to postfix notation."""
    output = []
    operator_stack = []
    
    # Define operator precedence
    precedence = {'+': 1, '-': 1, '*': 2, '/': 2}
    
    # Tokenize (simplified: assumes single-digit numbers or separated by spaces)
    tokens = expression.split()
    
    for token in tokens:
        if token.isdigit():
            # Number: add to output
            output.append(token)
        elif token in precedence:
            # Operator: pop higher/equal precedence operators to output
            while (operator_stack and 
                   operator_stack[-1] != '(' and 
                   precedence.get(operator_stack[-1], 0) >= precedence.get(token, 0)):
                output.append(operator_stack.pop())
            operator_stack.append(token)
        elif token == '(':
            operator_stack.append(token)
        elif token == ')':
            # Pop until matching '('
            while operator_stack and operator_stack[-1] != '(':
                output.append(operator_stack.pop())
            if operator_stack:
                operator_stack.pop()  # Remove the '('
    
    # Pop remaining operators
    while operator_stack:
        output.append(operator_stack.pop())
    
    return ' '.join(output)


def evaluate_postfix(postfix):
    """Evaluate a postfix expression."""
    stack = []
    tokens = postfix.split()
    
    for token in tokens:
        if token.isdigit():
            stack.append(int(token))
        else:
            b = stack.pop()
            a = stack.pop()
            if token == '+':
                stack.append(a + b)
            elif token == '-':
                stack.append(a - b)
            elif token == '*':
                stack.append(a * b)
            elif token == '/':
                stack.append(a // b)
    
    return stack[0]


# Example usage
expression = "3 + 4 * 2"
postfix = shunting_yard(expression)
result = evaluate_postfix(postfix)

print(f"Original: {expression}")
print(f"Postfix:  {postfix}")
print(f"Result:   {result}")
```

**Key points**:
- The algorithm runs in O(n) time
- It handles operator precedence correctly
- It can be extended for functions (like `sin`, `cos`) by treating them as special tokens
- Error handling should be added for malformed expressions in production code

## Extras  

**Common Stack Problems**

1. **Valid Parentheses**: Given a string containing just `(){}[]`, determine if the input is valid. Use a stack to match opening and closing brackets.

2. **Min Stack**: Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

3. **Stack Sort**: Sort a stack using only one additional stack and no other data structures.

4. **Tower of Hanoi**: Classic recursive problem that demonstrates stack-based thinking.

**Performance Characteristics**

| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| Push      | O(1)           | O(1)             |
| Pop       | O(1)           | O(1)             |
| Peek      | O(1)           | O(1)             |
| Search    | O(n)           | O(n)             |

**When to Use Stacks**

- When you need LIFO behavior
- For undo/redo functionality
- To track state in recursive algorithms
- For parsing and evaluating expressions
- In depth-first search (DFS) graph traversal

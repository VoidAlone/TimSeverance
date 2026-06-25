### Notations

In every day math we are accustomed to "infix" mathematical notation where the operator of an expression is placed "in" between the two operands of the expression: 1+2.

This is "easily" readable and feels a lot like most languages' order of operations which would be Subject-Verb-Object ordering. The most common orderings are SVO or SOV. 

Tim Ate Apples (42% of languages)
Tim Apples Ate (45% of languages)

#### Postfix

Postfix notation is similar, I'd say, to that Subject-Object-Verb (SOV) ordering. Also known as Reverse Polish Notation, it has the operators affixed to the right side of an expression i.e. 12+.

Why might we prefer a notation like this? Because, computers can't think on their own. They can only do exactly what we tell them, and it's much easier to have them read left to right without looking ahead and compensating for ambiguity.

Postfix notation is wildly useful for stack based evaluation of expressions and generating unambiguous abstract syntax trees.

Ambiguity is the crux of the situation, and postfix eliminates it entirely.

#### Algorithm
### Stacks


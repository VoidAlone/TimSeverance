foo->bar == (*foo).bar

- foo being a pointer to an object, with *foo.bar the compiler evaluates the dot operator first. Which results in *(foo.bar) or in otherwords, we're dereferncing a supposed pointer bar. *foo.bar yields dereferencing bar of foo. We get bar from foo, and then dereference that pointer. If we want to access members of a pointer to an object then we need to evaluate the pointer first, thus the parens (*foo).bar. This explicitly forces us to dereference foo, and grab the member bar, dereferencing bar of foo. The operator -> is a shortcut for this.
- We don't need to distinguish between dot operator and -> operator in other languages because languages like python, c#, java etc. don't usually let us access by pointer (except for c# when in unsafe mode)

Size_t vs int and such

- Size_t is specifically designed to around system storage.
- Size_t is guaranteed to represent the max size of any object in memory
- Could be 16, 32, or 64.
- Returned by size_of()

Const, constexpr, enum.

- I made a goof and talked about readonly. That's a c# thing, my bad. I do think there's a property

Declaration vs Definition

- I DECLARE BANKRUPTCY!!! No inherit meaning, just a word without much to it. In the world of programming it's basically just an identifier with a type that can be turned into a symbol for use by the compiler.
- Definitions give meaning. In other words, when we do an assignment, or define a function with a body, the declaration is given substance, and actual information to be stored in the computer.

- Struct vs Class

- What's the difference in C++?
- What's the difference in C?

- Pragma Once vs Include Guard

NOTE: Semantics are crucial, but often debated. When we use certain words, we assign certain meaning to those words, and people spend a lot of time debating on whether or not the exact words and what they mean are correct. Don't worry too much about getting lost in the weeds of semantics, just be willing to change and adapt your understanding to match better, more informed definitions.
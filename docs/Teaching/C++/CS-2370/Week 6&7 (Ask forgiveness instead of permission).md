### Exceptions

[errors and exception handling in modern c++](https://learn.microsoft.com/en-us/cpp/cpp/errors-and-exception-handling-modern-cpp?view=msvc-170)

- A try block surrounds normal code, which is exited immediately if a throw statement executes.
- A throw statement appears within a try block; if reached, execution jumps immediately to the end of the try block. The code is written so only error situations lead to reaching a throw. The throw statement provides an object of a particular type, such as an object of type "runtime_error", which is a class defined in the stdexcept library. The statement is said to throw an exception of the particular type. A throw statement's syntax is similar to a return statement.
- A catch clause immediately follows a try block; if the catch was reached due to an exception thrown of the catch clause's parameter type, the clause executes. The clause is said to catch the thrown exception. A catch block is called a handler because it handles an exception.

[try, throw, catch Statements (C++)](https://learn.microsoft.com/en-us/cpp/cpp/try-throw-and-catch-statements-cpp?view=msvc-170)

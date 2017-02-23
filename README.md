# Math Functions
A C++ library containing most commonly used mathematics routines in solving Project Euler.
While this is written to improve upon code reusability while attempting Project Euler, I hope that others will also find this useful.

## Usage
Download the .cpp and .h files and add them to your project directory

```
$ g++ -std=c++11 -c MathFuncsLib.cpp
$ ar rvs MathFuncsLib.a MathFuncsLib.o
```
This creates an archive file.
Now include the header file into your source code

```
//main.cpp

#include <iostream>
#include "MathFuncsLib.h"

int main() {
  std::cout << "Hello World" << std::endl;
  return 0;
}
```
Now go back to your terminal to compile.
```
$ g++ -std=c++11 main.cpp MathFuncsLib.a
```
This should compile and run without any errors. And make sure you are using C++11 compiler

## Documentation
Working on it...

## To do (in no particular order)
- [ ] Finding nth prime
- [ ] Whether a number is pandigital
- [ ] Whether a number is permutation of another number
- [ ] Sum of multiples of a number
- [ ] Whether 3 numbers form a triangle
- [ ] Check for Pythagorean triplet
- [ ] Divisors count (proper and improper)
- [ ] Prime factorization and prime factors count
- [ ] Collatz Sequence
- [ ] Champernowne's Constant
- [ ] Factorials
- [ ] Computations with days of the year
- [ ] Fibonacci Index
- [ ] Combinatorics
- [ ] Concatenating integers
- [ ] Check for perfect square
- [ ] Triangular, Pentagonal and Hexagonal numbers

## Contributing
At this stage, there not many functionalities available. If you think you have an awesome suggestion (all suggestions are awesome!), feel free to open an issue with your feature. If you already implemented it, open a pull request.

If you have a better implementation or optimization to any of the algorithms I've used, submit your proposal, properly commented, with a pull request and I'll look into it.
The only contributing guideline is "Don't mess up existing code and try to follow the same style (unless you think it is inefficient)"

## Issues
This is a work in progress. I try my best to keep the code bug free and correct. But some edge cases may not be fully tested. If you come across any bug, file an issue and I will look into it. I might add some test cases and CI, in the near future, for keeping the code free of bugs.

## License
This is released under the MIT License. See the license for more info.

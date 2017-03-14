/**
 ** MathFuncsLib
 ** Licensed under MIT License by Aparajithan Venkateswaran
 ** 2017
 **
 */

#pragma once
#ifndef MATH_FUNCTIONS_H
#define MATH_FUNCTIONS_H

#include <iostream>
#include <vector>

using std::vector;
using std::int64_t;

namespace Primes {
	//All functions relating to prime numbers and primality tests

	//Returns a vector array of prime numbers
	int64_t* primeList(int64_t upperLimit);

	//Returns a prime sieve of boolean values
	bool* primeSieve(int64_t size);

	//Primality test
	bool isPrime(int64_t n);

	//Greatest prime factor
	int64_t greatestPrimeFactor(int64_t num);
}

namespace Sequences {
	//All functions relating to series and sequences

	//nth Fibonacci number
	int64_t fibonacci(int64_t n);
	int64_t* fibonacciList(int n);

	//Sums
	int64_t sumSeries(int size, int coeff);

	//Sum multiples
	int64_t sumMultiples(int64_t upperLimit, int64_t multiple);

	//Factorials
	int64_t factorial(unsigned int n);
	int64_t* factorialList(unsigned int n);
}

namespace Arithmetic{
	//Miscellaneous Arithmetic

	//Split number into digits
	int* digitizeArray(int64_t n);
	vector<int> digitizeVector(int64_t n);

	//Palindrome
	bool isPalindrome(int64_t number, int base);

	//Pandigital
	bool isPandigital(int64_t n, bool zero);

	//Permutation
	//bool isPermutation(int64_t n, int64_t m);

	//Perfect square
	bool isPerfectSquare(int64_t n);

	//Concatenate integers
	int64_t concatInt(int64_t a, int64_t b);
}

namespace privateFunctions{
	int64_t* doubleArray(int64_t* a, int64_t* size);
}

#endif // !MATH_FUNCTIONS_H
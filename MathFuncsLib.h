/**
 ** MathFuncsLib
 ** Licensed under MIT License by Aparajithan Venkateswaran
 ** 2017
 **
 */

#pragma once

#include <iostream>
#include <vector>

using std::vector;
using std::int64_t;

namespace Primes {
	//All functions relating to prime numbers and primality tests

	//Returns a vector array of prime numbers
	vector<int64_t> primeList(int64_t upperLimit);

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
}

namespace Arithmetic{
	//Miscellaneous Arithmetic

	//Split number into digits
	int* digitizeArray(int64_t n);
	vector<int> digitizeVector(int64_t n);
}

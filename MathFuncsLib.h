/**
 ** MathFuncsLib.h
 */

#pragma once

#include <vector>

using std::vector;

namespace Euler{
	//All functions relating to prime numbers and primality tests
	class Primes{
	public:
		//Returns a vector array of prime numbers
		vector<int64_t> primeList(int64_t upperLimit);

		//Returns a prime sieve of boolean values
		bool* primeSieve(int64_t size);

		//Primality test
		bool isPrime(int64_t n);

		//Greatest prime factor
		int64_t greatestPrimeFactor(int64_t num);
	};
}
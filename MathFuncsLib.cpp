/** 
 ** MathFuncsLib.cpp
 */

#include "MathFuncsLib.h"
#include <vector>
#include <cstring>
#include <stdexcept>

using namespace std;

namespace Euler {

	//A vector array of prime numbers
	vector<int64_t> Primes::primeList(int64_t upperLimit) {
		vector<int64_t> primes;
		primes.push_back(2);

		for (int64_t i = 3; i <= upperLimit; i += 2) {

			//Check for primality
			bool prime = true;
			for (int j = 0; j < primes.size() && primes[j] * primes[j] <= i; ++j) {
				if (i % primes[j] == 0) {
					prime = false;
					break;
				}
			}
			if (prime) {
				primes.push_back(i);
			}
		}

		return primes;
	}

	//Boolean prime sieve - much faster than vector implementation
	bool* Primes::primeSieve(int64_t size) {
		bool* prime = new bool[size + 1];
		memset(prime, true, size + 1);				//faster than loops and vectors
		prime[0] = false;
		prime[1] = false;

		for (int64_t p = 2; p*p <= size; p++) {
			if (prime[p] == true) {
				for (int64_t i = p * 2; i <= size; i += p) {
					prime[i] = false;
				}
			}
		}
		return prime;
	}
}
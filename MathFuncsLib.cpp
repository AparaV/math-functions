/** 
 ** MathFuncsLib.cpp
 */

#include "MathFuncsLib.h"
#include <vector>
#include <cstring>
#include <cmath>
#include <stdexcept>

using namespace std;

namespace Primes {

	//A vector array of prime numbers
	vector<int64_t> primeList(int64_t upperLimit) {
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
	bool* primeSieve(int64_t size) {
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

	//Primality test
	bool isPrime(int64_t n) {
		if (n <= 1) {
			return false;
		}
		for (int64_t i = 2; i * i <= n; ++i) {
			if (n %i == 0) {
				return false;
			}
		}
		return true;
	}

	//Greatest prime factor
	int64_t greatestPrimeFactor(int64_t num) {
		int64_t largestFactor = 0;
		int64_t sqrtNum = sqrt(num) + 1;

		for (int64_t i = 2; i < sqrtNum; ++i) {
			if (num % i == 0) {
				largestFactor = i;
				num /= i;
				while (num %i == 0) {
					num /= i;
				}
			}
		}

		return largestFactor;
	}
}

namespace Sequences {

	//nth Fibonacci number
	int64_t fibonacci(int64_t n) {
		int64_t a = 1, b = 1, c;
		if (n <= 0) {
			return -1;
		}
		if (n == 1 || n == 2) {
			return a;
		}
		for (int i = 3; i <= n; ++i) {
			c = a + b;
			a = b;
			b = c;
		}
		return c;
	}
}

namespace Arithmetic {
	
	//Digitize number
	int* digitizeArray(int64_t n) {
		int length = static_cast<int>(log10(n) + 1);
		int* digits = new int[length];
		for (int i = length - 1; i >= 0; ++i) {
			digits[i] = n % 10;
			n /= 10;
		}
		return digits;
	}
	//Digitize number into vector
	vector<int> digitizeVector(int64_t n) {
		int length = static_cast<int>(log10(n) + 1);
		vector<int> digits(length, 0);
		for (int i = length - 1; i >= 0; ++i) {
			digits[i] = n % 10;
			n /= 10;
		}
		return digits;
	}
}
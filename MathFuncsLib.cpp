/**
 ** MathFuncsLib
 ** Licensed under MIT License by Aparajithan Venkateswaran
 ** 2017
 **
 */

#include "MathFuncsLib.h"
#include <vector>
#include <cstring>
#include <cmath>
#include <stdexcept>
#include <sstream>
#include <map>

using namespace std;

namespace Primes {

	//A vector array of prime numbers
	int64_t* primeList(int64_t upperLimit) {
		int size = 10, index = 0;
		int64_t* primes = new int64_t[size];
		primes[index] = 2;
		index++;

		for (int64_t i = 3; i <= upperLimit; i += 2) {
			bool prime = true;
			for (int j = 0; j < index && primes[j] * primes[j] <= i; ++j) {
				if (i % primes[j] == 0) {
					prime = false;
					break;
				}
			}
			if (prime) {
				primes[index] = i;
				index++;
				if (index == size) {
					primes = privateFunctions::doubleArray(primes, &size);
				}
			}
		}
		primes[index] = -1;

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

	//nth prime
	int64_t findPrime(int n) {
		if (n <= 0) {
			return -1;
		}
		if (n == 1) {
			return 2;
		}
		if (n == 2) {
			return 3;
		}
		int64_t prime;
		int64_t* primes = new int64_t[n];
		primes[1] = 2;
		int maxSize = n, currSize = 1;
		int counter = 1, curr = 3;
		while (counter != n) {
			bool isPrime = true;
			for (int i = 1; i <= currSize; ++i) {
				if (curr % primes[i] == 0) {
					isPrime = false;
					break;
				}
			}
			if (isPrime) {
				counter++;
				primes[++currSize] = curr;
				if (currSize >= maxSize - 1) {
					primes = privateFunctions::doubleArray(primes, &maxSize);
				}
			}
			curr += 2;
		}
		prime = primes[currSize];
		delete[] primes;
		return prime;
	} // end of nth prime

	//Prime factors
	int64_t countPrimeFactors(int64_t n) {
		int64_t factors = 0;
		for (int64_t i = 2; i <= sqrt(n) + 1; ++i) {
			if (n % i == 0) {
				factors++;
				n /= i;
				while (n % i == 0) {
					n /= i;
				}
			}
		}
		if (n > 2) {
			factors++;
		}
		return factors;
	}

	map<int, int> primeFactors(int n) {
		map<int, int> factors;
		int size = sqrt(n) + 1;
		for (int i = 2; i <= size; ++i) {
			if (n % i == 0) {
				factors[i] = 1;
				n /= i;
				while (n % i == 0) {
					factors[i]++;
					n /= i;
				}
			}
		}
		if (n > 2) {
			factors[n] = 1;
		}
		return factors;
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
	//Fibonacci List
	int64_t* fibonacciList(int n) {
		int64_t* list = new int64_t[n + 2];
		list[0] = 0;
		list[1] = 1;
		for (int i = 2; i <= n; ++i) {
			list[i] = list[i - 1] + list[i - 2];
		}
		list[n + 1] = -1;
		return list;
	}

	//Sum Series
	int64_t sumSeries(int size, int coeff) {
		int64_t sum = 0;
		if (coeff == 1) {
			sum = size*(size + 1) / 2;
		}
		else if (coeff == 2) {
			sum = size*(size + 1)*(2 * size + 1) / 6;
		}
		else if (coeff == 3) {
			sum = size*(size + 1) / 2;
			sum *= sum;
		}
		else {
			for (int i = 1; i <= size; ++i) {
				sum += pow(i, coeff);
			}
		}
		return sum;
	}

	//Sum multiples
	int64_t sumMultiples(int64_t upperLimit, int64_t multiple) {
		int64_t number = upperLimit / multiple;
		return multiple * number * (number + 1) / 2;
	}

	//Factorials
	int64_t factorial(unsigned int n) {
		if (n <= 1) {
			return 1;
		}
		int64_t prod = 1;
		for (int i = 2; i <= n; ++i) {
			prod *= i;
		}
		return prod;
	}

	int64_t* factorialList(unsigned int n) {
		int64_t* list = new int64_t[n + 1];
		list[0] = 1;
		list[1] = 1;
		for (int i = 2; i <= n; ++i) {
			list[i] = list[i - 1] * i;
		}
		return list;
	}

	//Collatz Sequence
	int64_t nextCollatz(int64_t n) {
		if (n % 2 == 0) {
			return n / 2;
		}
		return 3 * n + 1;
	}
	int64_t collatzLength(int n) {
		int64_t count = 1;
		while (n != 1) {
			n = Sequences::collatzLength(n);
			count++;
		}
		return count;
	}

	//Champernowne's Constant
	string champernowne(int n) {
		int digits = 1, multiplier = 1, number = 0;
		while (number < n) {
			multiplier *= 10;
			number += digits * (multiplier - 1);
			digits++;
		}
		int upperLimit = multiplier - 1;
		stringstream ss;
		for (int i = 1; i <= n; ++i) {
			ss << i;
		}
		return ss.str();
	}

} // end of sequences and series

namespace Arithmetic {

	//Digitize number
	int* digitizeArray(int64_t n) {
		int length = static_cast<int>(log10(n) + 1);
		int* digits = new int[length + 1];
		for (int i = length - 1; i >= 0; ++i) {
			digits[i] = n % 10;
			n /= 10;
		}
		digits[length] = -1;
		return digits;
	}

	//Palindrome
	bool isPalindrome(int64_t number, int base) {
		int64_t reversed = 0, temp = number;
		while (temp > 0) {
			reversed = base * reversed + temp % base;
			temp /= base;
		}
		return number == reversed;
	}

	//Pandigital - adapted from http://stackoverflow.com/a/2485016/5055644
	bool isPandigital(int64_t n, bool zero) {
		int count = 0, digits = 0, x = 1, temp;
		if (zero) {
			x = 0;
		}
		while (n > 0) {
			temp = digits;
			digits |= (1 << (int)((n % 10) - x));
			if (temp == digits) {
				return false;
			}
			count++;
			n /= 10;
		}
		return digits == (1 << count) - 1;
	}

	//Permutation
	/*bool isPermutation(int64_t n, int64_t m) {
		int A = 0, B = 0, temp;
		while (n > 0) {
			temp = A;
			A ^= (1 << static_cast<int>((n % 10) - 1));
			n /= 10;
		}
		while (m > 0) {
			temp = B;
			B ^= (1 << static_cast<int>((m % 10) - 1));
			m /= 10;
		}
		return A == B;
	}*/

	//Perfect square
	bool isPerfectSquare(int64_t n) {
		double x = sqrt(n);
		return x == static_cast<int>(x);
	}

	//Concatenate integers
	int64_t concatInt(int64_t a, int64_t b) {
		int temp = b;
		while (temp > 0) {
			a *= 10;
			temp /= 10;
		}
		return a + b;
	}

	//Divisiors
	int64_t* divisors(int64_t n, bool proper) {
		int64_t* result = new int64_t[10];
		int maxSize = 10, currSize = 1;
		result[0] = 1;
		for (int i = 2; i*i < n; ++i) {
			if (n % i == 0) {
				result[currSize++] = i;
				if (currSize >= maxSize - 1) {
					result = privateFunctions::doubleArray(result, &maxSize);
				}
				result[currSize++] = n / i;
				if (currSize >= maxSize - 1) {
					result = privateFunctions::doubleArray(result, &maxSize);
				}
			}
		}
		if (!proper) {
			result[currSize] = n;
			if (currSize >= maxSize - 1) {
				result = privateFunctions::doubleArray(result, &maxSize);
			}
		}
		result[currSize] = -1;
		return result;
	}
}

/*Geometry*/
namespace Geometry {

	//check for triangle
	bool isTriangle(int64_t a, int64_t b, int64_t c) {
		if ((a + b > c) && (b + c > a) && (c + a > b)) {
			return true;
		}
		return false;
	} // end of check for triangle

	//pythagorean triplet
	bool isRightTriangle(int64_t a, int64_t b, int64_t c) {
		if (a*a + b*b == c*c) {
			return true;
		}
		else if (b*b + c*c == a*a) {
			return true;
		}
		else if (c*c + a*a == b*b) {
			return true;
		}
		return false;
	} // end of right triangle
} // end of geometry

/*Private Functions*/
namespace privateFunctions {

	//Array doubling
	int64_t* doubleArray(int64_t* a, int* size) {
		int64_t* newArray = new int64_t[2 * (*size)];
		for (int i = 0; i < *size; ++i) {
			newArray[i] = a[i];
		}
		(*size) *= 2;
		delete[] a;
		return newArray;
	}

} // end of namespaceprivateFunctions

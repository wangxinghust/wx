#include <algorithm>
#include <vector>
using namespace std;

// Runtime: 168 ms, faster than 24.68% of C++ online submissions for Count Primes.
// Memory Usage : 8.2 MB, less than 88.98 % of C++ online submissions for Count Primes.
class Solution {
public:
	int countPrimes(int n) {
		int count = 0;
		for (int i = 2; i < n; i++) {
			if (isPrime(i)) count++;
		}
		return count;
	}
	bool isPrime(int num) {
		if (num == 2 || num == 3) return 1;
		if (num % 6 != 1 && num % 6 != 5) return 0;
		int tmp = sqrt(num);
		for (int i = 5; i <= tmp; i += 6)
			if (num % i == 0 || num % (i + 2) == 0) return 0;
		return 1;
	}
};

// Runtime: 192 ms, faster than 22.44% of C++ online submissions for Count Primes.
// Memory Usage : 8.1 MB, less than 95.19 % of C++ online submissions for Count Primes.
class Solution2 {
public:
	int countPrimes(int n) {
		if (n <= 2) return 0;
		int count = 1;
		for (int i = 3; i < n; i += 2) {
			if (isPrime(i)) count++;
		}
		return count;
	}
	bool isPrime(int num) {
		if (num == 2 || num == 3) return 1;
		if (num % 6 != 1 && num % 6 != 5) return 0;
		int tmp = sqrt(num);
		for (int i = 5; i <= tmp; i += 6)
			if (num % i == 0 || num % (i + 2) == 0) return 0;
		return 1;
	}
};


// The Sieve of Eratosthenes is one of the most efficient ways to find all prime numbers up to n
// Runtime: 80 ms, faster than 42.41% of C++ online submissions for Count Primes.
// Memory Usage : 8.5 MB, less than 78.42 % of C++ online submissions for Count Primes.
class Solution3 {
public:
	int countPrime(int n) {
		vector<bool> isPrime(n);
		for (int i = 2; i < n; i++) {
			isPrime[i] = true;
		}
		// Loop's ending condition is i * i < n instead of i < sqrt(n)
		// to avoid repeatedly calling an expensive function sqrt().
		for (int i = 2; i * i < n; i++) {
			if (!isPrime[i]) continue;
			for (int j = i * i; j < n; j += i) {
				isPrime[j] = false;
			}
		}
		int count = 0;
		for (int i = 2; i < n; i++) {
			if (isPrime[i]) ++count;
		}
		return count;
	}
};
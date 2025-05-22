//function to calculate first N prime numbers
// This function uses the Sieve of Eratosthenes algorithm to find all prime numbers up to a given limit.

#include <bits/stdc++.h>
using namespace std;

vector<int> sieve(int limit) {
    vector<int> primes;
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false; 

    for (int i = 2; i <= limit; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}
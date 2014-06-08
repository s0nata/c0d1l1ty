#!/usr/bin/python
# number factorization algorithm based on the sieve of Eratosthenes
# from https://codility.com/media/train/9-Sieve.pdf

import sys

def sieve_int(n):
    sieve = [0] * (n + 1)

    i = 2
    while( i * i < n):
        if (sieve[i] == 0):
            j = i * i
            while(j <= n):
                if (sieve[j] == 0):
                    sieve[j] =  i;
                j += i
        i += 1

    return sieve
    
def factorization(n,divisors):
    prime_factors = []
    
    while(divisors[n] > 0):
        prime_factors += [divisors[n]]
        n /= divisors[n]
        
    prime_factors += [n]
    
    return prime_factors
    
n = int(sys.argv[1])
tmp = sieve_int(n)
primes = factorization(n,tmp)

print "Here are the prime factors of %s:" % n
for i in primes:
    print i
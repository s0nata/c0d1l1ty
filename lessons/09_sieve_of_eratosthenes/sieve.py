#!/usr/bin/python
# Sieve  of Eratosthenes algorithm inplementation from
# https://codility.com/media/train/9-Sieve.pdf

import sys

def sieve( n ):
    print("Here are the prime nubers between 1 and %s:" % (n))
    
    sieve = [True] * (n + 1)
    sieve[0] = sieve[1] = False
    i = 2
    while ( i * i <= n):
        if (sieve[i]):
            k = i * i
            while (k <= n):
                sieve[k] = False
                k += i
        i += 1

    for i in range(0,n):
        if (sieve[i]):
            print i
        
    return 

sieve(int(sys.argv[1]))

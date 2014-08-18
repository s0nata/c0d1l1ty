/*
 * Source: https://codility.com/demo/take-sample-test/count_non_divisible
 * Result: 22/100 @ https://codility.com/demo/results/demoFEKV2E-9AT/
*/

#include <algorithm> //max_element()
#include <vector>
#include <set>

// 'sieve of Eratosthenes' modification
// to get an array of the least prime
// factors for numbers up to n (1-to-1)
vector<int> least_facts(int& n) {
    vector<int> sieve(n+1,0);
    int i = 2;
    
    while (i*i < n) {
        if (sieve[i] == 0) {
            int j = i*i;
            while (j <= n) {
                if (sieve[j] == 0) sieve[j] = i;
                j += i;
            }
        }
        i++;
    }
    
    return sieve;
}

// find all prime factors of n
vector<int> find_primes(int n) {
    vector<int> sieve = least_facts(n);
    
    vector<int> primes;
    while (sieve[n] > 0) {
        primes.push_back(sieve[n]);
        n /= sieve[n];
    }
    primes.push_back(n);
    
    return primes;
}

// find all divisors of n, including 1 and n
set<int> find_divisors(int& n) {
    vector<int> primes = find_primes(n);
    set<int> divs;
    int tmp, factors_num = primes.size();
    
    for(int fn = factors_num; fn > 0; fn--) {
        for(int pos = 0; pos <= factors_num - fn; pos++) {
            tmp = 1;    
            for(int mtp = pos;mtp < pos + fn; mtp++) {
                tmp *= primes[mtp];    
            }
            divs.insert(tmp);
            divs.insert(n/tmp);
        }    
    }
    
    return divs;
}

vector<int> solution(vector<int> &A) {
    int N = A.size();
    
    // aux vector to store numbers of occurences of elements in A    
    int max_A = *max_element(A.begin(),A.end());
    vector<int> occurences(max_A+1,0);
    for(int i = 0; i < N; i++) occurences[A[i]]++;
    
    //for each element of A (no repeats here)
    //(looping through _occurences_)
    // 1) find its divisors;
    // 2) find number of their occurences
    //    and substract it from the total
    //    number of elements
    vector<int> ndivisors_occs(max_A+1,N);
    for(int i = 0; i < max_A + 1;i++) {
        if (occurences[i] != 0) {
            //find divisors
            set<int> occi_divs = find_divisors(i);
            //store their number of occurences
            for (set<int>::iterator it = occi_divs.begin();
                 it != occi_divs.end(); it++) {
                ndivisors_occs[i] -= occurences[*it];        
            }
        }    
    }
    
    // construct the answer
    vector<int> res(N); 
    for(int i = 0; i<N;i++) {
        res[i] = ndivisors_occs[A[i]];    
    }

    return res;
}

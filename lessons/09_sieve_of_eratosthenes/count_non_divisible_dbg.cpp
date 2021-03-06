/*
 * Source: https://codility.com/demo/take-sample-test/count_non_divisible
 * Result: 22/100 @ https://codility.com/demo/results/demoFEKV2E-9AT/
 * Result: 44/100 @ https://codility.com/demo/results/demoTY7TCM-WWC/
 * Result: 66/100 @ https://codility.com/demo/results/demo4GRJGZ-R8V/
 *         same as brute force approach
 *         still return larger numbers than should in performance tests
*/

//debugging previous soultion

#include <algorithm> //max_element()
#include <vector>
#include <set>

//void pout(vector<int>& vec) {
//    int n = vec.size();
//    for(int i = 0; i < n; i++) cout << vec[i] << "\t" ;
//    cout << endl;
//}

// 'sieve of Eratosthenes' modification
// to get an array of the least prime
// factors for numbers up to n (1-to-1)
vector<int> least_facts(int& n) {
    vector<int> sieve(n+1,0);
    int i = 2;
    
    while (i < n) {
        if (sieve[i] == 0) {
            int j = i;
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
vector<int> find_primes(int n, vector<int>& sieve) {
//    vector<int> sieve = least_facts(n);
    
    vector<int> primes;
    while (sieve[n] > 0) {
        primes.push_back(sieve[n]);
        n /= sieve[n];
    }
    primes.push_back(n);
    
    return primes;
}

// find all divisors of n, including 1 and n
set<int> find_divisors(int& n, vector<int>& sieve) {
    vector<int> primes = find_primes(n,sieve);

//cout << "n = " << n << endl;
//cout << "primes\n\t";
//pout(primes);

    set<int> divs;
    int tmp, factors_num = primes.size();
    
    for(int fn = factors_num; fn > 0; fn--) {
        for(int pos = 0; pos <= factors_num - fn; pos++) {
            tmp = 1;    
            for(int mtp = pos;mtp < pos + fn; mtp++) {
                tmp *= primes[mtp];    
            }
//cout << "\t\ttmp = " << tmp << "\tn/tmp = ";
            divs.insert(tmp);
//cout << n/tmp << endl;
            divs.insert(n/tmp);
        }    
    }
    
    return divs;
}

vector<int> solution(vector<int> &A) {
    int N = A.size();
//cout << "N = " << N << endl;
    // aux vector to store numbers of occurences of elements in A    
    int max_A = *max_element(A.begin(),A.end());
    vector<int> occurences(max_A+1,0);
    for(int i = 0; i < N; i++) occurences[A[i]]++;
    
//vector<int> idx(max_A+1,0);
//for(int i = 1; i < max_A + 1;i++) idx[i] = i;
//pout(idx);

//cout << "A\n";
//pout(A);

//cout << "occurences\n";
//pout(occurences);
    
    //for each element of A (no repeats here)
    //(looping through _occurences_)
    // 1) find its divisors;
    // 2) find number of their occurences
    //    and substract it from the total
    //    number of elements
    vector<int> ndivisors_occs(max_A+1,N);
    vector<int> min_divs_sieve = least_facts(max_A);
    
    for(int i = 0; i < max_A + 1;i++) {
//cout << "\t i = " << i << endl;
        if (occurences[i] != 0) {
            //find divisors
            set<int> occi_divs = find_divisors(i,min_divs_sieve);
            //store their number of occurences
            for (set<int>::iterator it = occi_divs.begin();
                 it != occi_divs.end(); it++) {
//cout << "\t div = " << *it << endl;
//cout << "\t occs(div) = " << occurences[*it] << endl;
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
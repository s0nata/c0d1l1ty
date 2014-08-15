/*
 * Source: https://codility.com/demo/take-sample-test/count_non_divisible
 * Result:  22/100
 */

// improving my prev. solution from https://codility.com/demo/results/demoKP3WWY-KFV/

#include<vector>
#include<algorithm>    //max element
#include<iostream>

vector<int> solution(vector<int> &A) {
    int N = A.size();
    
    if (N == 1) {
        vector<int> not_divisors(1,0);
        return not_divisors;
    }
    
    //find the actual max element in A
    int maxA = *max_element(A.begin(),A.end());
    cout << "max el " << maxA << endl;
    
    // count how many times each element is met in A
    vector<int> occurences(maxA+1,0);
    
    for(int i = 0; i < N; i++) {
        occurences[A[i]]++;
    }
    
    cout <<  "occurences\n";
    for (int i = 0; i < occurences.size(); i++) cout << occurences[i] << "  ";
    cout << endl;
    
    // make sort of eratosthenes sieve for possible
    // max element of A (2*N from the task info)
    
    vector<int> sieve(maxA+1,0);
    int p = 2, q;
    while ( p * p < maxA ) {
        if (sieve[p] == 0) {
            q = p * p;
            while (q <= maxA) {
                if (sieve[q] == 0) {
                    sieve[q] = p;
                }
                q += p;
            }
        }
        p++;
    }
    
    // actual work
    vector<int> not_divisors(N,N);
    vector<int> factors;
    
    for (int i = 0; i < N; i++) {
        factors.clear();
        if (A[i] > 1) {
            not_divisors[i] -= occurences[1]; // number of "1" in A
        }
        not_divisors[i] -= occurences[A[i]]; //number of self-occurences
        //here fill the "factors" vector
        //but it may contain duplicates
        //and it contains only half of the divisors
        int M = A[i];
        while (sieve[M] > 0) {
            factors.push_back(sieve[M]);
            M /= sieve[M];
        }
        factors.push_back(M);
        //so here more factors
        // how to do it in a correct way?
        int T = factors.size();
        for (int t= 0; t < T;t++) {
            for (int u = t + 1; u < T;u++ ){
                factors.push_back(factors[t]*factors[u]);
            }
        }
        
        cout << "current A[" << i <<"] " << A[i];
        cout <<  "\n  factors\t\t";
        for (int z = 0; z < factors.size(); z++) cout << factors[z] << "  ";
        cout << endl;
        
        for (unsigned int j = 0; j < factors.size();j++) {
            //not prime number
            //here somehow manage duplicates in factors aux array
            //so not to substract twice for same thing
            if (factors[j] != A[i]) {
                not_divisors[i] -= occurences[factors[j]];
            }
        }
        
        cout <<  "  non-divisors\t\t " << not_divisors[i]<<endl;
    }
    
    return not_divisors;
}

/* Your test case [24 15 4 8 7] : NO RUNTIME ERRORS 
 * (returned value: [1, 4, 4, 1, 4] )
 * Output:
 *
 * max el 24
 * occurences
 * 0  0  0  0  1  0  0  1  1  0  0  0  0  0  0  1  0  0  0  0  0  0  0  0  1  
 * current A[0] 24
 *   factors		2  2  2  3  4  4  6  4  6  6  
 *   non-divisors		 1
 * current A[1] 15
 *   factors		3  5  15  
 *   non-divisors		 4
 * current A[2] 4
 *   factors		2  2  4  
 *   non-divisors		 4
 * current A[3] 8
 *   factors		2  2  2  4  4  4  
 *   non-divisors		 1
 * current A[4] 7
 *   factors		7  
 *   non-divisors		 4
*/

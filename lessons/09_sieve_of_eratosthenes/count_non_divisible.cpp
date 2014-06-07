/*
 * Source: https://codility.com/demo/take-sample-test/count_non_divisible
 * Result:  22/100 @ https://codility.com/demo/results/demoKP3WWY-KFV/
 * 
 * You are given a non-empty zero-indexed array A consisting of N
 * integers.
 *
 * For each number A[i] such that 0 ≤ i < N, we want to count the number
 * of elements of the array that are not the divisors of A[i]. We say
 * that these elements are non-divisors.
 *
 * For example, consider integer N = 5 and array A such that:
 *
 *   A[0] = 3
 *   A[1] = 1
 *   A[2] = 2
 *   A[3] = 3
 *   A[4] = 6
 *
 * For the following elements:
 *
 *       A[0] = 3, the non-divisors are: 2, 6,
 *       A[1] = 1, the non-divisors are: 3, 2, 3, 6,
 *       A[2] = 2, the non-divisors are: 3, 3, 6,
 *       A[3] = 3, the non-divisors are: 2, 6,
 *       A[6] = 6, there aren't any non-divisors.
 *
 * Write a function:
 *
 *   vector<int> solution(vector<int> &A); 
 *
 * that, given a non-empty zero-indexed array A consisting of N
 * integers, returns a sequence of integers representing the amount of
 * non-divisors.
 *
 * The sequence should be returned as:
 *
 *       a structure Results (in C), or
 *       a vector of integers (in C++), or
 *       a record Results (in Pascal), or
 *       an array of integers (in any other programming language).
 *
 * For example, given:
 *
 *   A[0] = 3
 *   A[1] = 1
 *   A[2] = 2
 *   A[3] = 3
 *   A[4] = 6
 *
 * the function should return [2, 4, 3, 2, 0], as explained above.
 *
 * Assume that:
 *
 *       N is an integer within the range [1..50,000];
 *       each element of array A is an integer within the range [1..2*N].
 *
 * Complexity:
 *
 *       expected worst-case time complexity is O(N*log(N));
 *       expected worst-case space complexity is O(N), beyond input
 *         storage (not counting the storage required for input
 *         arguments).
 *
 * Elements of input arrays can be modified.
 */

#include<vector>

vector<int> solution(vector<int> &A) {
    int N = A.size();
    
    if (N == 1) {
        vector<int> not_divisors(1,0);
        return not_divisors;
    }
    
    // count how many times each element is met in A
    vector<int> occurences(2*N+1,0);
    
    for(int i = 0; i < N; i++) {
        occurences[A[i]]++;
    }
    
    // make sort of eratosthenes sieve for possible
    // max element of A (2*N from the task info)
    
    vector<int> sieve(2*N+1,0);
    int p = 2, q;
    while ( p * p < 2*N ) {
        if (sieve[p] == 0) {
            q = p * p;
            while (q <= 2*N) {
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
        int M = A[i];
        while (sieve[M] > 0) {
            factors.push_back(sieve[M]);
            M /= sieve[M];
        }
        factors.push_back(M);
        for (unsigned int j = 0; j < factors.size();j++) {
            //not odd number
            if (factors[j] != A[i]) {
                not_divisors[i] -= occurences[factors[j]];
            }
        }
    }
    
    return not_divisors;
}

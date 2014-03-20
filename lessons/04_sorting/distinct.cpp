/*
 * Source: https://codility.com/demo/take-sample-test/distinct
 * Result: 100/100 @ https://codility.com/demo/results/demo3UFF5N-RCA/
 *
 * Write a function
 *
 *   int solution(const vector<int> &A); 
 *
 * that, given a zero-indexed array A consisting of N integers,
 * returns the number of distinct values in array A.
 *
 * Assume that:
 *
 *       N is an integer within the range [0..100,000];
 *       each element of array A is an integer within the range
 *           [−1,000,000..1,000,000].
 *
 * For example, given array A consisting of six elements such 
 * that:
 *
 *   A[0] = 2    A[1] = 1    A[2] = 1
 *   A[3] = 2    A[4] = 3    A[5] = 1
 *
 * the function should return 3, because there are 3 distinct
 * values appearing in array A, namely 1, 2 and 3.
 *
 * Complexity:
 *
 *       expected worst-case time complexity is O(N*log(N));
 *       expected worst-case space complexity is O(N), beyond
 *          input storage (not counting the storage required for
 *          input arguments).
 *
 * Elements of input arrays can be modified.
 */

#include <algorithm>
int solution(const vector<int> &A) {
    // write your code in C++98
    int N = A.size();
    
    if (N == 0) {
        return 0;
    }
    
    vector<int> B (A);
    sort(B.begin(),B.end());
    
    int diff = 1;
    for(int i = 1; i < N; i++) {
        if (B[i] != B[i-1]) {
            diff++;
        }
    }
    
    return diff++;
}

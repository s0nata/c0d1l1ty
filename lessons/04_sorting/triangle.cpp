/*
 * Source: https://codility.com/demo/take-sample-test/triangle
 * Result: 93/100 @ https://codility.com/demo/results/demoDK9477-7FP/
 *
 * A zero-indexed array A consisting of N integers is given. A
 * triplet (P, Q, R) is triangular if 0 ≤ P < Q < R < N and:
 *
 *       A[P] + A[Q] > A[R],
 *       A[Q] + A[R] > A[P],
 *       A[R] + A[P] > A[Q].
 *
 * For example, consider array A such that:
 *
 * A[0] = 10    A[1] = 2    A[2] = 5
 * A[3] = 1     A[4] = 8    A[5] = 20
 *
 * Triplet (0, 2, 4) is triangular.
 *
 * Write a function:
 *
 *   int solution(const vector<int> &A); 
 *
 * that, given a zero-indexed array A consisting of N integers,
 * returns 1 if there exists a triangular triplet for this array
 * and returns 0 otherwise. For example, given array A such that:
 *
 * A[0] = 10    A[1] = 2    A[2] = 5
 * A[3] = 1     A[4] = 8    A[5] = 20
 *
 * the function should return 1, as explained above. Given array
 * A such that:
 *
 * A[0] = 10    A[1] = 50    A[2] = 5
 * A[3] = 1
 *
 * the function should return 0.
 *
 * Assume that:
 *
 *       N is an integer within the range [0..1,000,000];
 *       each element of array A is an integer within the range
 *           [−2,147,483,648..2,147,483,647].
 *
 * Complexity:
 *
 *       expected worst-case time complexity is O(N*log(N));
 *       expected worst-case space complexity is O(N), beyond
 *           input storage (not counting the storage required for
 *           input arguments).
 *
 * Elements of input arrays can be modified.
 */


#include <algorithm>
int solution(const vector<int> &A) {
    //C++98
    vector<int> B(A);
    sort(B.begin(),B.end());

    int N = B.size();
    for (int i = 0; i < N-2; i++) {
        if (B[i] >=0) {
            if ( B[i] + B[i+1] > B[i+2] ){
                if (B[i+1] + B[i+2] > B[i]) {
                    if (B[i] + B[i+2] > B[i+1]){
                        return 1;
                    }
                }
            }
        }
    }
    
    return 0;
}

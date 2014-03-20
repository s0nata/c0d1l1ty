/* 
 * Source: https://codility.com/demo/take-sample-test/min_avg_two_slice
 * Result: 100/100 @ https://codility.com/demo/results/demoGW5VAV-VDJ/
 * Based on: http://codesays.com/2014/solution-to-min-avg-two-slice-by-codility/
 *
 * A non-empty zero-indexed array A consisting of N integers is
 * given. A pair of integers (P, Q), such that 0 ≤ P < Q < N, is
 * called a slice of array A (notice that the slice contains at
 * least two elements). The average of a slice (P, Q) is the sum
 * of A[P] + A[P + 1] + ... + A[Q] divided by the length of the
 * slice. To be precise, the average equals 
 * (A[P] + A[P + 1] + ... + A[Q]) / (Q − P + 1).
 *
 * For example, array A such that:
 *
 *   A[0] = 4
 *   A[1] = 2
 *   A[2] = 2
 *   A[3] = 5
 *   A[4] = 1
 *   A[5] = 5
 *   A[6] = 8
 *
 * contains the following example slices:
 *
 *     slice (1, 2), whose average is (2 + 2) / 2 = 2;
 *     slice (3, 4), whose average is (5 + 1) / 2 = 3;
 *     slice (1, 4), whose average is (2 + 2 + 5 + 1) / 4 = 2.5.
 *
 * The goal is to find the starting position of a slice whose
 * average is minimal.
 *
 * Write a function:
 *
 *   int solution(vector<int> &A); 
 *
 * that, given a non-empty zero-indexed array A consisting of N
 * integers, returns the starting position of the slice with the
 * minimal average. If there is more than one slice with a minimal
 * average, you should return the smallest starting position of
 * such a slice.
 *
 * For example, given array A such that:
 *
 *   A[0] = 4
 *   A[1] = 2
 *   A[2] = 2
 *   A[3] = 5
 *   A[4] = 1
 *   A[5] = 5
 *   A[6] = 8
 *
 * the function should return 1, as explained above.
 *
 * Assume that:
 *
 *       N is an integer within the range [2..100,000];
 *       each element of array A is an integer within the range
 *          [−10,000..10,000].
 *
 * Complexity:
 *
 *       expected worst-case time complexity is O(N);
 *       expected worst-case space complexity is O(N), beyond
 *          input storage (not counting the storage required for
 *          input arguments).
 *
 * Elements of input arrays can be modified.
 */

int solution(vector<int> &A) {
    // write your code in C++98
    int N = A.size();
    
    double cur_min_avg = (A[0] + A[1]) / 2.0;
    double cur_slice2, cur_slice3;
    int cur_index = 0;

    for(int i = 0; i < N - 2; i++) {
        // slice of the length 2
        cur_slice2 = (A[i] + A[i+1]) / 2.0;
        if ( cur_slice2  < cur_min_avg) {
            cur_min_avg = cur_slice2;
            cur_index = i;
        }
        // slice of the length 3
        cur_slice3 = (A[i] + A[i+1] + A[i+2]) / 3.0;
        if ( cur_slice3 < cur_min_avg) {
            cur_min_avg = cur_slice3;
            cur_index = i;
        }
    }

    // last slice of length 2
    if ( (A[N-1] + A[N-2]) / 2.0  < cur_min_avg) {
        cur_min_avg = (A[N-1] + A[N-2]) / 2.0;
        cur_index = N-2;
    }
    
    return cur_index;
}


/* 
 * Source: https://codility.com/demo/take-sample-test/min_avg_two_slice
 * Result: 60/100 @ https://codility.com/demo/results/demoPFQ296-VKJ/
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

double slice_avg(vector<int>& ps, int p, int q) {
    return ((double) ps[q+1] - ps[p]) / ((double) q + 1 - p);
}

int solution(vector<int> &A) {
    // write your code in C++98
    int N = A.size();
    int sum = 0;
    
    //step 1: prefix sums aux array
    vector<int> psums;
    
    for(int i = 0; i < N+1; i++) {
        psums.push_back(sum);
        sum += A[i];
    }
    
    //step 2: double-looping through slices
    double cur_min = slice_avg(psums,0,1);
    int cur_p   = 0;
    double slice;
    
    for (int p = 0; p < N; p++) {
        for (int q = p+1; q < N; q++) {
            slice = slice_avg(psums,p,q);
            if (slice < cur_min) {
                cur_min = slice;
                cur_p   = p;
            }
        }
    }
    
    return cur_p;
}

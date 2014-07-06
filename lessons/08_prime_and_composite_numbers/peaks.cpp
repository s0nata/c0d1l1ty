/*
 * Source: http://codility.com/demo/take-sample-test/peaks/
 * Result:  36/100 @ https://codility.com/demo/results/demoQ8W6PM-VFP/
 * Result:   9/100 @ https://codility.com/demo/results/demoA7NMY2-HX9/
 * Result:  63/100 @ https://codility.com/demo/results/demoRJG4MS-G3T/
 * Result   90/100 @ https://codility.com/demo/results/demo9RKGFE-8TH/
 *
 * A non-empty zero-indexed array A consisting of N integers is given.
 *
 * A peak is an array element which is larger than its neighbors. More
 * precisely, it is an index P such that 0 < P < N − 1, A[P − 1] < A[P]
 * and A[P] > A[P + 1].
 *
 * For example, the following array A:
 *
 *   A[0] = 1
 *   A[1] = 2
 *   A[2] = 3
 *   A[3] = 4
 *   A[4] = 3
 *   A[5] = 4
 *   A[6] = 1
 *   A[7] = 2
 *   A[8] = 3
 *   A[9] = 4
 *   A[10] = 6
 *   A[11] = 2
 *
 * has exactly three peaks: 3, 5, 10.
 *
 * We want to divide this array into blocks containing the same number
 * of elements. More precisely, we want to choose a number K that will
 * yield the following blocks:
 *
 *       A[0], A[1], ..., A[K − 1],
 *       A[K], A[K + 1], ..., A[2K − 1],
 *       ...
 *       A[N − K], A[N − K + 1], ..., A[N − 1].
 *
 * What's more, every block should contain at least one peak. Notice
 * that extreme elements of the blocks (for example A[K − 1] or A[K])
 * can also be peaks, but only if they have both neighbors (including
 * one in an adjacent blocks).
 *
 * The goal is to find the maximum number of blocks into which the array
 * A can be divided.
 *
 * Array A can be divided into blocks as follows:
 *
 * - one block (1, 2, 3, 4, 3, 4, 1, 2, 3, 4, 6, 2). This block
 *   contains three peaks.
 * - two blocks (1, 2, 3, 4, 3, 4) and (1, 2, 3, 4, 6, 2). Every block
 *   has a peak.
 * - three blocks (1, 2, 3, 4), (3, 4, 1, 2), (3, 4, 6, 2). Every block
 *   has a peak. Notice in particular that the first block (1, 2, 3, 4)
 *   has a peak at A[3], because A[2] < A[3] > A[4], even though A[4]
 *   is in the adjacent block.
 *
 * However, array A cannot be divided into four blocks, (1, 2, 3), 
 * (4, 3, 4), (1, 2, 3) and (4, 6, 2), because the (1, 2, 3) blocks do
 * not contain a peak. Notice in particular that the (4, 3, 4) block
 * contains two peaks: A[3] and A[5].
 *
 * The maximum number of blocks that array A can be divided into is
 * three.
 *
 * Write a function:
 *
 *   int solution(vector<int> &A); 
 *
 * that, given a non-empty zero-indexed array A consisting of N
 * integers, returns the maximum number of blocks into which A can be
 * divided.
 *
 * If A cannot be divided into some number of blocks, the function
 * should return 0.
 *
 * For example, given:
 *
 *   A[0] = 1
 *   A[1] = 2 
 *   A[2] = 3 
 *   A[3] = 4 
 *   A[4] = 3 
 *   A[5] = 4 
 *   A[6] = 1 
 *   A[7] = 2 
 *   A[8] = 3 
 *   A[9] = 4 
 *   A[10] = 6 
 *   A[11] = 2
 *
 * the function should return 3, as explained above.
 *
 * Assume that:
 *
 *       N is an integer within the range [1..100,000];
 *       each element of array A is an integer within the range
 *         [0..1,000,000,000].
 *
 * Complexity:
 *
 *       expected worst-case time complexity is O(N*log(log(N)));
 *       expected worst-case space complexity is O(N), beyond input
 *         storage (not counting the storage required for input
 *         arguments).
 *
 * Elements of input arrays can be modified.
 */

// Translated from http://codesays.com/2014/solution-to-peaks-by-codility/
// improving previous solution
// https://codility.com/demo/results/demoYYB2JA-GP2/

#include <vector>
using namespace std;

int solution(vector<int> &A) {
    int N = A.size();
    
    // A is too small to have at least one peak
    if (N < 3) return 0;
    
    // prefix sum of a number of peaks in A
    // O(N)
    vector<int> peaks_sum(N,0);
    for(int i = 1; i < N-1;i++) {
        // update current value
        peaks_sum[i] = peaks_sum[i-1];
        // if peak
        if ((A[i-1] < A[i]) and (A[i] > A[i+1])) {
            peaks_sum[i]++;
        }
    }
    // last element
    peaks_sum[N-1] = peaks_sum[N-2];
    
    // what if there are no peaks?
    if (peaks_sum[N-1] == 0) return 0;
    
    // main loop: number of intervals is some factor of N
    //            thus we loop, looking for divisors and
    //            for each (pair) check peaks existence
    // O(sqrt(N))
    int divisor = 1; // not to omit border case of 1 interval
                     // which is possible if N is prime
    int blocks_size;
    int blocks_number; // for readability
    int blocks_number_max = 0;
    bool break_flag = false;
    
    while( divisor * divisor <= N) {
        if (N % divisor == 0) {
        //lesser factor, bigger blocks
            blocks_number = divisor;
            blocks_size   = N / divisor;

            // checking whether each block has a peak
            // by looking at the difference between number
            // of peaks on the interval borders
                
            // if exists a peak in the first block
            if (peaks_sum[0] != peaks_sum[blocks_size-1]) {
                // for the rest of the blocks
                for(int i = blocks_size - 1; i < N - blocks_size; i += blocks_size) {
                    if (peaks_sum[i] == peaks_sum[blocks_size+i]) {
                        break_flag = true;
                        break; // no peak on some interval
                    }
                }
                if (!break_flag) blocks_number_max = blocks_number;
                else break_flag = false; //reset
            }
        
            if (divisor * divisor == N) continue;
        
        //greater factor, smaller blocks
            blocks_size    = divisor;
            blocks_number = N / divisor;
            // checking whether each block has a peak
            // by looking at the difference between number
            // of peaks on the interval borders

            // if exists a peak in the first block
            if (peaks_sum[0] != peaks_sum[blocks_size-1]) {
                // for the rest of the blocks
                for(int i = blocks_size - 1; i < N - blocks_size; i += blocks_size) {
                    if (peaks_sum[i] == peaks_sum[blocks_size+i]) {
                        break_flag = true;
                        break; // no peak on some interval
                    }
                }
                if (!break_flag) return  blocks_number;
                else break_flag = false; //reset
            }
        }
        divisor++;
    }
    
    return blocks_number_max;
}

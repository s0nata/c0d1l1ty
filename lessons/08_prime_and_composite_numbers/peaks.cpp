/*
 * Source: http://codility.com/demo/take-sample-test/peaks/
 * Result:  36/100 @ https://codility.com/demo/results/demoQ8W6PM-VFP/
 * Result:   9/100 @ https://codility.com/demo/results/demoA7NMY2-HX9/
 * Result:  63/100 @ https://codility.com/demo/results/demoRJG4MS-G3T/
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

// currently there are problems with chaotic/large sequences
// smth wrong with conditions (too many)?

#include <deque>

int solution(vector<int> &A) {
    int N = A.size();
    
    if (N < 3) return 0;
    
    deque<int> divisors;
    deque<int>::iterator mid = divisors.begin();
    
    int j = 2;
    while (j * j < N) {
        if (N % j == 0) {
            if (divisors.empty()) {
                divisors.push_front(j);
                divisors.push_back(N/j);
            }
            else {
                divisors.insert(mid,j);
                ++mid;
                divisors.insert(mid,N/j);
                ++mid;
            }
        }
        j++;
    }
    
    if (j * j == N) {
        divisors.insert(mid,j);
    }
    
    //counting peaks
    int peaks_cnt = 0;
    for(int i = 1; i < N-1; i++) {
        if ( (A[i-1] < A[i]) && (A[i] > A[i+1]) ) {
            peaks_cnt++;
        }
    }
    
    if (peaks_cnt == 0 ) return 0;
    if (divisors.empty()) return 1;
    
    int D = divisors.size();
    int cur_len;
    bool has_peak_this = false;
    bool has_peak_each = true;
    
    for (int i = D-1; i >= 0 ; i--) {
        //can't be more intervals than peaks
        if (divisors[i] <= peaks_cnt) {
            cur_len = N / divisors[i];
            //loop througn A for each interval
            for (int q = 0; q <= N - cur_len; q+=cur_len) {
                //loop through elements of an interval
                //CAREFUL: peaks can be on borders
                for(int p = q; p < q + cur_len ; p++) {
                    //excluding 2 borders
                    if ((p > 0) && (p < N-1) ) {
                        //at least one peak in the interval
                        if ( (A[p-1] < A[p]) && (A[p] > A[p+1]) ) {
                            has_peak_this = true;
                            break;  // we leave the interval with positive info
                        }
                    }
                }
                //we have just left the interval
                has_peak_each &= has_peak_this;
                has_peak_this = false;
                if (!has_peak_each) break;
            }
            // at this point we passed all intervals for current divisor
            if (has_peak_each) return divisors[i];
        }
    }
    
    return 1;
}


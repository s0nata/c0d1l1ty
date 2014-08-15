/*
 * Source: http://codility.com/demo/take-sample-test/peaks/
 * Result   90/100
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

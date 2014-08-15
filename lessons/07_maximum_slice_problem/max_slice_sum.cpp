/*
 * Source: https://codility.com/demo/take-sample-test/max_slice_sum
 * Result: 100/100
 */

#include <algorithm> //max();

int solution(const vector<int> &A) {
    
    int N = A.size();

    int max_cur = A[0];
    int max_tot = A[0];
    
    for(int i = 1; i < N; i++) {
        max_cur = max(0, max_cur + A[i]);
        max_tot = max(max_cur, max_tot);
    }
    
    return max_tot;
}

/*
 * Source: https://codility.com/demo/take-sample-test/max_double_slice_sum
 * Result: 100/100
 */

#include <algorithm>
#include <vector>

int solution(vector<int> &A) {
    //code in C++98
    int N = A.size();
    
    //pass1: left sums, going ->
    int cur_sum = 0;
    vector<int> left_sum(N,0);
    
    for(int i = 1; i < N-1; i++) {
        cur_sum = max(0, cur_sum + A[i]);
        left_sum[i] = cur_sum;
    }
    
    //pass2: right sums, going <-
    cur_sum = 0;
    vector<int> right_sum(N,0);
    
    for(int i = N-2; i > 0; i--) {
        cur_sum = max(0, cur_sum + A[i]);
        right_sum[i] = cur_sum;
    }
    
    //pass3: going througn all pairs of left and right sums
    int max_double_slice = 0;
    
    for(int i = 0; i < N-2; i++) {
        max_double_slice = max(max_double_slice,left_sum[i]+right_sum[i+2]);
    }
    
    return max_double_slice;
}


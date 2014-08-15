/*
 * Source: https://codility.com/demo/take-sample-test/tape_equilibrium
 * Result: 100/100 @ https://codility.com/demo/results/demoDDB576-XEE/
 */

#include <cstdlib>
int solution(vector<int> &A) {
    int N = A.size();
    
    int sum_l = A[0];
    int sum_r = 0;
    for(int i = 1; i < N; i++) {
        sum_r += A[i];
    }
    
    //P == 1
    int min_diff = abs(sum_l - sum_r);
    //P >=2
    for (int i = 1; i < N-1;i++) {  //A[N-1] should always stay in sum_r
        sum_l += A[i];
        sum_r -= A[i];
        if (abs(sum_l - sum_r) < min_diff) {
            min_diff = abs(sum_l - sum_r);
        }
    }
    return min_diff;
}
               

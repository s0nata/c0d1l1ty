/*
 * Source: http://codility.com/demo/take-sample-test/max_profit
 * Result: 100/100
 */

#include <algorithm> // min(), max();

int solution(const vector<int> &A) {
    int N = A.size();
    
    if (N < 2) return 0;
    
    int cur_p = A[0],
        cur_profit = 0,
        max_profit = 0;
        
    for(int i = 1; i < N; i++) {
        cur_p      = min(cur_p, A[i]);
        cur_profit = max(0, A[i] - cur_p);
        max_profit = max(max_profit, cur_profit);
    }
    
    return max_profit;
}

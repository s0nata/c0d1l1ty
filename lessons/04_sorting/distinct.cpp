/*
 * Source: https://codility.com/demo/take-sample-test/distinct
 * Result: 100/100
 */

#include <algorithm>
int solution(const vector<int> &A) {
    // write your code in C++98
    int N = A.size();
    
    if (N == 0) {
        return 0;
    }
    
    vector<int> B (A);
    sort(B.begin(),B.end());
    
    int diff = 1;
    for(int i = 1; i < N; i++) {
        if (B[i] != B[i-1]) {
            diff++;
        }
    }
    
    return diff++;
}

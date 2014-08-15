/*
 * Source: https://codility.com/demo/take-sample-test/triangle
 * Result: 100/100
 */

#include <algorithm>

int solution(const vector<int> &A) {
    int N = A.size();
    vector<int> B(A);
    sort(B.begin(),B.end());
    
    if (N < 3) return 0;
    
    for(int i = 0; i < N-2; i++) {
        // B[i]   <= B[i+1] <= B[i+2] implies that
        // B[i]   < B[i+1] + B[i+2] and
        // B[i+1] < B[i+2] + B[i] which leaves to check
        // B[i+2] - B[i] < B[i+1] (overflow possible)
        if (B[i+1] > B[i+2] - B[i]) return 1;
    }
    
    return 0;
}


/*
 * Source: https://codility.com/demo/take-sample-test/count_triangles
 * Result: 100/100
 */

#include <algorithm> // sort();

int solution(vector<int> &A) {
    int N = A.size();
    
    if (N < 3) return 0;

    sort(A.begin(),A.end());

    int cnt = 0, 
        r;
    
    for(int p = 0; p < N; p++) {
        r = 0;
        for(int q = p+1; q < N; q++) {
            while( (r < N) && (A[p] + A[q] > A[r]) ) r++;
            cnt += r - q - 1;
        }
    }
    
    return cnt;
}
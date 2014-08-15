/*
 * Source: https://codility.com/demo/take-sample-test/frog_river_one
 * Result: 100/100
 */
 
#include <vector>

int solution(int X, vector<int> &A) {
    // write your code in C++98
    int N = A.size(), len = 0, t = 0;
    
    vector<bool> pos(X,false);
    
    for(int i = 0; i < N; i++) {
        if (pos[A[i]-1] == false) {
            len++;
            t = i;
            pos[A[i]-1] = true;
        }
    }
    
    if (len == X) return t;
    
    return -1;
}

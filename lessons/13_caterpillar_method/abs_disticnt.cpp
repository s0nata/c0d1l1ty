/*
 * source: https://codility.com/demo/take-sample-test/abs_distinct
 * result:  92/100
 */

#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11
    int N = A.size();
    
    if (N == 1) return 1;
    
    int cnt = 0,
        head = N-1,
        tail = 0;
        
    while (head > tail) {

        while ((A[head] == A[head-1]) && (head > tail + 1)) head--;
        while ((A[tail] == A[tail+1]) && (head > tail + 1)) tail++;

        if (abs(A[head]) == abs(A[tail])) {
            head--;
            tail++;
            cnt++;
        }
        else if (abs(A[head]) > abs(A[tail])) {
            head--;
            cnt++;
        }
        else {
            tail++;
            cnt++;
        }
        
    }
    
    if (head == tail) cnt++;
    
    return cnt;
}

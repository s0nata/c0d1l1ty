/*
 * Source: https://codility.com/demo/take-sample-test/max_counters
 * Result: 100/100
 */

#include <algorithm>  //max();
#include <vector>

vector<int> solution(int N, vector<int> &A) {
    int M = A.size();           //number of operations
    vector<int> counter(N,0);   //number of counters
    int old_max_counter = 0,
        cur_max_counter = 0;
    
    for(int i = 0; i < M; i++) {
        if (A[i] < N+1) {
            if(counter[A[i]-1] < old_max_counter){
                counter[A[i]-1] = old_max_counter;
            }
            counter[A[i]-1]++;
            cur_max_counter = max(cur_max_counter,counter[A[i]-1]);
        }
        else {
            old_max_counter = cur_max_counter;
        }
    }
    
    for(int i = 0; i < N; i++) {
        if (counter[i] < old_max_counter)
            counter[i] = old_max_counter;
    }
    
    return counter;
}


/*
 * Source: https://codility.com/demo/take-sample-test/dominator
 * Result: 100/100
 */

#include <stack>
#include <cmath>

int solution(const vector<int> &A) {

    int N = A.size();
    
    //corner cases for the small inputs
    
    if (N == 0) return -1;
    
    if (N == 1) return 0;
    
    if (N == 2) {
        if (A[0] == A[1]) return 0;
        else              return -1;
    }
    
    // general candidate search
    
    stack<int> candidates;
    
    for(int i = 0; i < N; i++) {
        if (candidates.empty()) {
            candidates.push(A[i]);
        }
        else {
            if (candidates.top() != A[i]) {
                candidates.pop();
            }
            else {
                candidates.push(A[i]);
            }
        }
    }
    
    // checking whether the candidate is a dominator
    
    if (candidates.empty()) {
        return -1;
    }
    else {
        int cand_count = 0;
        int cand_val   = candidates.top();
        
        for (int i = 0; i < N; i++) {
            if (A[i] == cand_val) cand_count++;
        }
        
        if (cand_count > (int) floor(N/2.0)) {
            int index = 0;
            
            while (A[index] != cand_val) {
                index++;
            }
            
            return index;
        }
    }
    
    return -1;
}

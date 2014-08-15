/*
 * Source: https://codility.com/demo/take-sample-test/perm_check
 * Result: 100/100
 */

#include <vector>
int solution(vector<int> &A) {
    // write your code in C++98
    long n = A.size();
    
    vector<bool> meet(n,false);
    
    for(long i = 0; i < n; i++) {
        //if A[i] > n+1, A is definitely not a permutation
        if (A[i]-1 > n)
            return 0;
        else { 
            //duplicated element occurred
            if (meet[A[i]-1] == true)
                return 0;
            else
            meet[A[i]-1] = true;
        }
    }
    
    //loop for checking
    for(long i = 0; i < n; i++) {
        if (meet[i] == false)
            return 0;
    }
    
    return 1;
}

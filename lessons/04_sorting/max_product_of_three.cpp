/*
 * Source: https://codility.com/demo/take-sample-test/max_product_of_three
 * Result: 100/100
 */

#include <algorithm>
int solution(vector<int> &A) {
    //C++98
    sort(A.begin(),A.end());
    
    int N = A.size();
    
    return max(A[N-3]*A[N-2]*A[N-1],A[0]*A[1]*A[N-1]);
}

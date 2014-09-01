// debugging previously solved
//https://codility.com/demo/results/demo4KPNTX-5RY/
//https://codility.com/demo/results/demoDXREBP-ZS2/
// current version
https://codility.com/demo/results/demoJDGZ6S-BAU/

#include <cstdlib>

int solution(vector<int> &A) {
    int N = A.size();
    
    if (N == 1) return 1;
    
    int left  = 0, 
        right = N-1,
        diff_cnt = 0;
    
    while (left <= right) {
        diff_cnt++;
        if (abs(A[left]) != abs(A[right])) {
            diff_cnt++;    
        }
        left++;
        right--;

        //move left
        while (left < N-1) {
            if (abs(A[left]) == abs(A[left-1])) left++;
            else break;
        }

        //move right
        while (right > 0) {
            if (abs(A[right]) == abs(A[right+1])) right--;
            else break;
        }
    }
    
    return diff_cnt;
}
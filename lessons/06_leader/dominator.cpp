/*
 * Source: https://codility.com/demo/take-sample-test/dominator
 * Result: 100/100 @ https://codility.com/demo/results/demoC55AWQ-M7Z/
 *
 * A zero-indexed array A consisting of N integers is given. The
 * dominator of array A is the value that occurs in more than half of
 * the elements of A.
 *
 * For example, consider array A such that
 *
 *   A[0] = 3    A[1] = 4    A[2] =  3
 *   A[3] = 2    A[4] = 3    A[5] = -1
 *   A[6] = 3    A[7] = 3
 *
 * The dominator of A is 3 because it occurs in 5 out of 8 elements of A
 * (namely in those with indices 0, 2, 4, 6 and 7) and 5 is more than a
 * half of 8.
 *
 * Write a function
 *
 *   int solution(const vector<int> &A);
 *
 * that, given a zero-indexed array A consisting of N integers, returns
 * index of any element of array A in which the dominator of A
 * occurs. The function should return −1 if array A does not have a
 * dominator.
 *
 *Assume that:
 *
 *       N is an integer within the range [0..100,000];
 *       each element of array A is an integer within the range
 *         [−2,147,483,648..2,147,483,647].
 *
 * For example, given array A such that
 *
 *   A[0] = 3    A[1] = 4    A[2] =  3
 *   A[3] = 2    A[4] = 3    A[5] = -1
 *   A[6] = 3    A[7] = 3
 *
 * the function may return 0, 2, 4, 6 or 7, as explained above.
 *
 *Complexity:
 *
 *        expected worst-case time complexity is O(N);
 *        expected worst-case space complexity is O(1), beyond input
 *          storage (not counting the storage required for input
 *          arguments).
 *
 *Elements of input arrays can be modified.
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

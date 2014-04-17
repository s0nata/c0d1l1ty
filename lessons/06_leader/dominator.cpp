/*
 * Source: https://codility.com/demo/take-sample-test/dominator
 * Result: 75/100 @ https://codility.com/demo/results/demoHDP7K9-HHE/
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

//surprisingly, 1-element array is valid input
//also need to take care of integer division

// you can also use includes, for example:
#include <stack>
int solution(const vector<int> &A) {
    // write your code in C++98
    int N = A.size();
    
    if (N < 2) {
        return -1;
    }
    
    //finding the candidate
    stack<int> candidates;
    
    for(int i = 0; i < N; i++) {
        //empty stack
        if (candidates.empty()) {
            candidates.push(A[i]);
        }
        //non-empty stack
        else {
            if (candidates.top() != A[i]) {
                candidates.pop();
            }
        }
    }
    
    //fifty-fifty
    if (candidates.empty()) {
        return -1;
    }
    else {
        //checking whether candidate occurs more than in N/2 positions
        int cand_counter = 0;
        int candidate = candidates.top();
        
        for(int i = 0; i < N; i++) {
            if (A[i] == candidate) {
                cand_counter++;
            }
        }
        
        //careful with division
        if (cand_counter > N/2) {
            //find the first position
            int cand_position = 0;
            
            while (A[cand_position] != candidate) {
                cand_position++;
            }
            
            return cand_position;
        }
    }
    
    return -1;
}

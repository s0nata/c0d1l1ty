/*
 *Source: https://codility.com/demo/take-sample-test/equi_leader
 * Result: 100/100 @ https://codility.com/demo/results/demo9Q8ZZ9-4JE/
 *
 *
 *
 * A non-empty zero-indexed array A consisting of N integers is given.
 *
 * The leader of this array is the value that occurs in more than half
 * of the elements of A.
 *
 * An equi_leader is an index S such that 0 ≤ S < N − 1 and two
 * sequences A[0], A[1], ..., A[S] and A[S + 1], A[S + 2], ..., A[N − 1]
 * have leaders of the same value.
 *
 *For example, given array A such that:
 *
 *   A[0] = 4
 *   A[1] = 3
 *   A[2] = 4
 *   A[3] = 4
 *   A[4] = 4
 *   A[5] = 2
 *
 * we can find two equi_leaders:
 *
 *       0, because sequences: (4) and (3, 4, 4, 4, 2) have the same
 *         leader, whose value is 4.
 *       2, because sequences: (4, 3, 4) and (4, 4, 2) have the same
 *         leader, whose value is 4.
 *
 * The goal is to count the number of equi_leaders. Write a function:
 *
 *   int solution(vector<int> &A);
 *
 * that, given a non-empty zero-indexed array A consisting of N
 * integers, returns the number of equi_leaders.
 *
 * For example, given:
 *
 *   A[0] = 4
 *   A[1] = 3
 *   A[2] = 4
 *   A[3] = 4
 *   A[4] = 4
 *   A[5] = 2
 *
 * the function should return 2, as explained above.
 *
 * Assume that:
 *
 *       N is an integer within the range [1..100,000];
 *       each element of array A is an integer within the range
 *         [−1,000,000,000..1,000,000,000].
 *
 * Complexity:
 *
 *       expected worst-case time complexity is O(N);
 *       expected worst-case space complexity is O(N), beyond input
 *         storage (not counting the storage required for input
 *         arguments).
 *
 * Elements of input arrays can be modified.
 */

#include <stack>
#include <cmath>

int solution(vector<int> &A) {
    // STEP 1 : FIND THE LEADER
    // or return 0 if there is no such element
    
    int N = A. size(); // N >= 2
    
    //corner cases
    if (N == 1) {
        return 0;
    }
    else if (N == 2) {
        if (A[0] == A[1]) return 1;
        else return 0;
    }
    else {
    // finding the leader candidate
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
        
        if (candidates.empty()) {
            return 0;
        }
        else {
        //check that leader IS a leader
            
            int leader   = candidates.top();
            int lead_cnt = 0;
            
            for (int i = 0; i < N; i++) {
                if (A[i] == leader)
                    lead_cnt++;
            }
            
            if (lead_cnt > (int) floor(N/2)) {
            //we really have a leader
                vector<int> leads(N,0);
                vector<int> nonleads(N,0);
                
                // count how many leading and non-leading elements
                // are at each A index
                if (A[0] == leader) leads[0] = 1;
                else             nonleads[0] = 1;
                
                for(int i = 1; i < N; i++) {
                    if (A[i] == leader) {
                        leads[i] = leads[i-1] + 1;
                        nonleads[i] = nonleads[i-1];
                    }
                    else {
                        leads[i] = leads[i-1];
                        nonleads[i] = nonleads[i-1] + 1;
                    }
                }
                
                int equi_leaders = 0;
                int front_leads, front_nonleads;
                    //back_leads, back_nonleads;
                for(int i = 0; i < N-1; i++) {
                    front_leads = leads[i];
                    front_nonleads = nonleads[i];
                    
                    if (front_leads > front_nonleads) {
                        if ((leads[N-1] - front_leads) > (nonleads[N-1] - front_nonleads)) {
                            equi_leaders++;
                        }
                    }
                }
                
                return equi_leaders;
            }
            
        }
        
    }
    
    return 0;
}


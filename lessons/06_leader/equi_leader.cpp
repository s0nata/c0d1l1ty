/*
 *Source: https://codility.com/demo/take-sample-test/equi_leader
 * Result: 100/100
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


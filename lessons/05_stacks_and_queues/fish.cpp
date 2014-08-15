/*
 * Source: https://codility.com/demo/take-sample-test/fish
 * Result: 100/100
 */

// you can also use includes, for example:
#include <stack>
int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++98
    int N = A.size();
    
    stack<int> downstream_fish;
    int live_fish = 0;
    
    for (int i = 0; i < N; i++) {
        if ( B[i] == 0 ) {
            //current fish is flowing upstream
            if ( downstream_fish.empty() ) {
                //and there is no fish in front of it
                //that flows downstream
                live_fish++;
            }
            else {
                //there is at least one fish flowing downstream
                int curr_down_fish;
                bool fish_eats_fish = true;
                
                while ( fish_eats_fish ) {
                    //let's check who eats whom
                    curr_down_fish = downstream_fish.top();
                    
                    if (A[curr_down_fish] > A[i]) {
                        //upstream flowing fish was eaten
                        fish_eats_fish = false;
                    }
                    else {
                        // else the downstream floating one was eaten
                        //and fish still eats fish
                        downstream_fish.pop();
                    }

                    //check whether there are more fish flowing downstream
                    if (downstream_fish.empty()) {
                        fish_eats_fish = false;
                        //and because the upstream-floating fish ate all
                        //those floating downstream
                        live_fish++;
                    }
                }
            }
        }
        else {
            // B[i] == 1
            downstream_fish.push(i);
        }
    }
    return live_fish + downstream_fish.size();
}


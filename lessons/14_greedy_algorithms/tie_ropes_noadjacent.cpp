/* 
 * Source: https://codility.com/demo/take-sample-test/tie_ropes
 * What if we remove the adjacency of ropes condition?
 * Time: 45 minutes
 */

#include <algorithm> // sort();
#include <deque>

int solution(int K, vector<int> &A) {
    int N = A.size();
    
    if (N == 1) {
        if (A[0] >= K) { return 1; }
        else           { return 0; }
    }

    sort(A.begin(),A.end());
    
    int cnt = 0,
        i = N-1;
    while (A[i] >= K) {
        cnt++;
        i--;
    }

    deque<int> shorts,
               longs;
    for(int j = 0; j < i; j++) {
        if (A[j] + A[i] < K) {
            shorts.push_back(A[j]);    
        }
        else {
            longs.push_back(A[j]);    
        }
    }
    longs.push_back(A[i]);
    
    int delta, cur_max;
    while (!longs.empty()) {
        if (longs.size() > 1) {
            longs.pop_back();
            longs.pop_front();
            cnt++;
        }
        else if (longs.size() == 1) {
            delta = K - longs.back();
            longs.pop_back();
            while ((delta > 0)&&(!shorts.empty())) {
                delta -= shorts.back();
                shorts.pop_back();
            }
            if (delta < 0) { cnt++; }
            else           { return cnt;} // no more ropes left
        }
        
        // at this point longs may be empty
        if (longs.size() >= 2) {
            cur_max = longs.back();
            longs.pop_back();
            while (longs.size() > 0) {
                if (longs.front() < K - cur_max) { // not sufficient
                    delta = longs.front();
                    longs.pop_front();
                    shorts.push_back(delta);
                }
                else break;
            }
            longs.push_back(cur_max);
        }
    
    }
    //here longs is empty
    delta = K;
    while (!shorts.empty()) {
        if (delta < 0) {
            delta = K;
            cnt++;
        }
        else {
            delta -= shorts.back();
            shorts.pop_back();
        }
    }
    
    return cnt;
}

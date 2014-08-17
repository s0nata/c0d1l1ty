/*
 * Source: https://codility.com/demo/take-sample-test/count_non_divisible
 * Result:  66/100 (correctness 100, performance 25 -- O(N^2))
 */
 
 #include <algorithm> // max_element()

vector<int> solution(vector<int> &A) {
    int N = A.size();
    
    //count occurences of each element in A
    int A_max = *max_element(A.begin(),A.end());

    vector<int> Atimes(A_max+1,0);
    for(int i = 0; i < N; i++) Atimes[A[i]]++;
    
    //bf approach pass 1
    vector<int> non_divs(A_max+1, 0);
    for(int i = A_max; i > 0; i--) {
        if (Atimes[i]> 0) {
            for (int j = i-1; j > 0; j--) {
                if (i % j > 0) {
                    non_divs[i] += Atimes[j];
                }
            }
        }
    }

    //bf approach pass 2
    for (int i = 0; i < A_max +1 ; i++) {
        if (Atimes[i] > 0) {
            for (int j = i + 1; j < A_max+1; j++) {
                non_divs[i] += Atimes[j];
            }
        }
    }
    
    vector<int> res(N,0);
    for(int i = 0; i < N; i++) {
        res[i] = non_divs[A[i]];
    }

    return res;
}

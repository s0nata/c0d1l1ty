/* 
 * Source: https://codility.com/demo/take-sample-test/min_avg_two_slice
 * Result: 100/100
 * Based on: http://codesays.com/2014/solution-to-min-avg-two-slice-by-codility/
 */

int solution(vector<int> &A) {
    // write your code in C++98
    int N = A.size();
    
    double cur_min_avg = (A[0] + A[1]) / 2.0;
    double cur_slice2, cur_slice3;
    int cur_index = 0;

    for(int i = 0; i < N - 2; i++) {
        // slice of the length 2
        cur_slice2 = (A[i] + A[i+1]) / 2.0;
        if ( cur_slice2  < cur_min_avg) {
            cur_min_avg = cur_slice2;
            cur_index = i;
        }
        // slice of the length 3
        cur_slice3 = (A[i] + A[i+1] + A[i+2]) / 3.0;
        if ( cur_slice3 < cur_min_avg) {
            cur_min_avg = cur_slice3;
            cur_index = i;
        }
    }

    // last slice of length 2
    if ( (A[N-1] + A[N-2]) / 2.0  < cur_min_avg) {
        cur_min_avg = (A[N-1] + A[N-2]) / 2.0;
        cur_index = N-2;
    }
    
    return cur_index;
}


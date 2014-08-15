/* 
 * Source: https://codility.com/demo/take-sample-test/min_avg_two_slice
 * Result: 60/100 @ demoPFQ296-VKJ
 */

double slice_avg(vector<int>& ps, int p, int q) {
    return ((double) ps[q+1] - ps[p]) / ((double) q + 1 - p);
}

int solution(vector<int> &A) {
    // write your code in C++98
    int N = A.size();
    int sum = 0;
    
    //step 1: prefix sums aux array
    vector<int> psums;
    
    for(int i = 0; i < N+1; i++) {
        psums.push_back(sum);
        sum += A[i];
    }
    
    //step 2: double-looping through slices
    double cur_min = slice_avg(psums,0,1);
    int cur_p   = 0;
    double slice;
    
    for (int p = 0; p < N; p++) {
        for (int q = p+1; q < N; q++) {
            slice = slice_avg(psums,p,q);
            if (slice < cur_min) {
                cur_min = slice;
                cur_p   = p;
            }
        }
    }
    
    return cur_p;
}

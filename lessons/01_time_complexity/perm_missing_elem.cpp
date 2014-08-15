/*
 * Source: https://codility.com/demo/take-sample-test/perm_missing_elem
 * Result: 100/100
 */

int solution(vector<int> &A) {
    int N = A.size();
    
    bool oddN = (N % 2 == 0) ? false : true;
    long sum  = (oddN) ? ((N+1)/2)*(N+2) : ((N+2)/2)*(N+1) ;
    
    for (int i = 0; i < N; i++)
        sum -= A[i];
    
    return sum;    
}


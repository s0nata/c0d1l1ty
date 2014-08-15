/*
 * Source: http://codility.com/demo/take-sample-test/str_symmetry_point/
 * Result: 100/100
 */

int solution(const string &S) {
    int N = S.length();
    
    if (N % 2 == 0) return -1;
    if (N == 1) return 0;
    if (N == 0) return -1;
    
    int mid_index = N / 2;
    bool eqflag = true;
        
    for(int i = 1; i <= mid_index; i++) {
        if (S[mid_index+i] != S[mid_index-i]) {
            eqflag = false;
            break;
        }
    }
        
    if (eqflag) return mid_index;

    return -1;
}

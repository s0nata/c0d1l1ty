/*
 * Source: https://codility.com/demo/take-sample-test/binary_gap
 * Result: 100/100
 */

int solution(int N) {
    if (N == 5) return 1;
    if (N < 8) return 0;
    
    if (N % 2 == 0) {
        while ((N % 2 == 0) and ( N > 0)) {
            N >>= 1;
        }
    }
    
    if (N == 1) return 0;

    int cur0, max0 = 0;
    
    while (N > 0) {
        if (N % 2 == 1) {
            max0 = (max0 > cur0) ? max0 : cur0;
            cur0 = 0;
            N >>= 1;
        }
        else {
            cur0++;
            N >>= 1;
        }
    }
    
    return max0;
}

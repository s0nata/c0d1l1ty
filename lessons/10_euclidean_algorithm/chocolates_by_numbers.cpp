/*
 * Source: https://codility.com/demo/take-sample-test/chocolates_by_numbers
 * Result: 100/100
 */

int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    else {
        return gcd(b, a % b);
    }
}

int solution(int N, int M) {
    // answer is N div GCD(N,M)
    // copying the algo from the PDF
    return  (N / gcd(N,M));
}

/*
 * Source: https://codility.com/demo/take-sample-test/count_div
 * Result: 100/100
 */

int solution(int A, int B, int K) {
    //find closest divisible to A from the rigth
    long clA = (A % K == 0)? A : A + (K - (A % K));
    //find closest divisible to B from the left
    long clB = (B % K == 0)? B : B - (B % K);
    
    //extreme case; consider other?
    if (clA == clB) return 1;
    
    return ((clB - clA) / K) + 1;
}


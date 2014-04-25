/*
 * Source: https://codility.com/demo/take-sample-test/count_div
 * Result: 100/100 @ https://codility.com/demo/results/demoG25BHZ-55Y/
 *
 * Write a function:
 *
 *   int solution(int A, int B, int K); 
 *
 * that, given three integers A, B and K, returns the number of
 * integers within the range [A..B] that are divisible by K, i.e.:
 *
 *   { i : A ≤ i ≤ B, i mod K = 0 }
 *
 * For example, for A = 6, B = 11 and K = 2, your function should
 * return 3, because there are three numbers divisible by 2 within the
 * range [6..11], namely 6, 8 and 10.
 *
 * Assume that:
 *
 *       A and B are integers within the range [0..2,000,000,000];
 *       K is an integer within the range [1..2,000,000,000];
 *       A ≤ B.
 *
 * Complexity:
 *
 *       expected worst-case time complexity is O(1);
 *       expected worst-case space complexity is O(1).
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


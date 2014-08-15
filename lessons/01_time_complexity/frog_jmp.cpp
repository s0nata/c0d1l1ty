/*
 * Source: https://codility.com/demo/take-sample-test/frog_jmp
 * Result: 100/100
 */

 #include <cmath>

int solution(int X, int Y, int D) {
    return (int) ceil(((long double)(Y - X))/D);
}


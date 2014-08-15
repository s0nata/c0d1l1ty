/*
 * Source: https://codility.com/demo/take-sample-test/count_factors
 * Result:  92/100
 */

#include <cmath>    //sqrt(), ceil()

int solution(int N) {
    if (N == 1) return 1;
    
    int counter = 0,
        factor = 2,
        lim = (int) ceil(sqrt(N));
        
    while (factor < lim) {
        if (N % factor == 0) {
            counter += 2;
        }
        factor++;
    }
    
    if (N == factor * factor) {
        counter++;
    }
    
    return counter + 2;
}


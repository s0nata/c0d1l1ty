/*
 * Source: https://codility.com/demo/take-sample-test/min_perimeter_rectangle
 * Result: 100/100
 */

#include <algorithm>
int solution(int N) {

    int cur_perim = 2 * (1 + N), 
        min_perim = 2 * (1 + N);
    int i = 2;
    
    while (i*i < N) {
        if ( N % i == 0) {
            cur_perim = 2 * ( i + (N / i));
        }
        
        min_perim = min(min_perim,cur_perim);
        i++;
    }
    
    //case when i*i == N
    if (i*i == N) {
        min_perim = min(min_perim, 4*i);
    }
    
    return min_perim;
}


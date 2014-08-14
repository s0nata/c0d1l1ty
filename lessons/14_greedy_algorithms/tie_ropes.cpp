/* 
 * Source: https://codility.com/demo/take-sample-test/tie_ropes
 * Result: 100/100
 * Time:   13 minutes
 */

int solution(int K, vector<int> &A) {
    int N = A.size(),
        cur_len = 0,
        cnt = 0;
    
    for (int i = 0; i < N; i++) {
        if (A[i] >= K) {
            cur_len = 0;
            cnt++;
        }
        else {
            cur_len += A[i];
            if (cur_len >= K) {
                cur_len = 0;
                cnt++;
            }
        }
    }
    
    return cnt;
}

/*
 * Detected time complexity:   O(N)
 * |--------------------------+---------+--------|
 * | test                     | time    | result |
 * |--------------------------+---------+--------|
 * | Example tests            |         |        |
 * |--------------------------+---------+--------|
 * | example                  |         |        |
 * | example test             | 0.008 s | OK     |
 * |--------------------------+---------+--------|
 * | Correctness tests        |         |        |
 * |--------------------------+---------+--------|
 * | single                   |         |        |
 * | single element           | 0.008 s | OK     |
 * |--------------------------+---------+--------|
 * | double                   |         |        |
 * | two elements             | 0.008 s | OK     |
 * |--------------------------+---------+--------|
 * | small_functional         |         |        |
 * | small functional tests   | 0.008 s | OK     |
 * |--------------------------+---------+--------|
 * | small_random             |         |        |
 * | small random sequences   |         |        |
 * | length = ~100            | 0.008 s | OK     |
 * |--------------------------+---------+--------|
 * | Performance tests        |         |        |
 * |--------------------------+---------+--------|
 * | medium_random            |         |        |
 * | chaotic medium sequences |         |        |
 * | length = ~5,000          | 0.008 s | OK     |
 * |--------------------------+---------+--------|
 * | large_range              |         |        |
 * | large range test,        |         |        |
 * | length = ~100,000        | 0.044 s | OK     |
 * |--------------------------+---------+--------|
 * | large_answer             |         |        |
 * | test with large answer,  |         |        |
 * | length = ~100,000        | 0.052 s | OK     |
 * |--------------------------+---------+--------|
 * | small_answer             |         |        |
 * | test with large answer,  |         |        |
 * | length = ~100,000        | 0.032 s | OK     |
 * |--------------------------+---------+--------|
 */

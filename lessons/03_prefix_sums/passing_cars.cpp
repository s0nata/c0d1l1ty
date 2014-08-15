/*
 * Source: https://codility.com/demo/take-sample-test/passing_cars
 * Result: 100/100
 */

int solution(vector<int> &A) {
    int cnt_zeroes = 0;
    int cnt_pairs  = 0;
    int N          = A.size();

    for(int i = 0; i < N; i++) {
        if (cnt_pairs > 1000000000) {
            return -1;
        }
        if (A[i] == 0) {
            cnt_zeroes++;
        }
        else {
            cnt_pairs += cnt_zeroes;
        }
    }

    return cnt_pairs;
}

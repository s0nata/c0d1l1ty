/*
 * Source: http://codility.com/demo/take-sample-test/str_symmetry_point/
 * Result: 100/100 @ https://codility.com/demo/results/demoEJX2HE-R47/
 *
 * Write a function:
 *
 *   int solution(const string &S); 
 *
 * that, given a string S, returns the index (counting from 0) of a
 * character such that the part of the string to the left of that
 * character is a reversal of the part of the string to its right. The
 * function should return −1 if no such index exists.
 *
 * Note: reversing an empty string (i.e. a string whose length is zero)
 * gives an empty string.
 *
 * For example, given a string:
 *
 * "racecar"
 *
 * the function should return 3, because the substring to the left of
 * the character "e" at index 3 is "rac", and the one to the right is
 * "car".
 *
 * Given a string:
 *
 * "x"
 *
 * the function should return 0, because both substrings are empty.
 *
 * Assume that:
 *
 *       the length of S is within the range [0..2,000,000].
 *
 * Complexity:
 *
 *       expected worst-case time complexity is O(length(S));
 *       expected worst-case space complexity is O(1) (not counting the
 *         storage required for input arguments).
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

/*
 * Source: https://codility.com/demo/take-sample-test/nesting
 * Result: 100/100 @ https://codility.com/demo/results/demoA7UF5B-WYS/
 *
 * A string S consisting of N characters is called properly nested if:
 *
 *       S is empty;
 *       S has the form "(U)" where U is a properly nested string;
 *       S has the form "VW" where V and W are properly nested strings.
 *
 * For example, string "(()(())())" is properly nested but string "())"
 * isn't.
 *
 * Write a function:
 *
 *   int solution(const string &S); 
 *
 * that, given a string S consisting of N characters, returns 1 if
 * string S is properly nested and 0 otherwise.
 *
 * For example, given S = "(()(())())", the function should return 1
 * and given S = "())", the function should return 0, as explained above.
 *
 * Assume that:
 *
 *       N is an integer within the range [0..1,000,000];
 *       string S consists only of the characters "(" and/or ")".
 *
 * Complexity:
 *
 *       expected worst-case time complexity is O(N);
 *       expected worst-case space complexity is O(1) (not counting the
 *         storage required for input arguments).
 */

#include <stack>
int solution(const string &S) {
    // write your code in C++98
    if (S == "") {
        return 1;
    }
    
    if (S[0] == ')') {
        return 0;
    }
    
    int N = S.length();
    
    if (N % 2 == 1) {
        return 0;
    }
    else {
        // stack to store brackets seen
        stack<char> brackets;
        
        //traversing the input string
        for(int i = 0; i < N; i++) {
            if (S[i] == '(') {
                brackets.push(S[i]);
            }
            else {
                if (!brackets.empty()){ //ugly and wrong
                    brackets.pop();
                }
                else {
                    return 0;
                }
            }
        }
        
        //non-empty stack signals that nesting is improper
        if (brackets.empty()){
            return 1;
        }
    }

    return 0;
}

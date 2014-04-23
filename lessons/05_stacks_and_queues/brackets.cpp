/*
 * Source: https://codility.com/demo/take-sample-test/brackets
 * Result: 100/100 @ https://codility.com/demo/results/demoE2G7WZ-DHH/
 *
 * A string S consisting of N characters is considered to be properly
 * nested if any of the following conditions is true:
 *
 *       S is empty;
 *       S has the form "(U)" or "[U]" or "{U}" where U is a properly
 *         nested string;
 *       S has the form "VW" where V and W are properly nested strings.
 *
 * For example, the string "{[()()]}" is properly nested but "([)()]"
 * is not.
 *
 * Write a function:
 *
 *   int solution(const string &S); 
 *
 * that, given a string S consisting of N characters, returns 1 if S
 * is properly nested and 0 otherwise.
 * 
 * For example, given S = "{[()()]}", the function should return 1 and
 * given S = "([)()]", the function should return 0, as explained
 * above.
 *
 * Assume that:
 *
 *       N is an integer within the range [0..200,000];
 *       string S consists only of the following characters: "(", "{",
 *         "[", "]", "}" and/or ")".
 *
 * Complexity:
 *
 *       expected worst-case time complexity is O(N);
 *       expected worst-case space complexity is O(N) (not counting the
 *         storage required for input arguments).
 */

#include <stack>
int solution(const string &S) {
    if (S.empty()) return 1;
 
    int N = S.length();
    if (N % 2 == 1) return 0;
    
    stack<char> brackets;
    
    for(int i = 0; i < N; i++) {
        if (brackets.empty()) brackets.push(S[i]);
        else {
            //cases when we pop
            if  ( S[i] == ')' ) {
                if (brackets.top() != '(')  return 0;
                else                        brackets.pop();
            }
            else if (S[i] == '}') {
                if (brackets.top() != '{')  return 0;
                else                        brackets.pop();                
            }
            else if (S[i] == ']') {
                if (brackets.top() != '[')  return 0;
                else                        brackets.pop();                
            }
            //otherwise we push
            else brackets.push(S[i]);
        }
    }
    
    if (brackets.empty()) return 1;
    
    return 0;
}


/*
 * Source: https://codility.com/demo/take-sample-test/brackets
 * Result: https://codility.com/demo/results/demoUZPF3X-FJ3/
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
using namespace std;

int solution(const string &S) {
    // write your code in C++98
    stack<char> brackets;
    int N = S.size();
    
    if (N == 0) return 1;
    
    int i = 0;
    brackets.push(S[i]);
    char cur_top, old_top;
    i++;
    
    do {
        old_top  = brackets.top();
        brackets.push(S[i]);
        cur_top = brackets.top();
        
        if (((old_top == '(') and (cur_top == ')')) or
            ((old_top == '{') and (cur_top == '}'))   or
            ((old_top == '[') and (cur_top == ']'))){
            brackets.pop();
            brackets.pop();
        }
        
        i++;
        
    } while (i < N);
    
    if (brackets.empty()) return 1;
    
    return 0;
}

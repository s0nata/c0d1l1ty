/*
 * Source: https://codility.com/demo/take-sample-test/brackets
 * Result: 100/100
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


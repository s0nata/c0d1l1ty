/*
 * Source: https://codility.com/demo/take-sample-test/nesting
 * Result: 100/100
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

/*
 * Task 1: given a list (represented by a structure IntList) and
 * a number M, return M-th element from the end or -1 otherwise.
 */

int solution(IntList * L, int M) {
    // write your code in C++98
    
    //step1: get the length of the list N
    int N = 0;
    IntList* cur_elem = L;
    
    while (cur_elem != NULL) {
        N++;
        cur_elem = cur_elem->next;
    } 
    
    //step2: do N-M steps to the element we need
    if (N - M < 0) 
        return -1;
    
    cur_elem = L;
    for(int i = 0; i < N - M; i++) {
        cur_elem = cur_elem->next;
    }
    
    return cur_elem->value;
}

/*
 * Task 2: implement a function that models the behaviour of a
 * specific stack-based arithmetic machine. Given an input string
 * of the specific format, return the result of its processing
 * or -1 if the input is incorrect.
 */

//#include <cctype>  //isdigit
//#include <cstdlib> //atoi

int solution(const string &S) {
    // write your code in C++98
    
    int N = S.size();
    if (N == 0) return -1; // check it
    
    vector<int> stack;

    const int MAX = 1<<12;
    
    for (int i = 0; i < N; i++) {
        //S[i]= [0..9] //(isdigit(atoi(S[i])))
        if ((S[i] <= '9') and (S[i] >= '0')) {
            stack.push_back(S[i] - '0');
        }
        else if (S[i] == '+') {
            if (stack.empty()) return -1;
            int a = stack.back();
            stack.pop_back();
            if (stack.empty()) return -1;
            int b = stack.back();
            stack.pop_back();
            int tmp = a+b;
            if (tmp < MAX) {
                stack.push_back(tmp);
            } 
            else {
                return -1;
            }
        }
        else if (S[i] == '*') {
            if (stack.empty()) return -1;
            int a = stack.back();
            stack.pop_back();
            if (stack.empty()) return -1;
            int b = stack.back();
            stack.pop_back();
            int tmp = a * b;
            if (tmp < MAX) {
                stack.push_back(a*b);
            }
            else {
                return -1;
            }
        }
    }
    
    if (stack.empty()) return -1;
    return stack.back();
}

/*
 * Task 3: yet another graph colouring problem, where given an
 * adjacency matrix the goal is to find the number of strongly
 * connected components.
 */
#include <queue>
#include <utility> //pair
using namespace std;

void bfs(const vector< vector<int> >& A,vector< vector<char> >& B, int x, int y, int n, int m) {
    queue< pair<int,int> > country;
    country.push(make_pair(x,y));
    
    while(!country.empty()){
        int i = country.front().first;
        int j = country.front().second;
        country.pop();
        B[i][j] = 1;
        
        //north
        if ((i-1 >= 0) and (B[i-1][j] != 1) and (A[i-1][j] == A[i][j]))
            country.push(make_pair(i-1,j));
        //east
        if ((j+1 < m) and (B[i][j+1] != 1) and (A[i][j+1] == A[i][j]))
            country.push(make_pair(i,j+1));            
        //south
        if ((i+1 < n) and (B[i+1][j] != 1) and (A[i+1][j] == A[i][j]))
            country.push(make_pair(i+1,j));            
        //west
        if ((j-1 >= 0) and (B[i][j-1] != 1) and (A[i][j-1] == A[i][j]))
            country.push(make_pair(i,j-1));        
    }
}

int solution(const vector< vector<int> > &A) {
    // write your code in C++98
    int N = A.size();
    int M = A[0].size();
    
    vector< vector<char> > AUX(N,vector<char>(M,0));
    
    int counter = 0;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if (AUX[i][j] !=1) {
                bfs(A,AUX,i,j,N,M);
                counter++;
            }
        }
    }
    return counter;
}

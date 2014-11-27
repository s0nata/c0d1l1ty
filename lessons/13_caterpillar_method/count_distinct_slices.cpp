// debugging previous attempt
#include <vector>
#include <iostream>
using namespace std;

#define MAGIC_LIM 1000000000

int solution(int M, vector<int> &A) {
    int N = A.size();
    
    if (N == 1) return 1;
    
    int head = 0, tail = 0,
        len, cnt = 0;
        
    vector<bool> visited(M+1,false);
    
    while (tail <= N-1) {
        // move head to the right until 
        // the first repeating element occurs    
        while ( (head < N) && (!visited[A[head]]) ) {
            visited[A[head]] = true;
            head++;
        }
        // now head points to the beginning
        // of the next interval
        
        // count distinct slices
        len = head - tail; // number of elements in slice
        cnt += ((len * (len + 1)) / 2); // distinct slices
        
        // magic number limit
        if (cnt >= MAGIC_LIM) return MAGIC_LIM;
        
        // clean visits information
        for (int i = tail; i < head; i++) visited[A[i]] = false;
        
        // i like to mov it mov it
        tail = head;
    }
    
    return cnt;
}
    
int main() {
    vector<int> test;
    int tmp;
    int M;
    
    cout << "enter M: ";
    cin >> M;
    cout << "enter the rest of the elements:\n";
    while (cin >> tmp) test.push_back(tmp);

//for (int i = 0; i < test.size(); i++) cout << test[i] << "  ";
//cout << endl;

    cout << "distinct slices number: ";
    cout << solution(M,test);
    cout << endl;

return 0;
}
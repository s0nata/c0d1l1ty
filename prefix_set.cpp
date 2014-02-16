/*
 * Source: http://codility.com/demo/take-sample-test/ps/
 *
 * A non-empty zero-indexed array A consisting of N integers is given. 
 * The first covering prefix of array A is the smallest integer P such that 
 * 0≤P. For example, the first covering prefix of the following 5−element 
 * array A:
 *
 * A[0] = 2  A[1] = 2  A[2] = 1
 * A[3] = 0  A[4] = 1
 *
 * is 3, because sequence [ A[0], A[1], A[2], A[3] ] equal to [2, 2, 1, 0],
 *  contains all values that occur in array A.
 *
 * Write a function int solution(const vector<int> &A) that, given a
 * zero-indexed non-empty array A consisting of N integers, returns the first
 * covering prefix of A. 
 *
 * Assume that:
 * - N is an integer within the range [1..1,000,000];
 * - each element of array A is an integer within the range [0..N−1].
 *
 * For example, given array A such that
 *
 * A[0] = 2  A[1] = 2  A[2] = 1  A[3] = 0  A[4] = 1
 *
 * the function should return 3, as explained above.
 *
 * Complexity:
 *
 * - expected worst-case time complexity is O(N);
 * - expected worst-case space complexity is O(N), 
 *   beyond input storage (not counting the storage
 *   required for input arguments).
 */

#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>
using namespace std;

// official solution, O(n)
int solution_off(const vector<int> &A) {
    long n = A.size();
    vector<bool> meet(n,false);   
    int result = n - 1;
    
    for(int i = 0; i < n;i++) {
        if (meet[A[i]] == false) {
            result = i;
            meet[A[i]] = true;
        }
    }
    return result;
}

//my first solution, O(n^2)
int solution(const vector<int> &A) {
    int n = A.size();
    
    if (n == 0) return 0;
    
    for (vector<int>::const_iterator it = A.end();
                                     it != A.begin();
                                     it--){
        
        if ((std::find(A.begin(),it,*it)) == it){
            int curval = *it;
            for(int i = 0; i < n; i++){
                if (A[i] == curval)
                   return i;
            }
        } 
    }
}

void test(const vector<int>& V){
    cout << "\nTest vector:\n";
    int len = V.size();
    for(int i = 0;i< len;i++)
        cout << V[i] << "  ";
    
    cout << "\nTest solution:\n";
    cout << solution_off(V);
}

int main(){
    //test data
    vector<int> testv1; 
    for(int j = 0; j < 20; j++){
            if (j < 10) testv1.push_back(j);
            else        testv1.push_back(0);
        }
    
    int myints[] = {2,2,0,1,2,1,2,1,1,1,2,2};
    vector<int> testv2 (myints, myints + sizeof(myints) / sizeof(int) );

    //tests
    test(testv1);
    test(testv2);
}

/*
 * Source: https://codility.com/demo/take-sample-test/genomic_range_query
 * Result: 100/100 @ https://codility.com/demo/results/demoYM2HWJ-MEH/
 * 
 * A non-empty zero-indexed string S is given. String S consists
 * of N characters from the set of upper-case English letters A,
 * C, G, T.
 *
 * This string actually represents a DNA sequence, and the 
 * upper-case letters represent single nucleotides.
 * 
 * You are also given non-empty zero-indexed arrays P and Q
 * consisting of M integers. These arrays represent queries 
 * about minimal nucleotides. We represent the letters of
 * string S as integers 1, 2, 3, 4 in arrays P and Q, where
 * A = 1, C = 2, G = 3, T = 4, and we assume that A < C < G < T.
 *
 * Query K requires you to find the minimal nucleotide from the
 * range (P[K], Q[K]), 0 ≤ P[i] ≤ Q[i] < N.
 * 
 * For example, consider string S = GACACCATA and arrays P, Q
 * such that:
 *
 *   P[0] = 0    Q[0] = 8
 *   P[1] = 0    Q[1] = 2
 *   P[2] = 4    Q[2] = 5
 *   P[3] = 7    Q[3] = 7
 *
 * The minimal nucleotides from these ranges are as follows:
 *
 *       (0, 8) is A identified by 1,
 *       (0, 2) is A identified by 1,
 *       (4, 5) is C identified by 2,
 *       (7, 7) is T identified by 4.
 *
 * Write a function:
 *
 *   vector<int> solution(string &S, vector<int> &P, vector<int> &Q); 
 *
 * that, given a non-empty zero-indexed string S consisting of N
 * characters and two non-empty zero-indexed arrays P and Q
 * consisting of M integers, returns an array consisting of M
 * characters specifying the consecutive answers to all queries.
 *
 * The sequence should be returned as:
 *
 *       a Results structure (in C), or
 *       a vector of integers (in C++), or
 *       a Results record (in Pascal), or
 *       an array of integers (in any other programming language).
 *
 * For example, given the string S = GACACCATA and arrays P, Q such that: 
 *
 *   P[0] = 0    Q[0] = 8
 *   P[1] = 0    Q[1] = 2
 *   P[2] = 4    Q[2] = 5
 *   P[3] = 7    Q[3] = 7
 *
 * the function should return the values [1, 1, 2, 4], as explained
 * above.
 * 
 * Assume that:
 *
 *       N is an integer within the range [1..100,000];
 *       M is an integer within the range [1..50,000];
 *       each element of array P, Q is an integer within the 
 *         range [0..N − 1]; 
 *       P[i] ≤ Q[i];
 *       string S consists only of upper-case English letters A, C, G, T.
 *
 * Complexity:
 *
 *       expected worst-case time complexity is O(N+M);
 *       expected worst-case space complexity is O(N), beyond 
 *         input storage (not counting the storage required for
 *         input arguments).
 *
 * Elements of input arrays can be modified.
 */

#include <vector>
vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    int N = S.length();
    int M = P.size();
    int ACGT = 4, A = 0, C = 1, G = 2, T = 3;
    
    vector<int> acgt(ACGT,0);
    vector< vector<int> > nucl_so_far(N+1,acgt);
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < ACGT; j++)
            nucl_so_far[i+1][j] = nucl_so_far[i][j];
            
        if (S[i] == 'A') nucl_so_far[i+1][A]++;
        if (S[i] == 'C') nucl_so_far[i+1][C]++;
        if (S[i] == 'G') nucl_so_far[i+1][G]++;
        if (S[i] == 'T') nucl_so_far[i+1][T]++;
    }
    
    vector<int> min_impacts(M,0);
    
    for(int i = 0; i < M; i++) {
        if (nucl_so_far[Q[i]+1][A] - nucl_so_far[P[i]][A] > 0) {
            min_impacts[i] = A + 1;
        }
        else if (nucl_so_far[Q[i]+1][C] - nucl_so_far[P[i]][C] > 0) {
            min_impacts[i] = C + 1;
        }
        else if (nucl_so_far[Q[i]+1][G] - nucl_so_far[P[i]][G] > 0) {
            min_impacts[i] = G + 1;
        }
        else if (nucl_so_far[Q[i]+1][T] - nucl_so_far[P[i]][T] > 0) {
            min_impacts[i] = T + 1;
        }
    }
    
    return min_impacts;
}


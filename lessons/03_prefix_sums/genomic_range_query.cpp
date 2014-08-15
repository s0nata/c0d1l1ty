/*
 * Source: https://codility.com/demo/take-sample-test/genomic_range_query
 * Result: 100/100
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


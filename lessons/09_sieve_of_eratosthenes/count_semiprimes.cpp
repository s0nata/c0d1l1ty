vector<int> solution(int N, vector<int> &P, vector<int> &Q) {
    int M = P.size();
    
    vector<int> spf(N+1,0), //smallest prime factors
                lpf(N+1,0); //largest prime factors
    int i = 2;
    //filling spf and lpf
    while (i <= N) {
        if (spf[i] == 0) {
            int k = i ;
            while (k <= N) {
                if (spf[k] == 0) spf[k] = i;
                if (lpf[k] < i)  lpf[k] = i;
                k += i;
            }
        }
        i++;
    }
    
    //counting semiprimes
    vector<int> counters(N+1,0);
    int cnt = 0;
    for(int i = 4; i < N+1; i++) {
        if (spf[i] * lpf[i] == i) cnt++;
        counters[i] = cnt;
    }

    //going through (P;Q) intervals
    vector<int> res(M,0);
    for (int i = 0; i < M; i++) {
        res[i] = counters[Q[i]] - counters[P[i]-1];
    }
    
    return res;
}

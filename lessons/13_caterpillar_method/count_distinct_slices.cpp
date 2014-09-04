int solution(int M, vector<int> &A) {
    int N = A.size();
    
    if (N == 1) return 1;
    
    int head = 0, tail = 0,
        cnt = 0,  cur_interv_len;
        
    while (tail < N) {
        // moving head to the right as far as possible
        // with this code (3,4,3,4) will be considered 
        //     a proper distinct slice
        while ((head < N -1) && (A[head + 1] != A[head])) head++;

        cur_interv_len = head - tail + 1;

        //TODO: check 1000000000 condition
        cnt += (cur_interv_len * (cur_interv_len + 1) ) / 2;

        head++;
        tail = head;
    }
    
    return cnt;
}

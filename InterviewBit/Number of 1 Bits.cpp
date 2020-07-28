int Solution::numSetBits(unsigned int A) {
    int cnt = 0;
    for (int i = 31; i >= 0; i--)
        if ((A >> i) & 1) cnt++; 
    return cnt;
}

unsigned int Solution::reverse(unsigned int A) {
    for (int i = 31, j = 0; i > 15; i--, j++) {
        if (((A >> i) & 1) == ((A >> j) & 1)) continue;
        A ^= (1 << i) ^ (1 << j);
    }
    return A;
}

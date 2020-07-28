int Solution::colorful(int A) {
    string s = to_string(A);
    set<int> st;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            string t = s.substr(i, j - i + 1);
            int p = 1;
            for (int k = 0; k <= j - i; k++)
                p *= t[k] - '0';
            auto it = st.find(p);
            if (it != st.end()) return 0;
            st.insert(p);
        }
    }
    return 1;
}

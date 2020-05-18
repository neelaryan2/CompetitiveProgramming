class Solution {
   public:
    bool backspaceCompare(string S, string T) {
        stack<char> st;
        int cnt;
        for (char c : S) {
            st.push(c);
            cnt = 0;
            while (!st.empty() && st.top() == '#')
                cnt++, st.pop();
            while (!st.empty() && cnt--)
                st.pop();
        }
        S.clear();
        while (!st.empty()) S += st.top(), st.pop();
        for (char c : T) {
            st.push(c);
            cnt = 0;
            while (!st.empty() && st.top() == '#')
                cnt++, st.pop();
            while (!st.empty() && cnt--)
                st.pop();
        }
        T.clear();
        while (!st.empty()) T += st.top(), st.pop();
        return (S == T);
    }
};
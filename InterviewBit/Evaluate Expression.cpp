using ll = long long;
int Solution::evalRPN(vector<string> &A) {
    stack<ll> st;
    for (string s : A) {
        if (s != "*" && s != "/" && s != "+" && s != "-") {
            st.push(stoll(s));
            continue;
        }
        ll b = st.top(); st.pop();
        ll a = st.top(); st.pop();
        if (s == "*") st.push(a * b);
        else if (s == "/") st.push(a / b);
        else if (s == "+") st.push(a + b);
        else if (s == "-") st.push(a - b);
    }
    return st.top();
}

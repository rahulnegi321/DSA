class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        set<string> st;
        queue<string> q;
        string ans = s;
        q.push(s);
        st.insert(s);

        while (!q.empty()) {
            string temp = q.front();
            q.pop();

            if (ans > temp) {
                ans = temp;
            }

            string t_add = temp;
            int n = temp.size();
            for (int i = 1; i < n; i = i + 2) {
                int d = t_add[i] - '0';
                d = (d + a) % 10;
                t_add[i] = (char)(d + '0');
            }
            if (!st.count(t_add)) {
                st.insert(t_add);
                q.push(t_add);
            }

            string t = temp;
            for (int i = 0; i < n; i++) {
                t[(i + b) % n] = temp[i];
            }

            if (!st.count(t)) {
                st.insert(t);
                q.push(t);
            }
        }
        return ans;
    }
};
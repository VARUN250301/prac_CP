class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char, int> m;
        for(char c: s) m[c]++;
        
        stack<char> st;
        vector<bool> v(26, false); //seen not seen
        for(int i = 0; i < s.length(); i++){
            if(v[s[i] - 'a']){
                m[s[i]]--;
                continue;
            }
            while(!st.empty() and m[st.top()] > 0 and st.top() > s[i]){
                v[st.top() - 'a'] = false;
                st.pop();
                
            }
            v[s[i] - 'a'] = true;
            st.push(s[i]);
            m[s[i]]--;
        }
        string ans = "";
        while(!st.empty()){
            char ch = st.top();
            st.pop();
            ans += ch;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
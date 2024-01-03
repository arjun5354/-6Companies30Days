/*
Question Source : https://www.proelevate.in/dsa-practice/6-companies-30-days
Asked By : goldman sachs
GFG : Number following a pattern
*/
class Solution{   
public:
    string printMinNumberForPattern(string s){
        int n=s.size();
        stack<int>st;
        string ans="";
        for(int i=0;i<=n;i++){
            st.push(i+1);
            if(s[i]=='I' || i==n){
                while(!st.empty()){
                    ans+=to_string(st.top());
                    st.pop();
                }
            }
            
        }
        return ans;
    }
};
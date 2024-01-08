/*
Question Source : https://www.proelevate.in/dsa-practice/6-companies-30-days
Asked By : microsoft
LeetCode : 299. Bulls and Cows
*/

class Solution {
public:
    string getHint(string secret, string guess) {
        int bull=0;
        int cows=0;
        vector<int>sec(10,0);
        vector<int>gue(10,0);
        int n=secret.size();
        for(int i=0;i<n;i++){
            if(secret[i]==guess[i]) bull++;
            else{
                sec[secret[i]-'0']++;
                gue[guess[i]-'0']++;
            }
        }
        for(int i=0;i<10;i++){
            cows+=min(sec[i],gue[i]);
        }

        string ans="";
        ans+=to_string(bull);
        ans+='A';
        ans+=to_string(cows);
        ans+='B';

        return ans;
    }
};
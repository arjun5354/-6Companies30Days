/*
Question Source : https://www.proelevate.in/dsa-practice/6-companies-30-days
Asked By : microsoft
LeetCode : 354. Russian Doll Envelopes
*/
class Solution {
public:
    int solveUsingRe(vector<vector<int>>&env,int prev,int i){
        if(i==env.size()) return 0;
        int include=0;
        if(prev==-1 || env[prev][0]<env[i][0]&&env[prev][1]<env[i][1]){
            include=1+solveUsingRe(env,i,i+1);
        }
        int exclude=solveUsingRe(env,prev,i+1);

        return max(include,exclude);
    }
    int solveUsingMem(vector<vector<int>>&env,int prev,int i, vector<vector<int>>&dp){
        if(i==env.size()) return 0;
        if(dp[prev+1][i]!=-1) return dp[prev+1][i];
        int include=0;
        if(prev==-1 || env[prev][0]<env[i][0]&&env[prev][1]<env[i][1]){
            include=1+solveUsingMem(env,i,i+1,dp);
        }
        int exclude=solveUsingMem(env,prev,i+1,dp);

        return dp[prev+1][i]=max(include,exclude);
    }
   static bool myCom(vector<int>&a,vector<int>&b){
       if(a[0]==b[0]) return a[1]>b[1];
       return a[0]<b[0];
   }
  int solveOptimal(vector<vector<int>>&arr) {
      // sort arr increasing order by width && wi==wj dec. by height
      sort(arr.begin(),arr.end(),myCom);
        if(arr.size() == 0)
            return 0;
        vector<int> ans;
        ans.push_back(arr[0][1]);

        for(int i=1; i<arr.size(); i++) {
            if(arr[i][1]> ans.back()) {
                //include
                ans.push_back(arr[i][1]);
            }
            else {
                //overwrite
                //find index of just bada element
                int index = lower_bound(ans.begin(), ans.end(), arr[i][1]) - ans.begin();
                ans[index] = arr[i][1];
            }
        }
        return ans.size();
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // sort(envelopes.begin(),envelopes.end());
        // return solveUsingRe(envelopes,-1,0);
        // vector<vector<int>>dp(envelopes.size()+1,vector<int>(envelopes.size()+1,-1));
        // return solveUsingMem(envelopes,-1,0,dp);
        
        return  solveOptimal(envelopes);
    }
};
/*
Question Source : https://www.proelevate.in/dsa-practice/6-companies-30-days
Asked By : goldman sachs
LeetCode : 2400. Number of Ways to Reach a Position After Exactly k Steps
*/
class Solution {
public:
    int mod=1e9+7;
    int solveUsingRe(int currPos,int target,int k){
        if(k==0&&currPos==target) return 1;

        if(k==0) return 0;

        int rightCount=solveUsingRe(currPos+1,target,k-1);
        int leftCount=solveUsingRe(currPos-1,target,k-1);

        return (leftCount+rightCount)%mod;
    }
    int solveUsingMem(int currPos,int target,int k,vector<vector<int>>&dp){
        if(k==0&&currPos==target) return 1;
        if(k==0) return 0;
        
        if(dp[currPos+1000][k]!=-1) return dp[currPos+1000][k];

        int rightCount=solveUsingMem(currPos+1,target,k-1,dp);
        int leftCount=solveUsingMem(currPos-1,target,k-1,dp);

        return dp[currPos+1000][k]=(leftCount+rightCount)%mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        // return solveUsingRe(startPos,endPos,k)%mod;
        vector<vector<int>>dp(startPos+2000,vector<int>(k+1,-1)); // here i took 2000 size of row cause startPos can be -ve but we can't store negetive value in the dp array so we take almost double size of the k..
        return solveUsingMem(startPos,endPos,k,dp)%mod;
    }
};
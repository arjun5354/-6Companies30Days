/*
Question Source : https://www.proelevate.in/dsa-practice/6-companies-30-days
Asked By : goldman sachs
LeetCode : 2327. Number of People Aware of a Secret
*/
class Solution {
public:
   int mod=1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long>dp(n+1,0);
        long long noOfPeopleSharingSecret=0;
        dp[1]=1;

        for(int i=2;i<=n;i++){
            long long noOfNewPeopleSharingSecret=dp[max(0,i-delay)];
            long long noOfPeopleForgettingSecret=dp[max(0,i-forget)];

            noOfPeopleSharingSecret+=(noOfNewPeopleSharingSecret-noOfPeopleForgettingSecret);
            dp[i]=noOfPeopleSharingSecret%mod;
        }
        long long ans=0;
        for(int i=n-forget+1;i<=n;i++){
            ans=(ans+dp[i])%mod;
        }
        return ans%mod;
    }
};
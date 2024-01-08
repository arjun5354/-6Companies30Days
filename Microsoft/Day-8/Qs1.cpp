/*
Question Source : https://www.proelevate.in/dsa-practice/6-companies-30-days
Asked By : microsoft
LeetCode : 1248. Count Number of Nice Subarrays
*/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]&1) nums[i]=1;
            else nums[i]=0;
        }

        unordered_map<int,int>mp;
        int sum=0,result=0;
        for(int i=0;i<n;i++){
             sum +=nums[i];
            if(sum==k) result++;

            if(mp.find(sum-k)!=mp.end()){
                result+=mp[sum-k];
            }
            mp[sum]++;
        }
        return result;
    }
};
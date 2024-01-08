/*
Question Source : https://www.proelevate.in/dsa-practice/6-companies-30-days
Asked By : microsoft
LeetCode : 560. Subarray Sum Equals K
*/
// Brute force Approach
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
           int sum=0;
            for(int j=i;j<n;j++){
                sum= sum+ nums[j];
                if(sum==k)cnt++;
            }
        }
        return cnt;
    }
};
// Optimal approach

/*

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();

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

*/
/*
Question Source : https://www.proelevate.in/dsa-practice/6-companies-30-days
Asked By : goldman sachs
LeetCode : 2261. K Divisible Elements Subarrays
*/
class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>>st; // set is used to remove duplicate element
        for(int i=0;i<nums.size();i++){
               vector<int>arr;
               int count=0;
            for(int j=i;j<nums.size();j++){
               if(nums[j]%p==0) count++;
                if(count>k) break;
                else arr.push_back(nums[j]);
                st.insert(arr);
            }
        }
    return st.size();
    }
};

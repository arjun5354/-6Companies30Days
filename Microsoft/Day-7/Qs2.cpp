/*
Question Source : https://www.proelevate.in/dsa-practice/6-companies-30-days
Asked By : microsoft
LeetCode : 462. Minimum Moves to Equal Array Elements II
*/
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        // sort the array
        sort(nums.begin(),nums.end());
        // calculate steps using two pointer
        int i=0,j=n-1;
        int steps=0;
        while(i<j){
            steps+=(nums[j]-nums[i]);
            i++;
            j--;
        }
        return steps;
    }
};
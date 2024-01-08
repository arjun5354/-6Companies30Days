/*
Question Source : https://www.proelevate.in/dsa-practice/6-companies-30-days
Asked By : microsoft
LeetCode : 453. Minimum Moves to Equal Array Elements
*/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        // sort(nums.begin(),nums.end());
        int minEle=*min_element(nums.begin(),nums.end());
        int steps=0;
    //    for(int i=0;i<n;i++){
       for(int i=n-1;i>=0;i--){
           steps+=nums[i]-minEle;
       }
       return steps;
    }
};
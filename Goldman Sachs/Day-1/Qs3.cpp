/*
Question Source : https://www.proelevate.in/dsa-practice/6-companies-30-days
Asked By : goldman sachs
Leetcode : 2343. Query Kth Smallest Trimmed Number
*/
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        int n = nums.size();
        for(auto &q:queries) {
            vector<pair<string,int>> pq;
            for(int i=0;i<n; i++) {
                pq.push_back({(nums[i].substr(nums[i].size()-q[1])), i});
            }
            sort(pq.begin(), pq.end());
            res.push_back(pq[q[0]-1].second);
        }
        return res;
    }
};
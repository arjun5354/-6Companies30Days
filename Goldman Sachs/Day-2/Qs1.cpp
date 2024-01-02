/*
Question Source : https://www.proelevate.in/dsa-practice/6-companies-30-days
Asked By : goldman sachs
Leetcode : 216. Combination Sum III
*/
class Solution {
public:
   void solveUsingRe(int i,int k,int sumTillNow,int n,vector<int>&subset,vector<vector<int>>&ans){
       // base case
       if(k<0) return;
       if(sumTillNow==n){
           if(k==0){
           ans.push_back(subset);
            return;
           }
           else return;
       }
       if(i==10) return;
      // take i
      subset.push_back(i);
       solveUsingRe(i+1,k-1,sumTillNow+i,n,subset,ans);
       // backtrac
       subset.pop_back();
       // not take i
       solveUsingRe(i+1,k,sumTillNow,n,subset,ans);
       
   }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>subset;
         solveUsingRe(1,k,0,n,subset,ans);   
         return ans;     
    }
};
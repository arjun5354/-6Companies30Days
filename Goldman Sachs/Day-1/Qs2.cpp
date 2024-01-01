/*
Question Source : https://www.proelevate.in/dsa-practice/6-companies-30-days
Asked By : goldman sachs
Leetcode : 2933. High-Access Employees
*/
class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
       // step-1 : create a map
       unordered_map<string,vector<int>>mp;// name->access time
       for(auto&it:access_times){
           int time=stoi(it[1]);
           mp[it[0]].push_back(time);
       }
       // step-2 : sort elements by their time
       for(auto&it:mp){
           if(it.second.size()<3) continue; // 
           sort(it.second.begin(),it.second.end());
       }
      // step-3 : store ans

      vector<string>ans;
      for(auto&it:mp){
          auto&time=it.second;
          for(int i=2;i<time.size();i++){
              if(time[i]-time[i-2]< 100){
                  ans.push_back(it.first);
                  break; // if we don't use break then it will give wrong ans in this test case :  [["dz","0719"],["dz","0726"],["dz","0716"],["dz","0716"]]
              }
          }
      }
     
    return ans;
    }
};
/*
Question Source : https://www.proelevate.in/dsa-practice/6-companies-30-days
Asked By : goldman sachs
Leetcode : 1765. Map of Highest Peak
*/

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int row=isWater.size();
        int col=isWater[0].size();
        vector<vector<int>>grid(row,vector<int>(col,INT_MAX));
        queue<pair<int,int>>q;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(isWater[i][j]==1){
                    q.push({i,j});
                    grid[i][j]=0;
                }
            }
        }

        while(!q.empty()){
            int Row=q.front().first;
            int Col=q.front().second;
            q.pop();
            int dx[]={-1,0,1,0};
            int dy[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int Crow=Row+dx[i];
                int Ccol=Col+dy[i];
                if(Crow>=0&&Crow<row && Ccol>=0&&Ccol<col && grid[Crow][Ccol]>1+grid[Row][Col]){
                    grid[Crow][Ccol]=1+grid[Row][Col];
                    q.push({Crow,Ccol});
                }
            }
        }
        return grid;
    }
};
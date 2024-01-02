/*
Question Source : https://www.proelevate.in/dsa-practice/6-companies-30-days
Asked By : goldman sachs
Leetcode : 519. Random Flip Matrix
*/
class Solution {
public:
    int n,m;
    int i=0,j=0; // we are starting from first row and first column
    Solution(int m, int n) {
        this->m=m;
        this->n=n;
    }
    
    vector<int> flip() {
        int row=i,col=j;
        if(j+1<n)++j;
        else if(i+1<m){
            i++;
            j=0;
        }
        else i=j=0;

        return {row,col};
    }
    
    void reset() {
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
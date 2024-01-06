/*
Question Source : https://www.proelevate.in/dsa-practice/6-companies-30-days
Asked By : microsoft
LeetCode : 1823. Find the Winner of the Circular Game
*/

class Solution {
public:
  // Josephus problem  
    int Winner(int n,int k){
        if(n==1) return 0;
        return (Winner(n-1,k)+k)%n;
    }
    int findTheWinner(int n, int k) {
        return Winner(n,k)+1;
    }
};
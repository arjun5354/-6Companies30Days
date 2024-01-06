/*
Question Source : https://www.proelevate.in/dsa-practice/6-companies-30-days
Asked By : microsoft
LeetCode : 1401. Circle and Rectangle Overlapping
*/
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int nearest_x=max(x1,min(x2,xCenter));
        int nearest_y=max(y1,min(y2,yCenter));

        int distFromX=nearest_x-xCenter;
        int distFromY=nearest_y-yCenter;
        return distFromX*distFromX+distFromY*distFromY<=radius*radius;
    }
};
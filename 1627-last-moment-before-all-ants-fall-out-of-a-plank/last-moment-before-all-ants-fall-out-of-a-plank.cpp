class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int leftidx, rightidx;
        if (left.size()==0) {
            leftidx=-1;
        } else if (right.size() == 0) {
            rightidx=-1;
        }
        if (leftidx!=-1)leftidx=INT_MIN;
        if (rightidx!=-1)rightidx=INT_MAX;
        for(int i = 0; i < left.size(); i++) {
            leftidx= max(leftidx,left[i]);
        }
        for(int i = 0; i < right.size(); i++) {
            rightidx= min(rightidx,right[i]);
        }
        if(leftidx==-1)return n-rightidx;
        else if (rightidx==-1)return leftidx;
        return max(leftidx , n-rightidx);
    }
};
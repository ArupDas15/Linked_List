class Solution {
public:
/*
Practically, on a grid, Chebyshev distance represents distance measured as if the shortest path between two points can take steps in any of the 8 grid directions at equal cost. Thus, by definition, Chebyshev distance is generally a useful distance measurement in games that allow unrestricted 8-way movement, where moving diagonally costs no more than moving in a cardinal direction.
*/
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if((sx==fx and sy==fy) and t==1)return false;
        // cout<<fx-sx<<endl<<fy-sy<<endl<<max(fx-sx,fy-sy);
        if (max(abs(fx-sx),abs(fy-sy)) <= t) return true;
        return false;
    }
};
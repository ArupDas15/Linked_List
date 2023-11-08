class Solution {
public:
/*
In a 2D grid, the Chebyshev distance represents the shortest path between
two points provided, one can take steps in any of the 8 grid directions at
equal cost. Thus, by definition, Chebyshev distance is generally a useful
distance measurement in games that allow unrestricted 8-way movement
where moving diagonally costs no more than moving in a cardinal direction.
*/
    // Time complexity: O(1)
    // Space complexity: O(1)
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        /* We cannot move to an adjacent point in one unit of time but 
        we cannot come back to the start/finish time. If start and end 
        refer to the same cell, we can successfully move from start to 
        end in given time t if t != 1.*/
        if(sx==fx and sy==fy and t==1) {
            return false;
        } 
        return max(abs(fx-sx),abs(fy-sy)) <= t;
    }
};

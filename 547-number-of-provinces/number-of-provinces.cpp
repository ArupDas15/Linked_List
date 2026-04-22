class Solution {
public:
    struct node{
        int parent;
        int rank;
    };
    vector<node> dsuf;
    int ans = 0;

    // union by rank
    void union_by_rank_op(int fromP, int toP) {
        if(dsuf[fromP].rank < dsuf[toP].rank) {
            dsuf[fromP].parent = toP; 
        } else if(dsuf[fromP].rank > dsuf[toP].rank ) {
            dsuf[toP].parent=fromP;  
        } else {
            dsuf[fromP].parent = toP;
            dsuf[toP].rank += 1;
        }
    }
    int find(int v) {
        if (dsuf[v].parent == v) return v;
        return dsuf[v].parent = find(dsuf[v].parent); //path compression
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        dsuf.resize(isConnected.size());
        int n = isConnected.size();

        for(int i = 0; i<n;i++){
            dsuf[i].parent=i;
            dsuf[i].rank=0;
        }

        for(int i = 0 ; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(isConnected[i][j] == 1) {
                    int fromP = find(i);
                    int toP = find(j);
                    if (toP != fromP) {
                        union_by_rank_op(toP,fromP);
                    }
                }
            }
        }
        for(int i = 0; i<n;i++){
            if (find(dsuf[i].parent)==i) ans++;
        }
        return ans;
    }
};
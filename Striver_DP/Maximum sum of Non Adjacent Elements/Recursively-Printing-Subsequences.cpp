// Reference: https://www.youtube.com/watch?v=AxNNVECce8c
// Time complexity: O(n*2^n), Space Complexity: O(n)
#include <bits/stdc++.h>
using namespace std;
void printF(vector<int>a,vector<int>&ds,int idx){
    if(idx==a.size()){
        for(int i=0;i<ds.size();i++)
            cout<<ds[i]<<" ";
        cout<<endl;
        return;
    }
    // pick the element.
    ds.push_back(a[idx]);
    printF(a,ds,idx+1,us);
    // do not pick the element.
    ds.pop_back();
    printF(a,ds,idx+1,us);
}
int main() {
    // Write C++ code here
    ordered_set<vector<int>>us;
    vector <int>a={3,1,2};
    int idx=0;
    vector<int>ds;
    printF(a,ds,idx,us);
    return 0;
}

// Reference: https://www.youtube.com/watch?v=AxNNVECce8c
// Time complexity: O(n*2^n), Space Complexity: O(n)
#include <bits/stdc++.h>
using namespace std;
void printF(vector<int>&a,vector<int>&ds,int idx){
    if(idx==a.size()){
        for(int i=0;i<ds.size();i++)
            cout<<ds[i]<<" ";
        if(ds.size()==0)cout<<"{}";
        cout<<endl;
        return;
    }
    // pick the element.
    ds.push_back(a[idx]);
    printF(a,ds,idx+1);
    // do not pick the element.
    ds.pop_back();
    printF(a,ds,idx+1);
}
int main() {
    vector <int>a={3,1,2};
    int idx=0;
    vector<int>ds;
    printF(a,ds,idx);
    return 0;
}
/* Sample Output
3 1 2 
3 1 
3 2 
3 
1 2 
1 
2 
{}    
 */

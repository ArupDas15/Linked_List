// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string str){
     int n = str.length();
        int cur_len = 1;  // lenght of current substring
        int max_len = 1;  // result
        int prev_index;  //  previous index
        int i;
        int visited[26];
     
        for (i = 0; i < 26;  i++)
            visited[i] = -1;
        // cout<<(int)str[0]<<"\n";
        visited[str[0]-'a'] = 0;
     
        for (i = 1; i < n; i++)
        {
            prev_index =  visited[str[i]-'a'];
     
            if (prev_index == -1 || i - cur_len > prev_index)
                cur_len++;
     
            else
            {
                if (cur_len > max_len)
                    max_len = cur_len;
     
                cur_len = i - prev_index;
            }
     
            visited[str[i]-'a'] = i;
        }
     
        if (cur_len > max_len)
            max_len = cur_len;
     
        // free(visited); // free memory allocated for visited
        return max_len;   
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}  // } Driver Code Ends
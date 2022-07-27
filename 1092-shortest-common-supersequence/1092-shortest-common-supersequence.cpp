class Solution {
public:
    string LCS(string str1, string str2){
        // int m = str1.length(), n = str2.length();
        // int t[m+1][n+1];
        // for(int i = 0; i < m + 1; i++){
        //     for( int j = 0; j < n + 1; j++){
        //         if(i == 0 || j == 0)
        //             t[i][j] = 0;
        //         else{
        //             if(str1[i - 1] == str2[j - 1])
        //                 t[i][j] = 1 + t[i - 1][j - 1];
        //             else
        //                 t[i][j] = max (t[i - 1][j], t[i][j - 1]);
        //         }
        //     }
        // }
        // int i = m, j = n;
        // string ans;
        // while(i>0 && j>0){
        //     if(str1[i-1]==str2[j-1]){
        //         ans = ans + str1[i - 1];
        //         i--;
        //         j--;
        //     }
        //     else if(t[i-1][j] > t[i][j-1])
        //         i--;
        //     else j--;
        // }
        // reverse(ans.begin(),ans.end());
        // return ans;
        int n = str1.size(), m = str2.size();
        vector<vector<string>> dp(n + 1, vector<string>(m + 1, ""));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (str1[i] == str2[j])
                    dp[i + 1][j + 1] = dp[i][j] + str1[i];
                else
                    dp[i + 1][j + 1] = dp[i + 1][j].size() > dp[i][j + 1].size() ?  dp[i + 1][j] : dp[i][j + 1];
        return dp[n][m];
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int i = 0, j = 0;
        string res="";
        for(char c:LCS(str1,str2)){
            while(str1[i]!=c)
                res=res+str1[i++];
            while(str2[j]!=c)
                res=res+str2[j++];
            res=res+c;
            i++;
            j++;
        }
        res=res+str1.substr(i)+str2.substr(j);
        return res;
    }
};
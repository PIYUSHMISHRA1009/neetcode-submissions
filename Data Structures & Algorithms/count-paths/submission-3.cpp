class Solution {
public:
    int uniquePaths(int n, int m) {
        //tabulation code
        vector<vector<int>> dp(n,vector<int>(m,0));
        dp[0][0]=1;
        for(int i=1;i<m;i++){
            dp[0][i]=1;
        }
        for(int j=1;j<n;j++){
            dp[j][0]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                int down=dp[i-1][j];
                int right=dp[i][j-1];
                dp[i][j]=down+right;
            }
        }
        return dp[n-1][m-1];
    }
};

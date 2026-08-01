class Solution {
public:
    int uniPaths(int i,int j,vector<vector<int>> &dp){
        if(i<0 || j<0 ){
            return 0;
        }
        if(i==0 && j==0){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int up=uniPaths(i-1,j,dp);
        int left=uniPaths(i,j-1,dp);
        return dp[i][j]=up+left;
    }
    int uniquePaths(int n, int m) {
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return uniPaths(n-1,m-1,dp);
    }
};

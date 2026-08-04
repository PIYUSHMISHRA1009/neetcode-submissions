class Solution {
public:
    int countSubstrings(string s) {
       int n=s.length();
       int cnt=0;
       vector<vector<bool>> dp(n,vector<bool>(n,false)); 
       for(int i=0;i<n;i++){
        dp[i][i]=true;
        cnt++;
       }
       for(int len=2;len<=n;len++){
        for(int i=0;i+len-1<n;i++){
            int j=i+len-1;
            if(s[i]==s[j]&&(len<=3 || dp[i+1][j-1])){
                dp[i][j]=1+dp[i-1][j-1];
                cnt++;
            }
            else{
                dp[i][j]=0;
            }
        }
       }
       return cnt;
    }
};

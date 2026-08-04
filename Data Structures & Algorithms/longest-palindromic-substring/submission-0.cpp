class Solution {
public:
    //use the concept
    string LongestCommonSubstring(string &s1,string &s2){
        int n1=s1.length();
        int n2=s2.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        int ans=INT_MIN;
        int endindex=-1;
        string res="";
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    if(dp[i][j]>ans){
                        ans=max(ans,dp[i][j]);
                        endindex=i;
                    }
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        return s1.substr(endindex-ans,ans);
    }
    string longestPalindrome(string s) {
        string s1=s;
        string s2=s;
        reverse(s2.begin(),s2.end());
        return LongestCommonSubstring(s1,s2);
    }
};

class Solution {
public:
    bool isPalindrome(string s) {
        string n="";
        for(int i=0;i<s.length();i++){
            if(isalnum(s[i])){
                n+=tolower(s[i]);
            }
        }
        int l=0;
        int r=n.length()-1;
        while(l<r){
            if(n[l]!=n[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};

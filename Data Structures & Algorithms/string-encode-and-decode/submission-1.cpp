class Solution {
public:

    string encode(vector<string>& strs) {
        string res="";
        for(int i=0;i<strs.size();i++){
            res+=to_string(strs[i].length())+'#'+strs[i];
        }
        return res;
    }

    vector<string> decode(string s) {
        int i=0;
        vector<string> res;
        while(i<s.length()){
            int j=i;
            while(s[j]!='#'){
                j++;
            }
            int len=stoi(s.substr(i,j-i));
            string t=s.substr(j+1,len);
            res.push_back(t);
            i=j+len+1;
        }
        return res;
    }
};

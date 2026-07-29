class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low = 0, high = 0;
        int n = s.length();

        unordered_map<char, int> mpp;
        int len = 0;      

        while (high < n) {
            mpp[s[high]]++;

            while (mpp.size() < (high - low + 1)) {
                mpp[s[low]]--;
                if (mpp[s[low]] == 0)
                    mpp.erase(s[low]);
                low++;
            }

            len = max(len, high - low + 1);
            high++;
        }

        return len;
    }
};
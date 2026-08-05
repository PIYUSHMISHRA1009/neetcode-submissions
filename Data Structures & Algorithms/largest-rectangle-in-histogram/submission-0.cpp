class Solution {
public:
    //find NSE and PSE then compute area at each heigh and find larget
    vector<int> NSE(vector<int> &heights){
        int n=heights.size();
        vector<int> res(n,n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&& heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()){
                res[i]=st.top();
            }
            st.push(i);
        }
        return res;
    }
    vector<int> PSE(vector<int> &heights){
        int n=heights.size();
        vector<int> res(n,-1);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()){
                res[i]=st.top();
            }
            st.push(i);
        }
        return res;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nextGE=NSE(heights);
        vector<int> prevGE=PSE(heights);
        int maxi=INT_MIN;
        for(int i=0;i<heights.size();i++){
            int area=(nextGE[i]-prevGE[i]-1)*heights[i];
            maxi=max(maxi,area);
        }
        return maxi;
    }
};

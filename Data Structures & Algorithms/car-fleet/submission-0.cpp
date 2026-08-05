class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> res;
        for(int i=0;i<position.size();i++){
            res.push_back({position[i],speed[i]});
        }
        sort(res.begin(),res.end());
        stack<double> st;
        int n=res.size();
        for(int i=n-1;i>=0;i--){
           double currTime=(double)(target-res[i].first)/res[i].second;
           if(st.empty() || currTime>st.top()){
            st.push(currTime);
           }
        }
        return st.size();
    }
};

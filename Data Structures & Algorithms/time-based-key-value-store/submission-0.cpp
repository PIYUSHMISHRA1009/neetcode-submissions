class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mpp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(mpp.find(key) == mpp.end()) return "";
        string res="";
        auto it=mpp[key];
        int low=0;
        int high=it.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(it[mid].first<=timestamp){
                res=it[mid].second;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return res;
    }
};

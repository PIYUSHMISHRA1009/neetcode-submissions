class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0;
        int r=heights.size()-1;
        int maxWater=INT_MIN;
        while(l<r){
            int water=(r-l)*min(heights[l],heights[r]);
            maxWater=max(maxWater,water);
            if(heights[l]>heights[r]){
                r--;
            }
            else if(heights[l]<=heights[r]){
                l++;
            }
        }
        return maxWater;
    }
};

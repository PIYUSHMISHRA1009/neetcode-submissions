class Solution {
public:
    int trap(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int maxLeft=height[l];
        int maxRight=height[r];
        int maxarea=0;
        while(l<r){
          if(maxLeft<maxRight){
            l++;
            maxLeft=max(maxLeft,height[l]);
            maxarea+=maxLeft-height[l];
          }
          else{
            r--;
            maxRight=max(maxRight,height[r]);
            maxarea+=maxRight-height[r];
          }
        }
        return maxarea;

    }
};

class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int x = 0;x<=nums[nums.size()-1];++x){
            auto it = lower_bound(nums.begin(),nums.end(),x);
            if(x==(nums.end()-it))return x;
        }
        return -1;
    }
};

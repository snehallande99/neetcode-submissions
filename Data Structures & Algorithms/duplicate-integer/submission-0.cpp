class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        vector<int> ind;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++)
        {
           if(nums[i]==nums[i-1])
           {
            return true;
           }
        }
        return false;
    }
};
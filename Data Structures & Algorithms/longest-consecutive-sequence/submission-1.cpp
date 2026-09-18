class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        vector <int> res;
        int n=nums.size();
        if(n<=1)
        return n;
        sort(nums.begin(),nums.end());
        int max=1;
        for(int i=1;i<n;i++){
          if(nums[i]==nums[i-1])
          {
            if(i==n-1)
            {
                res.push_back(max);
            }
            continue;
          }
          else if(nums[i]==nums[i-1]+1)
          {
            max++;
            if(i==n-1)
            {
                res.push_back(max);
            }
          }
          else{
            res.push_back(max);
            max=1;
          }
          
        }
        sort(res.begin(),res.end(),greater<int>());

        return res[0];
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector <int> res;
      
        sort(nums.begin(),nums.end());
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
          if(mp.find(nums[i])==mp.end())
          {
            mp[nums[i]]=1;
          }
          else{
            mp[nums[i]]++;
          }
        }

        vector<pair<int, int>> v(mp.begin(), mp.end());
        sort(v.begin(),v.end(),[](auto &a, auto &b)
        {
            return a.second>b.second;
        });
        if(k>mp.size())
        {
            k=mp.size();
        }
        for(int i=0;i<k;i++)
        {
            res.push_back(v[i].first);
        }

        return res;
    }
};

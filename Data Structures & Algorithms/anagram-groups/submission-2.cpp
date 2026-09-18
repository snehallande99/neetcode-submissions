class Solution {
public:
    struct ArrayHash {
        size_t operator()(const array<int, 26>& arr) const {
            size_t h = 0;

            for(int x : arr) {
                h = h * 31 + x;
            }

            return h;
        }
    };
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<array<int, 26>,vector<string>, ArrayHash > mp;
        for(int i=0;i<strs.size();i++)
        {
            array<int, 26> cnt = {};
            for(char ch : strs[i])
            {
                cnt[ch - 'a']++;
            }
            mp[cnt].push_back(strs[i]); 
        }
        for(auto pr:mp)
        {
            res.push_back(pr.second);
        }
        return res;
    }
};

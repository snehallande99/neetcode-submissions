class Solution {
public:
    vector<int> countBits(int n) {
         vector<int> res;

         for(int i=0;i<=n;i++)
         {
            int m=0;
            for(int j=0;j<32;j++)
            {
                if(i&(1<<j))
                m++;
            }
            res.push_back(m);
         }

         return res;
    }
};

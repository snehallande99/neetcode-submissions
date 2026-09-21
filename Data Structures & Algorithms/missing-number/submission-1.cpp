class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n==0)
        return 0;
        int x=nums[0]&1;
        if(x==1)
        {
            return 0;
        }
        
        for(int i=0;i<n-1;i++)
        {
            int a=nums[i]&1;
            int b=nums[i+1]&1;
            
            if(a^b)
            {
                continue;
            }
            else
            {
                return nums[i+1]-1;
            }    
           
        }

        return nums[n-1]+1;
    }
};

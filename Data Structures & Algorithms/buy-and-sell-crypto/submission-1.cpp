class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxp=0;
        int i=0;
        int j=prices.size();

        while(i<prices[i]-1 && prices[i]>prices[i+1])
        {
            i++;
        }
        while(j>0 && prices[j-1]>prices[j])
        {
            j--;
        }

        for(int k=0;k<prices.size();k++)
        {
            for(int l=k+1;l<prices.size();l++)
            {
                maxp=max(maxp,prices[l]-prices[k]);
            }
        }

        return maxp;
    }
};

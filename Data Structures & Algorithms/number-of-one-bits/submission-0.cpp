class Solution {
public:
    int hammingWeight(uint32_t n) {
        int m=0;
        for(int i=0;i<32;i++)
        {
            if(n&(1<<i))
            m++;
            else
            continue;
        }
        return m;
    }
};

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        for(int i = 0; i < 16; i++)
        {
            int a = i;
            int b = 31 - i;

            uint32_t bit1 = (n >> a) & 1;
            uint32_t bit2 = (n >> b) & 1;

            if(bit1 != bit2)
            {
                n ^= (1u << a);
                n ^= (1u << b);
            }
        }

        return n;
    }
};
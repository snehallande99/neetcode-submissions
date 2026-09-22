class Solution {
public:
    int getSum(int a, int b) {
        int rem=0;
        int last=0;
        int x=0;
        int i=0;
        for(i=0;i<32;i++)
        {
            int n1=(a>>i)&1;
            int n2=(b>>i)&1;
            int r;
            cout<<rem;
            if(rem==1)
            {
              r=rem^n1^n2;
            }
            else{
                r=n1^n2;
            }
            if(r)
            {
              if(rem==1 && n1==1 && n2==1)
              {
                rem=1;
              }
              else
              {rem=0;}
              last=1;
            }
            else{
                if(n1==1 || n2==1)
                {
                    rem=1;
                    last=0;
                }
                else{
                    rem=0;
                    last=0;
                }
            }
            x = x | (last<<i);
        }
        // if(rem==1)
        // {
        //    return 11;
        // }
        return x;
    }
};

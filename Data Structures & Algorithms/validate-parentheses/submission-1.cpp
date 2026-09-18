class Solution {
public:
    bool isValid(string s) {          
        stack <char> st;
        int i=0;
        while(i<s.size())
        {
            if(s[i]=='(' || s[i]== '{' || s[i]=='[')
            {
                st.push(s[i]);
                 i++;
                 continue;
            }
            if(s[i]==')')
            {
                if(st.empty())
                    return false;

                if( st.top()=='(')
                {
                    st.pop();
                    i++;
                    continue;
                }
                else{
                    return false;
                }
            }
            if(s[i]=='}')
            { 
                if(st.empty())
                    return false;

                if(st.top()=='{'           )
                {
                    st.pop();
                    i++;
                    continue;
                }
                else{
                   return false;
                }
                
            }
            if(s[i]==']')
            {
                if(st.empty())
                    return false;

                if(st.top()=='[')
                {
                st.pop();
                i++;
                continue;
                }
                else{
                    return false;
                }
                
            }
    
            i++;  
        }
      if(st.empty())
      return true;
      else
      return false;
    }
};

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m= heights[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> v(n,vector<int>(m,0));
        //pacific
        for(int col=0;col<m;col++)
        {
            int r=0;
            int c=col;
            if(v[r][c]!=1)
            {
                q.push({r,c});
                while(!q.empty())
                {
                r=q.front().first;
                c=q.front().second;
                v[r][c]=1;
              
                if(c>0 && heights[r][c-1]>=heights[r][c] && v[r][c-1]!=1)
                {
                    v[r][c-1]=1;
                    q.push({r,c-1});
                    
                }
                if((c+1)<m && heights[r][c+1]>=heights[r][c] && v[r][c+1]!=1)
                {
                    v[r][c+1]=1;
                    q.push({r,c+1});
                    
                }
                
                if((r+1)<n && heights[r+1][c]>=heights[r][c] && v[r+1][c]!=1)
                {
                    v[r+1][c]=1;
                    q.push({r+1,c});
                    
                }
                q.pop();
                }
                
            }
        }
        for(int row=0;row<n;row++)
        {
            int r=row;
            int c=0;
            if(v[r][c]!=1)
            {
                q.push({r,c});
                while(!q.empty())
                {
                r=q.front().first;
                c=q.front().second;
                v[r][c]=1;
              
                if((c+1)<m && heights[r][c+1]>=heights[r][c] && v[r][c+1]!=1)
                {
                    v[r][c+1]=1;
                    q.push({r,c+1});
                }
                 if((r+1)<n && heights[r+1][c]>=heights[r][c] && v[r+1][c]!=1)
                {
                    v[r+1][c]=1;
                    q.push({r+1,c});
                }
                if((r-1)>=0 && heights[r-1][c]>=heights[r][c] && v[r-1][c]!=1)
                {
                    v[r-1][c]=1;
                    q.push({r+1,c});
                }
                q.pop();
                }
                
            }
        }

        //Alantic

        for(int col=0;col<m;col++)
        {
            int r=n-1;
            int c=col;
            if(v[r][c]!=2 && v[r][c]!=3)
            {
                q.push({r,c});
                while(!q.empty())
                {
                r=q.front().first;
                c=q.front().second;
                if(v[r][c]==1 || v[r][c]==3)
                v[r][c]=3;
                else
                v[r][c]=2;
              
                if(c>0 && heights[r][c-1]>=heights[r][c] && v[r][c-1]!=2 && v[r][c-1]!=3 )
                {
                    if(v[r][c-1]==1 || v[r][c-1]==3)
                    v[r][c-1]=3;
                    else
                    v[r][c-1]=2;
                    q.push({r,c-1});
                    
                }
                if((c+1)<m && heights[r][c+1]>=heights[r][c] && v[r][c+1]!=2 && v[r][c+1]!=3)
                {
                    if(v[r][c+1]==1 || v[r][c+1]==3)
                    v[r][c+1]=3;
                    else
                    v[r][c+1]=2;
                    
                    q.push({r,c+1});
                    
                }
                
                if((r-1)>=0 && heights[r-1][c]>=heights[r][c] && v[r-1][c]!=2 && v[r-1][c]!=3)
                {
                    if(v[r-1][c]==1 || v[r-1][c]==3)
                    v[r-1][c]=3;
                    else
                    v[r-1][c]=2;
                
                    q.push({r-1,c});
                   
                }
                q.pop();
                }
                
            }
        }
        for(int row=0;row<n;row++)
        {
            int r=row;
            int c=m-1;
            if(v[r][c]!=2 && v[r][c]!=3)
            {
                q.push({r,c});
                while(!q.empty())
                {
                r=q.front().first;
                c=q.front().second;

                if(v[r][c]==1 || v[r][c]==3)
                    v[r][c]=3;
                else
                    v[r][c]=2;
            
                if(c>0 && heights[r][c-1]>=heights[r][c] && v[r][c-1]!=2 && v[r][c-1]!=3)
                {
                    if(v[r][c-1]==1 || v[r][c-1]==3)
                    v[r][c-1]=3;
                    else
                    v[r][c-1]=2;
                    q.push({r,c-1});
                    
                }
                if((r+1)<n && heights[r+1][c]>=heights[r][c] && v[r+1][c]!=2 && v[r+1][c]!=3)
                {
                    if(v[r+1][c]==1 || v[r+1][c]==3)
                    v[r+1][c]=3;
                    else
                    v[r+1][c]=2;
                    q.push({r+1,c});
                    
                }
                
                if((r-1)>=0 && heights[r-1][c]>=heights[r][c] && v[r-1][c]!=2 && v[r-1][c]!=3)
                {
                    if(v[r-1][c]==1 || v[r-1][c]==3)
                    v[r-1][c]=3;
                    else
                    v[r-1][c]=2;
                    q.push({r-1,c});
                    
                }
                q.pop();
                }
                
            }
        }
        vector<vector<int>> res;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]==3)
                {
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    res.push_back(temp);
                }
                
            }
        }

        return res;
    }
};

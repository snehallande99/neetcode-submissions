class Solution {
public:
    void dfss(int r, int c, vector<vector<int>>& v,vector<vector<char>>& grid)
    {
        queue<pair<int,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        q.push({r,c});
        v[r][c]==1;
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=-1;i<=1;i++)
            {
                for(int j=-1;j<=1;j++)
                {
                    if(i!=0 && j!=0)
                    {
                        continue;
                    }
                    int rr=row+i;
                    int cc=col+j;
                    if(rr>=0 && rr<n && cc>=0 && cc<m && v[rr][cc]==0 && grid[rr][cc]=='1')
                    {
                        v[rr][cc]=1;
                        q.push({rr,cc});
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
       int r=grid.size();
       int c=grid[0].size();
       vector<vector<int>> v(r,vector<int>(c,0));
       int count=0;
       for(int i=0;i<r;i++)
       {
        for(int j=0;j<c;j++)
        {
            if(v[i][j]==0 && grid[i][j]=='1')
            {
                dfss(i,j,v,grid);
                count++;
            }
        }
       }
       return count; 
    }
};

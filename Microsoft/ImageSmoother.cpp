class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m= img[0].size();

        vector<vector<int>> ans(n,vector<int>(m,0));

        int dx[9] = {-1,-1,-1,0,0,0,1,1,1};
        int dy[9] = {-1,0,1,-1,0,1,-1,0,1};

        int avg = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int num = 0;
                int sum = 0;
                for(int k=0;k<9;k++)
                {
                    int r = i+dx[k];
                    int c = j+dy[k];

                    if(r<0 || c<0 || r>=n || c>=m)
                    {
                        continue;
                    }

                    num++;
                    sum+=img[r][c];

                }
                avg = floor(sum/num);
                ans[i][j] = avg;
            }
        }

        return ans;
    }
};

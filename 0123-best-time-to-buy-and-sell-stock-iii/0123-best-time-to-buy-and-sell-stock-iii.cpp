class Solution {
public:
int check(int idx,int buy,vector<int>& prices,vector<vector<vector<int>>>dp,int count)
{
    if(count==2)
    {
        return 0;
    }
    if(idx==prices.size())
    {
        return 0;
    }
    if(dp[idx][buy][count]!=-1)
    {
        return dp[idx][buy][count];
    }
    if(buy)
    {
        int take=-prices[idx]+check(idx+1,0,prices,dp,count);
        int notake=check(idx+1,1,prices,dp,count);
        return dp[idx][buy][count]=max(take,notake);
    }
    else
    {
        int sell=prices[idx]+check(idx+1,1,prices,dp,count+1);
        int nosell=check(idx+1,0,prices,dp,count);
        return dp[idx][buy][count]=max(sell,nosell);
    }

}
  
    int maxProfit(vector<int>& prices) {
         int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,(vector<int>(3,-1))));
        //return check(0,1,prices,dp,0);
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<2;j++)
            {
                dp[i][j][2]=0;
            }
        }
        for(int j=0;j<2;j++)
        {
            for(int i=0;i<3;i++)
            {
                dp[n][j][i]=0;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<2;j++)
            {
                for(int k=0;k<2;k++)
                {
                    if(j)
                    {
                        int take=-prices[i]+dp[i+1][0][k];
                        int notake=dp[i+1][1][k];
                        dp[i][j][k]=max(take,notake);
                    }
                    else
                    {
                        int sell=prices[i]+dp[i+1][1][k+1];
                        int nosell=dp[i+1][0][k];
                        dp[i][j][k]=max(sell,nosell);
                    }
                }
            }
        }
        return dp[0][1][0];
    }
};
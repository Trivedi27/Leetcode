
int fun(string&s,string&t,int i1,int i2,vector<vector<int>>&dp)
{
if( i2==t.size() )                return 1;
if( t.size()-i2>s.size()-i1 )                  return 0;
if(dp[i1][i2]!=-1)                  return dp[i1][i2];
int count=0;  if(s[i1]==t[i2])         count+=fun(s,t,i1+1,i2+1,dp);      count+=fun(s,t,i1+1,i2,dp);  
return dp[i1][i2]= count;       
}



//////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int numDistinct(string s, string t) {
//////////////////////////////////////////////////////////////////////////////////////////////////////

int n1=s.size();         int n2=t.size();
vector<vector<int>>dp(  n1,vector<int>(n2,-1)   );
return fun(s,t,0,0,dp);

//////////////////////////////////////////////////////////////////////////////////////////////////////   
    }
};
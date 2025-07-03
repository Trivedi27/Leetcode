class Solution {
public:
    int ct=0;
    void rec(int n,int k,string&ans,vector<char>&chck,string temp,map<char,int>&mpp){
        if(temp.size()==n){
            ct++;
            if(ct==k){
                ans=temp;
            }
            return;
        }
        if(ct>=k){
            return;
        }
        for(int i=0;i<n;i++){
            if(mpp[chck[i]]==0){
                mpp[chck[i]]=1;
                rec(n,k,ans,chck,temp+chck[i],mpp);
                mpp[chck[i]]=0;
            }
        }
    }
    string getPermutation(int n, int k) {
        string ans;
        vector<char>chck={'1','2','3','4','5','6','7','8','9'};
        map<char,int>mpp;
        rec(n,k,ans,chck,"",mpp);
        return ans;
    }
};
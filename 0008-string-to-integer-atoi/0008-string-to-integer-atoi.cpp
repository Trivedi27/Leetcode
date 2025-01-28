class Solution {
public:
    int myAtoi(string s) {
        int n = s.size(); int index=0;
        while(index<n && s[index]==' '){
            index++;
        }

        bool pos=true; int isfound=0;
        if(index<n && (s[index]=='+' || s[index]=='-')){
            pos=(s[index]=='+');
            index++;
        }

        long long result = 0;
        for(int i=index;i<n;i++){
            if(s[i]>='0' && s[i]<='9'){
                result = result*10 + (s[i]-'0');
                if(result>INT_MAX){
                    return pos?INT_MAX:INT_MIN;
                }
            }
            else break;
        }
        return pos?result:-result;
    }
};
class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26);
        for(char ch:word) freq[ch-'a']++;
        int res = INT_MAX;
        for(int i:freq){
            int curr = 0;
            for(int j:freq){
                if(j > i+k) curr += j - (i+k);
                else if(j < i) curr += j;
            }
            res = min(res, curr);
        }
        return res;
    }
};
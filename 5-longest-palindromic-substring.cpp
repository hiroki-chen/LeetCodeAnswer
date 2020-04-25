

class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.size();
        if(len==0||len==1)
            return s;
        int start=0;
        int end=0;
        int mlen=0;
        for(int i=0;i<len;i++){
            int len1=expendaroundcenter(s,i,i);
            int len2=expendaroundcenter(s,i,i+1);
            mlen=max(max(len1,len2),mlen);
            if(mlen>end-start+1){
                start=i-(mlen-1)/2;
                end=i+mlen/2;
            }
        }
        return s.substr(start,mlen);
    }
    int expendaroundcenter(string s, int l, int r){
        while(l >= 0 && s[l] == s[r] && r < s.size()){
            l--;
            r++;
        }
        return r-l-1;
    }
};
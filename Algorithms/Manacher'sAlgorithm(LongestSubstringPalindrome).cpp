class Solution {
public:    
    string longestPalindrome(string s) {
        
        string manacher_str  = "#";
        
        for(int i=0; i<s.size(); i++)
            manacher_str = manacher_str + s[i] + "#";
        
        int n = manacher_str.size();
        vector<int> plen(n,0);
        int pos = 0, maxRight = 0, maxLen = 0, maxLenPos = 0;
        
        for(int i=0; i<n; i++){
            
            if(i<maxRight)
                plen[i] = min(plen[2*pos-i], maxRight-i);
            else
                plen[i] = 1;
            while(i-plen[i] >= 0 && i+plen[i] < n && manacher_str[i+plen[i]] == manacher_str[i-plen[i]])
                plen[i]++;
            if(plen[i] > maxLen){
                maxLen = plen[i];
                maxLenPos = i;
            }
            
            if(i+plen[i] > maxRight){
                maxRight = i + plen[i];
                pos = i;
            }            
        }
        
        s="";
        
        for(int i=maxLenPos - maxLen +1; i < maxLenPos + maxLen -1; i++)
            if(manacher_str[i] != '#')
                s+= manacher_str[i];
        
        return s;
        
    }
};
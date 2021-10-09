class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> map;
        if(s=="") return 0;
        int count = 0;
        int ans = INT_MIN;
        for(int i = 0;i<s.length();i++){
            if(map.count(s[i])==0){
                count++;
                map[s[i]] = i;
            }
            else{
                if(i - map[s[i]]>count) count++;
                else count = i - map[s[i]];
                map[s[i]] = i;
            }
            ans = max(ans,count);
        }
        return ans;
    }
    
};

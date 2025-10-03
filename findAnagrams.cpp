class Solution {
public:
    bool allZero(vector<int>&counter){
        for(int &i:counter){
            if(i!=0){
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        vector<int>counter(26,0);
        for(int i=0;i<p.size();i++){
            counter[p[i]-'a']++;
        }
        int i=0;
        int j=0;
        vector<int>result;
        while(j<n){
            counter[s[j]-'a']--;
            if((j-i+1)==p.size()){
                if(allZero(counter)){
                    result.push_back(i);
                }
                counter[s[i]-'a']++;
                i++;
            }
            j++;
        }
        return result;
    }
};

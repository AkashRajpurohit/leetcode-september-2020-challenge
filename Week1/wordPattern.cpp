class Solution {
private:
    vector<string> split(string str) {
        vector<string> result;
        string s = "";
        for(char c: str) {
            if(c == ' ') {
                result.push_back(s);
                s = "";
            } else {
                s += c;
            }
        }

        result.push_back(s);
        return result;
    }
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> m;
        vector<string> words = split(str);
        unordered_set<string> seenWords;
        
        if(pattern.size() != words.size()) return false;
        
        int n = pattern.size();
        
        for(int i = 0; i < n; ++i) {
            char currentPattern = pattern[i];
            string currentWord = words[i];
            
            if(m.find(currentPattern) != m.end()) {
                if(m[currentPattern] != currentWord) return false;
            } else {
                if(seenWords.find(currentWord) != seenWords.end()) return false;
                
                m[currentPattern] = currentWord;
                seenWords.insert(currentWord);
            }
        }
        
        return true;
    }
};
class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        unordered_map<char, int> m;
        int bulls = 0, cows = 0;
        
        for(int i = 0; i < n; ++i) {
            if(secret[i] == guess[i]) bulls++;
            else m[secret[i]]++;
        }
        
        for(int i = 0; i < n; ++i) {
            if(m.find(guess[i]) != m.end() && m[guess[i]] > 0 && secret[i] != guess[i]) {
                cows++;
                m[guess[i]]--;
            }
        }
        
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
class Solution {
private:
    unordered_map<string, vector<pair<string, double>>> buildGraph(vector<vector<string>>& eq, vector<double>& values) {
        unordered_map<string, vector<pair<string, double>>> g;
        int n = values.size();
        
        for(int i = 0; i < n; ++i) {
            string src = eq.at(i).at(0);
            string dest = eq.at(i).at(1);
            
            if(g.find(src) == g.end()) 
                g[src] = vector<pair<string, double>>();
            if(g.find(dest) == g.end()) 
                g[dest] = vector<pair<string, double>>();
            
            g[src].push_back(make_pair(dest, values.at(i)));
            g[dest].push_back(make_pair(src, 1 / values.at(i)));
        }
        
        return g;
    }
    
    double dfs(string src, string dest, unordered_set<string>& visited, unordered_map<string, vector<pair<string, double>>> g) {
        
        if(g.find(src) == g.end() || g.find(dest) == g.end()) 
            return -1.0;
        if(src == dest)
            return 1.0;
        
        visited.insert(src);
        
        for(pair<string, double> ng: g[src]) {
            if(visited.find(ng.first) == visited.end()) {
                double ans = dfs(ng.first, dest, visited, g);
                
                if(ans != -1.0)
                    return ans * ng.second;
            }
        }
        
        return -1.0;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> g = buildGraph(equations, values);
        vector<double> result;
        unordered_set<string> s;
        
        for(vector<string> q: queries) {
            result.push_back(dfs(q.at(0), q.at(1), s, g));
            s.clear();
        }
        
        return result;
    }
};
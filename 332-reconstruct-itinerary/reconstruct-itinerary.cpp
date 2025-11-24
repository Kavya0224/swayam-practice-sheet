// class Solution {
// public:
//     vector<string> findItinerary(vector<vector<string>>& tickets) {
//         int n=tickets.size();
//         vector<bool> vis(n,false);
//         string arr="JFK";
//         vector<string> ans;
//         int v=0;
//         while(v!=n){
//             for(int i=0;i<n;i++){
//                 if(tickets[i][0]==arr && vis[i]==false && n==v+1){
                    
//                      ans.push_back(arr);
//                      ans.push_back(tickets[i][1]);
//                 vis[i]=true;
//                 v++;
                
//                 }
//                 else if(tickets[i][0]==arr && vis[i]==false){
//                 ans.push_back(arr);
//                 vis[i]=true;
//                 v++;
//                 arr=tickets[i][1];
//                 }
//             }
//         }
//         return ans;

//     }
// };
class Solution {
public:
    unordered_map<string, multiset<string>> g;
    vector<string> ans;

    void dfs(string u) {
        while (!g[u].empty()) {
            string v = *g[u].begin();
            g[u].erase(g[u].begin());
            dfs(v);
        }
        ans.push_back(u);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto &t : tickets) 
            g[t[0]].insert(t[1]);

        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

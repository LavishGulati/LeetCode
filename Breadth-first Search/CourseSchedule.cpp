#define pb push_back

class Solution {
public:
    bool dfs(vector<int> *graph, int u, int mark, int *vis){
        vis[u] = 0;
        for(int v : graph[u]){
            if(vis[v] == 0){
                return false;
            }
            else if(vis[v] == -1){
                if(!dfs(graph, v, mark, vis)){
                    return false;
                }
            }
        }
        vis[u] = mark;
        return true;
    }

    bool canFinish(int n, vector<vector<int>>& prereq) {
        int m = prereq.size();
        vector<int> *graph = new vector<int>[n];
        int *vis = new int[n];
        for(int i = 0; i < n; i++){
            vis[i] = -1;
        }

        for(int i = 0; i < m; i++){
            graph[prereq[i][1]].pb(prereq[i][0]);
        }


        for(int i = 0; i < n; i++){
            if(vis[i] == -1){
                if(!dfs(graph, i, i+1, vis)){
                    return false;
                }
            }
        }

        return true;
    }
};

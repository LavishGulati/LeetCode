#define pb push_back
#define all(x) x.begin(), x.end()

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

    vector<int> findOrder(int n, vector<vector<int>>& prereq) {
        if(!canFinish(n, prereq)){
            vector<int> output;
            return output;
        }

        int m = prereq.size();
        int *numEdges = new int[n];
        vector<int> *graph = new vector<int>[n];
        vector<int> *revGraph = new vector<int>[n];

        for(int i = 0; i < n; i++){
            numEdges[i] = 0;
        }

        for(int i = 0; i < m; i++){
            numEdges[prereq[i][0]]++;
            graph[prereq[i][1]].pb(prereq[i][0]);
            revGraph[prereq[i][0]].pb(prereq[i][1]);
        }

        vector<int> output;
        bool *vis = new bool[n];
        for(int i = 0; i < n; i++){
            vis[i] = false;
        }

        queue<int> q;
        for(int i = 0; i < n; i++){
            if(numEdges[i] == 0){
                q.push(i);
                vis[i] = true;
                output.pb(i);
            }
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v : graph[u]){
                if(!vis[v]){
                    bool include = true;
                    for(int i : revGraph[v]){
                        if(!vis[i]){
                            include = false;
                            break;
                        }
                    }
                    if(include){
                        q.push(v);
                        vis[v] = true;
                        output.pb(v);
                    }
                }
            }
        }

        return output;
    }
};

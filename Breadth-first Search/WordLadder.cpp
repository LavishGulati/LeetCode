typedef pair<int, int> pii;
#define mp make_pair
#define f first
#define s second
#define pb push_back

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.pb(beginWord);
        int n = wordList.size();
        int m = wordList[0].size();
        if(n == 0){
            return 0;
        }

        bool find = false;
        for(int i = 0; i < n; i++){
            if(wordList[i] == endWord){
                find = true;
                break;
            }
        }
        if(!find){
            return 0;
        }

        vector<int> *graph = new vector<int>[n];
        int diff;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                diff = 0;
                for(int k = 0; k < m; k++){
                    if(wordList[i][k] != wordList[j][k]){
                        diff++;
                        if(diff == 2){
                            break;
                        }
                    }
                }
                if(diff == 1){
                    graph[i].pb(j);
                    graph[j].pb(i);
                }
            }
        }

        set<int> visited;
        queue<pii> q;
        q.push(mp(n-1, 0));
        visited.insert(n-1);
        while(!q.empty()){
            pii u = q.front();
            q.pop();
            if(wordList[u.f] == endWord){
                return u.s+1;
            }

            for(int v : graph[u.f]){
                if(visited.find(v) == visited.end()){
                    q.push(mp(v, u.s+1));
                    visited.insert(v);
                }
            }
        }

        return 0;
    }
};

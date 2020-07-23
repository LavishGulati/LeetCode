typedef pair<int, int> pii;
#define mp make_pair
#define f first
#define s second

class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pii> pq;
        int *freq = new int[26];
        int n = s.length();
        for(int i = 0; i < 26; i++){
            freq[i] = 0;
        }

        for(int i = 0; i < n; i++){
            freq[s[i]-'a']++;
        }

        for(int i = 0; i < 26; i++){
            if(freq[i] > 0){
                pq.push(mp(freq[i], i));
            }
        }

        string output = "";
        char c;
        pii p = pq.top(), p1;
        pq.pop();
        c = 'a'+p.s;
        output += c;
        if(p.f > 1){
            pq.push(mp(p.f-1, p.s));
        }

        while(!pq.empty()){
            p = pq.top();
            pq.pop();
            if(output.back()-'a' == p.s){
                if(!pq.empty()){
                    p1 = pq.top();
                    pq.pop();
                    c = 'a'+p1.s;
                    output += c;
                    if(p1.f > 1){
                        pq.push(mp(p1.f-1, p1.s));
                    }
                    pq.push(p);
                }
                else{
                    return "";
                }
            }
            else{
                c = 'a'+p.s;
                output += c;
                if(p.f > 1){
                    pq.push(mp(p.f-1, p.s));
                }
            }
        }
        return output;
    }
};

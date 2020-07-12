class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 1){
            return 1;
        }

        set<int> taken;
        priority_queue<int, vector<int>, greater<int> > pq;
        pq.push(2); taken.insert(2);
        pq.push(3); taken.insert(3);
        pq.push(5); taken.insert(5);
        for(int i = 0; i < n-2; i++){
            int x = pq.top();
            pq.pop();
            if(pq.size() <= n-2 && x <= INT_MAX/2 && taken.find(x*2) == taken.end()){
                pq.push(2*x);
                taken.insert(2*x);
            }
            if(pq.size() <= n-2 && x <= INT_MAX/3 && taken.find(x*3) == taken.end()){
                pq.push(3*x);
                taken.insert(3*x);
            }
            if(pq.size() <= n-2 && x <= INT_MAX/5 && taken.find(x*5) == taken.end()){
                pq.push(5*x);
                taken.insert(5*x);
            }
        }
        return pq.top();
    }
};

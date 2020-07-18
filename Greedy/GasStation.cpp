class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sum = gas[0]-cost[0];
        int i = 0, j = 1%n;
        while(i < n){
            while(sum >= 0 && j != i){
                sum += gas[j]-cost[j];
                j = (j+1)%n;
            }

            if(j == i && sum >= 0){
                return i;
            }
            else{
                sum -= gas[i]-cost[i];
                i++;
                if(i == j){
                    sum += gas[j]-cost[j];
                    j = (j+1)%n;
                }
            }
        }

        return -1;
    }
};

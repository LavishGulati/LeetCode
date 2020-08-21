#define pb push_back

class Solution {
public:
    vector<string> output;

    void solveMin(int id, int num, int x, int h){
        if(x > 59){
            return;
        }
        else if(num == 0){
            if(x < 10){
                output.pb(to_string(h)+":0"+to_string(x));
            }
            else{
                output.pb(to_string(h)+":"+to_string(x));
            }
            return;
        }
        else if(id == 6){
            return;
        }

        solveMin(id+1, num, x, h);
        x = (x|(1<<id));
        solveMin(id+1, num-1, x, h);
    }

    void solveHours(int id, int num, int x){
        if(x > 11){
            return;
        }
        else if(num == 0){
            output.pb(to_string(x)+":00");
            return;
        }
        else if(id == 4){
            solveMin(0, num, 0, x);
            return;
        }

        solveHours(id+1, num, x);
        x = x|(1<<id);
        solveHours(id+1, num-1, x);
    }

    vector<string> readBinaryWatch(int num) {
        output.clear();
        solveHours(0, num, 0);
        return output;
    }
};

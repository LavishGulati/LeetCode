class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int num = 0;
        int n = data.size(), x, d;
        for(int i = 0; i < n; i++){
            if(num <= 0){
                x = 0;
                for(d = 7; d >= 0; d--){
                    if(data[i]&(1<<d)){
                        x++;
                    }
                    else{
                        break;
                    }
                }
                if(d < 0 || x == 1 || x > 4){
                    return false;
                }
                num = x-1;
            }
            else{
                if(data[i]&(1<<7) && !(data[i]&(1<<6))){
                    num--;
                }
                else{
                    return false;
                }
            }
        }
        if(num > 0){
            return false;
        }
        return true;
    }
};

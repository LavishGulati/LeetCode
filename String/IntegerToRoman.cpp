class Solution {
public:
    string intToRoman(int num) {
        string output = "";

        if(num/1000 > 0){
            for(int i = 0; i < num/1000; i++){
                output += 'M';
            }
        }

        if((num/100)%10 == 9){
            output += "CM";
        }
        else if((num/100)%10 >= 5){
            output += 'D';
            for(int i = 0; i < ((num/100)%10) - 5; i++){
                output += 'C';
            }
        }
        else if((num/100)%10 == 4){
            output += "CD";
        }
        else if((num/100)%10 > 0){
            for(int i = 0; i < ((num/100)%10); i++){
                output += 'C';
            }
        }

        if((num/10)%10 == 9){
            output += "XC";
        }
        else if((num/10)%10 >= 5){
            output += 'L';
            for(int i = 0; i < ((num/10)%10) - 5; i++){
                output += 'X';
            }
        }
        else if((num/10)%10 == 4){
            output += "XL";
        }
        else if((num/10)%10 > 0){
            for(int i = 0; i < ((num/10)%10); i++){
                output += 'X';
            }
        }

        if((num)%10 == 9){
            output += "IX";
        }
        else if((num)%10 >= 5){
            output += 'V';
            for(int i = 0; i < ((num)%10) - 5; i++){
                output += 'I';
            }
        }
        else if((num)%10 == 4){
            output += "IV";
        }
        else if((num)%10 > 0){
            for(int i = 0; i < ((num)%10); i++){
                output += 'I';
            }
        }
        return output;
    }
};

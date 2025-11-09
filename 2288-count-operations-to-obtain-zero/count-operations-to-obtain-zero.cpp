class Solution {
public:
    int countOperations(int num1, int num2) {
        long long op = 0;
        if(num1 == 0 || num2 == 0){
            return 0;
        }
        while(num1 && num2 ){
            while(num1 >= num2){
                num1 = num1 - num2;
                op++;
            }
            if(num1 == 0 || num2  == 0){
                return op;
            }
            while(num2 >= num1){
                num2 = num2 - num1;
                op++;
            }
        }
        return (int)op;
    }
};
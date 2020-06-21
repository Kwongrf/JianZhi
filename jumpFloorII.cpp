class Solution {
public:
    int jumpFloorII(int number) {
        if(number == 0) return 0;
        return pow(2, number - 1);
        //return  1<<--number;//大神写法，移位比幂更快 
    }
};

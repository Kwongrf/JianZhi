class Solution {
public:
    int cutRope(int number) {
        if(number == 0) return 0;
        int max = 1;
        for(int m = 2; m <= number; m++)
        {
            int c = number % m;
            int p = number / m;
            int mul = 1;
            for(int i = 0;i < m;i++)
            {
                mul *=  p + (c > 0);
                c--;
            }
            if(mul > max)
                max = mul;
        }
        return max;
    }
};

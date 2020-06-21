class Solution {
public:
    int rectCover(int number) {
        if(number <= 0) return 0;
        int f = 1, g = 2;
        while(--number)
        {
            g += f;
            f = g - f;
        }
        return f;
    }
};

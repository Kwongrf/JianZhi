class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.empty()) return false;
        
        sort(numbers.begin(), numbers.end());
        int num = 0;
        int j,i;
        for(j = 0;j < numbers.size();j++)
        {
            if(numbers[j] == 0)
                num++;
            else 
            {
                if(j > 0 && numbers[j] == numbers[j-1])
                    return false;
            }
        }
        if(numbers[numbers.size()-1] - numbers[num] < 5)
            return true;
        else
            return false;
    }
};

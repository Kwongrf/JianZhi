class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.empty())
            return 0;
        int size = numbers.size();
        int max = 0;
        map<int, int> countMap;
        for(int i = 0; i < size;i++)
        {
            if(countMap.find(numbers[i])!=countMap.end())
                countMap[numbers[i]]++;
            else
                countMap[numbers[i]] = 1;
            
            if(countMap[numbers[i]] > max)
                 max = countMap[numbers[i]];
            if(max > size/2)
                 return numbers[i];
        }
        return 0;
    }
};

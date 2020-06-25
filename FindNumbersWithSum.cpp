class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int i, j;
        i = 0;
        j = array.size()-1;
        vector<int> result;
        if(array.size() <= 1) 
            return result;
        if(array[i] + array[i+1] > sum || array[j] + array[j-1]< sum)
            return result;
        
        while(i < j)
        {
            if(array[i] + array[j] > sum)
                j--;
            else if (array[i] + array[j] < sum)
                i++;
            else
            {
                result.push_back(array[i]);
                result.push_back(array[j]);
                return result;
            }
        }
        return result;
    }
};

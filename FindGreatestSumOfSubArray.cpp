class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.empty())
            return 0;
        
        int tmp = array[0];
        int result = array[0];
        
        for(int i = 1;i < array.size();i++)
        {
            if(array[i] > 0)
            {
                if(tmp <= 0)
                {
                    if(array[i] > result)
                    {
                        result = array[i];
                        tmp = result;
                    }
                    else
                        tmp = array[i];
                }    
                else
                {
                    if(array[i] + tmp > result)
                    {
                        result = array[i] + tmp;
                        tmp = result;
                    }
                    else
                        tmp += array[i];
                }    
                
            }
            else
            {
                if(array[i] > result)
                {
                    result = array[i];
                    tmp = array[i];
                }
                else
                    tmp += array[i];
            }
        }
        return result;
    }
};

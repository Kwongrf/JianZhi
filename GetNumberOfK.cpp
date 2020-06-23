class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.empty())
            return 0;
        
        int low = 0;
        int high = data.size();
        int mid = 0;
        while(low < high)
        {
            mid = (low + high) / 2;
            if(k > data[mid])
                low = mid + 1;
            else if(k < data[mid])
                high = mid;
            else
                break;
        }
        int count = 0;
        if(data[mid] == k)
            count += 1;
        else
            return 0;
        int i = mid - 1;
        int j = mid + 1;
        
        while(i >= 0) 
            if(data[i] == k)
            {
                count++;
                i--;
            }    
            else
                break;
        while(j < data.size()) 
            if(data[j] == k)
            {
                count++;
                j++;
            }    
            else
                break;
        return count;
    }
};

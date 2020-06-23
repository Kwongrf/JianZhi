#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int _minNumberInRotateArray(vector<int> rotateArray) {//这个写的有问题，但是通过了 
        if(rotateArray.empty())
            return 0;
        int low = 0;
        int high = rotateArray.size()-1;
        int min = rotateArray[0];
        int pre = -1;
        while(1)
        {
            
            while(rotateArray[low]>=rotateArray[high])
            {
                pre = low;
                low = (low + high) / 2;
                if(low == pre)
                    return rotateArray[high];
            }
            high = low;
            low = pre;
            if(high == low + 1)
                return rotateArray[high];
        }
    }
    int minNumberInRotateArray(vector<int> rotateArray) {
    	if(rotateArray.empty())
            return 0;
        int low = 0;
        int high = rotateArray.size()-1;
        int mid;
        while(low < high)
        {
        	mid = (low + high) / 2; 
        	
        	if(rotateArray[mid]>rotateArray[high])
        		low = mid + 1;
			else if(rotateArray[mid] == rotateArray[high])
				high = high -1;
			else
				high = mid;
			
		}
		return rotateArray[low];
	}
		 
};
int main()
{
	Solution s;
	int a[5] = {1,0,1,1,1};
	vector<int> arr(a, a+5);
	cout<<s.minNumberInRotateArray(arr);
}

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if(input.empty() || k == 0 || k > input.size()) return res;
        
        vector<int> arr(input);
        int len = arr.size();
        buildMinHeap(arr, len);
        res.push_back(arr[0]);
        int stop = len - k;
        for(int i = len - 1;i > stop;i-- )
        {
            swap(arr, 0, i);
            len--;
            heapify(arr, 0, len);
            res.push_back(arr[0]);
        }
        return res;
    }
    
    void buildMinHeap(vector<int>&arr, int len)
    {
        for(int i = (int)(len/2)-1;i >= 0;i--)
            heapify(arr, i, len);
    }
    void heapify(vector<int>& arr, int i, int len)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int minimal = i;
        
        if(left < len && arr[left] < arr[minimal])
            minimal = left;
        if(right < len && arr[right] < arr[minimal])
            minimal = right;
        if(minimal != i){
            swap(arr, i, minimal);
            heapify(arr, minimal, len);
        }
    }
    void swap(vector<int>& arr,int i,int j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
};
int main()
{
	Solution s;
	int a[8] = {4,5,1,6,2,7,3,8};
	vector<int> arr(a, a+8);
	vector<int>res = s.GetLeastNumbers_Solution(arr, 1);
	for(int i =0;i < res.size(); i++)
		cout<<res[i]<<" ";
}

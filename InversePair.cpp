#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& arr, int l, int mid, int r,int&ret)
{
	vector<int> tmp(r - l + 1);
	int i = l, j = mid + 1, k =0;
	while(i <= mid && j <= r)
	{
		if(arr[i] > arr[j])
		{
			tmp[k++] = arr[j++];
			
			ret += (mid - i + 1);
			ret%=1000000007;
		}
		else
		{
			tmp[k++] = arr[i++];	
		}
	}
	while(i <= mid)
	{
		tmp[k++] = arr[i++];
	}
	while(j <= r)
	{
			tmp[k++] = arr[j++];	
	}
	for(int m = 0;m < k;m++)
		arr[l + m] = tmp[m];
}
void show(vector<int>arr)
{
	for(int i = 0;i < arr.size();i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
void merge_sort(vector<int>& arr, int l, int r, int& ret)
{
	if(l >= r)
		return;
	int mid = l + ((r - l) >> 1);//移位运算法优先级低于+ 
//	cout<<"mid "<<mid<<" r "<<r<<" l "<<l<<endl;
	merge_sort(arr, l, mid, ret);
	merge_sort(arr, mid + 1, r, ret);
	merge(arr, l, mid, r, ret);
	show(arr);
	cout<<ret<<endl;
//	cout<<l<<"-"<<mid<<"-"<<r<<endl;
	
}

int main()
{
	int a[8] = {2,1,4,3,5,6,8,7};
	vector<int> arr(a, a+8);
	int ret = 0;
	merge_sort(arr, 0, arr.size()-1,ret);
	cout<<ret<<endl;
}

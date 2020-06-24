#include<iostream>
using namespace std;

int main()
{
	int n = -1;
	int count = 0;
	if(n < 0)
	{
		count++; 
		n = n & 0x7fffffff;
//		n = (~(-1*n) + 1) & 0x7fffffff;
	}	
	cout<<n<<endl;	
	
	while(n)
	{
		cout<<(n & 1)<<endl;
		count += (n & 1);
		n = n>>1;
//		cout<<n<<endl;
	}
	cout<<count<<endl;
}

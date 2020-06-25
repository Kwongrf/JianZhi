#include<iostream>
#include<cmath>
#include<string>
using namespace std;

int NumberOf1Between1AndN_Solution(int n)
{
	int count = 0;
	int t = 0;
	int num = n;
	while(n)
	{
		int c = n % 10;
		n /= 10;
		if(n!=0)//
		{
			count += ( n + (c > 1) ) * pow(10, t);
			if(c == 1)
			{
				count += num - n * pow(10,t+1) - c * pow(10,t) + 1;
			} 
		}
		else
		{
			if(c > 1)
				count += pow(10, t);
			else
			{
				
				count += num - pow(10, t) + 1;
			}
		}
		t++;
		cout<<count<<" "<<t<<" "<<n<<endl;
	}	
	return count;
}	

int main()
{
	cout<<NumberOf1Between1AndN_Solution(21345); 
}

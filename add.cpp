#include<iostream>
using namespace std;
class Solution {
public:
    int Add(int num1, int num2)
    {
        int c = num1 & num2;
        int sum = num1 ^ num2;
        while(c)
        {
            c = c<<1;
            int tmp = sum & c;
            sum = sum ^ c;
            c = tmp;
        }
        return sum;
    }
};
int main()
{
	int n1 = 0;
	int n2 = 1;
	int c = n1 & n2;
	int sum = n1 ^ n2;
	while(c)
	{	
		c = c<<1;
		int tmp = sum & c;	
		sum = sum ^ c;	
		c = tmp;
	}
	cout<<sum;
//	cout<<n1 | n2<<endl;
//	cout<<n1 ^ n2<<endl;
//	cout<<n3;
}

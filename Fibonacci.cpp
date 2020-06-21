#include<iostream>
using namespace std;
int Fibonacci(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        
        int tmpN, tmpN_1 = 1, tmpN_2 = 0;
        for(int i = 2;i <= n; i++)
        {
            tmpN = tmpN_1 + tmpN_2;
            tmpN_2 = tmpN_1;
            tmpN_1 = tmpN;
            
        }
        return tmpN;
        
        int f = 0, g = 1;
        while(n--)
        {
        	g += f;
			f = g - f; 
		}
		return f;
	}		
int main()
{
	cout<<Fibonacci(4); 
}

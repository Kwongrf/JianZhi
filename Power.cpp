#include<iostream>
using namespace std;
    double Power(double base, int exponent) {
        if(base == 0) return 0;
        if(exponent == 0) return 1;
        double pow = 1.0;
        int e = abs(exponent);
        cout<<e<<endl; 
        if(e)
        {
            e/=2;
            double tmp = Power(base, e);
            pow = tmp*tmp;
        }
        if(abs(exponent) % 2 == 1)
            pow *= base;
        if(exponent < 0)
            pow = 1.0/pow;
        return pow;
    }
		
int main()
{
	cout<<Power(2,-3);
}

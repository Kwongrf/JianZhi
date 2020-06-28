#include<iostream>
#include<cmath>
#include<map>
using namespace std;
 
#include<unordered_map>
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index == 1) return 1;
        int x = 0, y = 0, z = 0;
        int a[100000] = {0};
        a[0] = 1;
        int count = 1;
        while(count < index)
        {
        	if(a[x]*2 < a[y]*3 && a[x]*2 < a[z]*5)
        	{
        		a[count] = a[x]*2;
        		x++;
        		count++;
			}
			else if(a[y]*3 < a[x]*2 && a[y]*3 < a[z]*5)
			{
				a[count] = a[y]*3;
				y++;
				count++;
			}
			else if(a[z]*5 < a[x]*2 && a[z]*5 < a[y]*3)
			{
				a[count] = a[z]*5;
				z++;
				count++;
			}
			else if(a[y]*3 == a[x]*2 && a[x]*2 != a[z]*5)
			{
				a[count] = a[y]*3;
				y++;
				x++;
				count++;
			}
			else if(a[y]*3 == a[z]*5 && a[y]*3 != a[x]*2)
			{
				a[count] = a[y]*3;
				y++;
				z++;
				count++;
			}
			else if(a[z]*5 == a[x]*2 && a[z]*5 != a[y]*3)
			{
				a[count] = a[z]*5;
				z++;
				x++;
				count++;
			}
			else
			{
				a[count] = a[z]*5;
				z++;
				x++;
				y++;
				count++;
				cout<<"!!!"<<endl;
				}	
		}
        return a[count-1];
    }
    
};
int main()
{
	Solution s;
	cout<<s.GetUglyNumber_Solution(1000);
	
}

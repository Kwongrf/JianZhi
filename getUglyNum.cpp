#include<iostream>
#include<cmath>
#include<map>
using namespace std;
 
#include<unordered_map>
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index == 1) return 1;
        
        int count = 1;
        int num = 2;
        int tmp = num;
        unordered_map<int, bool> ugly;
        int prime[3] = {2,3,5};
        while(count < index)
        {
            int k;
            for(k = 0;k < 3;k++)
            {
                    
                if(tmp % prime[k] == 0)
                {
                	
                    tmp /= prime[k];
                    if(tmp == 1)
                    {
                    	count++;
                        ugly[num] = true;
                        num++;
                    	tmp = num;
					}
                    else if(ugly.find(tmp)!=ugly.end())
                    {
                    	if(ugly[tmp])
                    	{
                    		count++;
                        	ugly[num] = true;
						}
                        else
                        {
                        	ugly[num] = false;
						}
                        num++;
                    	tmp = num;
                    } 
					
                    break;
                }    
            }
            if(k == 3)
            {
            	ugly[num] = false;
				num++;
				tmp = num; 
            }
            
        }
        return num - 1;
    }
};
int main()
{
	Solution s;
	cout<<s.GetUglyNumber_Solution(1000);
	
}

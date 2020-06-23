#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if(length == 0)
            return false;
        bool* got = new bool[length];
        for(int i = 0 ;i < length;i++) got[i]= false;
        for(int i = 0 ;i < length;i++)
        {
            if(got[numbers[i]])
            {
                *duplication = numbers[i];
//                cout<<*duplication<<endl;
                return true;
            }    
            else
                got[numbers[i]] = true;
        }
        return false;
    }
};
int main()
{
	int a[5]={2,1,3,1,4};
	vector<int> n(a, a+5);
	Solution s;
	int c = -1;
	int* d = &c;
	cout<<s.duplicate(a,5,d);
	cout<<*d; 
	
}

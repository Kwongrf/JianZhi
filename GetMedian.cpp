#include<iostream>
#include<queue>
#include<stack>
using namespace std;
class Solution {
public:
    priority_queue<int,vector<int>,greater<int> >Q;
    void Insert(int num)
    {
        Q.push(num);
    }

    double GetMedian()
    { 
        stack<int>s;
        int size;
        if(Q.size()%2 == 0)
        {
            size =  Q.size();
            for(int i = 0;i < size/2-1;i++)
            {
                s.push(Q.top());
                Q.pop();
            } 
            
            int a1 = Q.top();
            s.push(Q.top());
            Q.pop();
            int a2 = Q.top();
            
            while(!s.empty())
            {
                Q.push(s.top());
                s.pop();
            }    
            return ((double)a1 + (double)a2) / 2;
        }
        else
        {
        	size = Q.size();
            for(int i = 0;i < size/2;i++) 
            {
                s.push(Q.top());
                Q.pop();
            }
            int a = Q.top();
            while(!s.empty())
            {
                Q.push(s.top());
                s.pop();
            } 
            return (double)a;
        }
        return -1.0;
    }
    void show()
    {
    	stack<int>s;
    	while(!Q.empty())
    	{
    		cout<<Q.top()<<" ";
    		s.push(Q.top());
    		Q.pop();
		}
		cout<<endl<<endl;
		while(!s.empty())
        {
                Q.push(s.top());
                s.pop();
        }
	}

};

int main()
{
	Solution so;
	so.Insert(5);
	cout<<so.GetMedian()<<endl;
	so.show();
	so.Insert(2);
	cout<<so.GetMedian()<<endl;
	so.show();
	so.Insert(3);
	cout<<so.GetMedian()<<endl;
	so.show();
	so.Insert(4);
	cout<<so.GetMedian()<<endl;
	so.show();
	so.Insert(1);
	cout<<so.GetMedian()<<endl;
	so.show();
	so.Insert(6);
	cout<<so.GetMedian()<<endl;
	so.show();
	so.Insert(7);
	cout<<so.GetMedian()<<endl;
	so.show();
	so.Insert(0);
	cout<<so.GetMedian()<<endl;
	so.show();
	so.Insert(8);
	cout<<so.GetMedian()<<endl;
	so.show();
}

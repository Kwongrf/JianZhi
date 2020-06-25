#include<iostream>
using namespace std;
class Solution {
public:
    struct LinkNode{
        int index;
        struct LinkNode* next;
        LinkNode(int i):
            index(i),next(NULL){}
    };
    
    int LastRemaining_Solution(int n, int m)
    {
        if(n <= 0 || m <=0) return -1;
        LinkNode* head;
        LinkNode* lastNode;
        for(int i = 0;i < n;i++)
        {
            LinkNode* kid = new LinkNode(i);
            if(i == 0)
                head = kid;
            else
                lastNode->next = kid;
            lastNode = kid;
        }
        lastNode->next = head;
        while(head->next!=head)
        {
            int i = 0;
            while(i!=m-1)
            {
                lastNode = head;
                head = head->next;
                i++;
            }
            lastNode->next = head->next;
            LinkNode* tmp = head;
            head = head->next;
            cout<<tmp->index<<endl;
            delete tmp;
        }
        return head->index;
    }
};
int main()
{
	Solution s;
	cout<<s.LastRemaining_Solution(7,3);
}

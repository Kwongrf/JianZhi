/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(k < 0)
            return NULL;
        vector<ListNode*>list;
        while(pListHead)
        {
            list.push_back(pListHead);
            pListHead = pListHead->next;
        }
        int n = list.size();
        if(k > n)
            return NULL;
        return list[n-k];
    }
    
};

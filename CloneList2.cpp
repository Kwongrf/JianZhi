/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        map<RandomListNode*, RandomListNode*> nodeMap;
        RandomListNode* newList = NULL;
        RandomListNode* lastNode = NULL;
        RandomListNode* curNode = NULL;
        RandomListNode* current = pHead;
        
        while(current)
        {
            if(nodeMap.find(current) == nodeMap.end())
            {    
                RandomListNode node = RandomListNode(current->label);
                nodeMap[current] = &node;
                curNode = &node;
            }
            else
                curNode = nodeMap[current];
            
            if(lastNode != NULL)
                lastNode->next = curNode;
            
            lastNode = curNode;
            if(newList == NULL)
                newList = curNode;
            
            if(current->random)
            {
                if(nodeMap.find(current->random) == nodeMap.end())
                {    
                    RandomListNode node = RandomListNode(current->random->label);
                    nodeMap[current->random] = &node;
                    curNode->random = &node;
                }
                else
                    curNode->random = nodeMap[current->random];
            }
            else
                curNode->random = NULL;
            
            current = current->next;
        }
        return newList;
        
    }
};

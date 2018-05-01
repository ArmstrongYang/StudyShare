#include <iostream>
#include <vector>

using namespace std;


struct ListNode{
    int val;
    struct ListNode* next;
    ListNode(int x):
        val(x), next(NULL) {}
};

class Solution 
{
    public:

    vector<int> printListFromTailToHead(struct ListNode *head)
    {
        struct ListNode *p = Head;
        vector<int> v;

        while(p!=NULL)
        {
            v.push_back(p->val);
            p = p->next;
        }
        return vector<int>(v.rbegin(), v.rend();)
    }
}
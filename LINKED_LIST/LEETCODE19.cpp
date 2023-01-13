// https://leetcode.com/problems/remove-nth-node-from-end-of-list/?envType=study-plan&id=level-2

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        if (!head->next)
        {
            return nullptr;
        }

        ListNode NewHead(0);
        NewHead.next = head;

        ListNode *Left = &NewHead;
        ListNode *Right = &NewHead;

        for (int i = 0; i < n; i++)
        {
            Right = Right->next;
        }

        while (Right->next)
        {
            Right = Right->next;
            Left = Left->next;
        }

        // ListNode* tobeDeleted = Left->next;
        Left->next = Left->next->next;

        // delete tobeDeleted;

        return NewHead.next;
    }
};
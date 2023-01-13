// https://leetcode.com/problems/odd-even-linked-list/description/?envType=study-plan&id=level-2

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
    ListNode *oddEvenList(ListNode *head)
    {

        if (!head)
            return head;

        ListNode *Left = head;
        ListNode *Right = (head->next);
        ListNode *EvenHead = (Right);

        while (Right && Right->next)
        {
            Left->next = Left->next->next;
            Right->next = Right->next->next;

            Left = Left->next;
            Right = Right->next;
        }

        Left->next = EvenHead;

        return head;

        // return head;
    }
};
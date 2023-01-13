// https://leetcode.com/problems/palindrome-linked-list/?envType=study-plan&id=level-2

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
    bool isPalindrome(ListNode *head)
    {
        vector<int> pal;
        ListNode *newNode = head;

        while (newNode->next)
        {
            pal.push_back(newNode->val);
            newNode = newNode->next;
        }

        pal.push_back(newNode->val);

        for (int i = 0; i < pal.size(); i++)
        {
            int cmp = pal[pal.size() - i - 1];
            if (pal[i] != cmp)
                return false;
        }

        return true;
    }
};
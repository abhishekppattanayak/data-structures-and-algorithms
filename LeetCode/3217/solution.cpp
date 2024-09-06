// LeetCode 3217. Delete Nodes From Linked List Present in Array

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // time complexity : O(n)
        // space complexity : O(n)

        unordered_map<int, bool> m;
        for (int& i : nums)
            m[i] = true;

        ListNode* ans = new ListNode(0, head);
        for (ListNode* it = ans; it->next;)
            if (m[it->next->val])
                it->next = it->next->next;
            else
                it = it->next;
        
        return ans->next;
    }
};
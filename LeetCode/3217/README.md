# 3217. Delete Nodes From Linked List Present in Array

You can find the original problem statement [here](https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/).

## Description

The premise of the problem statement is simply, to delete nodes with some values from the given linked list. The values are listed in `nums`.

Given inputs,
  1. array `nums`
  2. listnode `head`

So, let's build the solution.

## Walkthrough

**Step 1**
Store values in `nums` in a data structure with `constant` lookup time. I'm going to use a hashmap data structure.

```cpp
unordered_map<int, bool> m;
for (int &i: nums)
  m[i] = true;
```

**Step 2**
Now we iterate through the linked list, and if the value is present in map `m` we set the next pointer to be next's next pointer.

```cpp
ListNode* ans = new ListNode(0, head);
for (ListNode* it=head; it->next; )
  if (m[it->val])
    it->next = it->next->next;
  else
    it = it->next;
```

**Step 3**
Return the head of the modified linkedlist.

```cpp
return ans->next;
```

## [🔗Solution File](solution.cpp)
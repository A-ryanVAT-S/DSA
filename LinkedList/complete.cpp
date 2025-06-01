#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// 1. Reverse a Linked List
// Time: O(n), Space: O(1)
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// 2. Detect a Cycle in a Linked List
// Time: O(n), Space: O(1)
bool hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

// 3. Merge Two Sorted Linked Lists
// Time: O(n + m), Space: O(1)
Node* mergeTwoLists(Node* l1, Node* l2) {
    Node* dummy = new Node(0);
    Node* tail = dummy;
    while (l1 && l2) {
        if (l1->data < l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = (l1) ? l1 : l2;
    return dummy->next;
}

// 4. Remove N-th Node From End of List
// Time: O(n), Space: O(1)
Node* removeNthFromEnd(Node* head, int n) {
    Node* dummy = new Node(0);
    dummy->next = head;
    Node* fast = dummy;
    Node* slow = dummy;
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return dummy->next;
}

// 5. Flatten a Linked List with child and next pointers
class NodeWithChild {
public:
    int data;
    NodeWithChild* next;
    NodeWithChild* child;

    NodeWithChild(int val) : data(val), next(nullptr), child(nullptr) {}
};

// Modified merge for NodeWithChild using child pointers
NodeWithChild* mergeChildLists(NodeWithChild* a, NodeWithChild* b) {
    NodeWithChild* dummy = new NodeWithChild(0);
    NodeWithChild* curr = dummy;
    while (a && b) {
        if (a->data < b->data) {
            curr->child = a;
            a = a->child;
        } else {
            curr->child = b;
            b = b->child;
        }
        curr = curr->child;
    }
    curr->child = a ? a : b;
    return dummy->child;
}

// Time: O(n * m), Space: O(1)
NodeWithChild* flatten(NodeWithChild* root) {
    if (!root || !root->next) return root;
    NodeWithChild* curr = root;
    while (curr->next) {
        curr = mergeChildLists(curr, curr->next);
        curr->next = curr->next->next;
    }
    return curr;
}

// 6. Add Two Numbers Represented by Linked Lists
// Time: O(max(n, m)), Space: O(max(n, m))
Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* dummy = new Node(0);
    Node* curr = dummy;
    int carry = 0;
    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) sum += l1->data, l1 = l1->next;
        if (l2) sum += l2->data, l2 = l2->next;
        carry = sum / 10;
        curr->next = new Node(sum % 10);
        curr = curr->next;
    }
    return dummy->next;
}

// 7. Intersection of Two Linked Lists
// Time: O(n + m), Space: O(1)
Node* getIntersectionNode(Node* headA, Node* headB) {
    if (!headA || !headB) return nullptr;
    Node* a = headA;
    Node* b = headB;
    while (a != b) {
        a = a ? a->next : headB;
        b = b ? b->next : headA;
    }
    return a;
}

// 8. Reverse Nodes in k-Group
// Time: O(n), Space: O(n/k) recursion stack (worst O(n) if k = 1)
Node* reverseKGroup(Node* head, int k) {
    Node* curr = head;
    int count = 0;

    // Check if we have at least k nodes
    while (curr && count < k) {
        curr = curr->next;
        count++;
    }

    if (count == k) {
        // Reverse first k nodes
        Node* prev = reverseKGroup(curr, k); // reverse rest recursively
        curr = head;
        while (count--) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    return head;
}

// 9. Check if a Linked List is a Palindrome
// Time: O(N), Space: O(1)
bool isPalindrome(Node* head) {
    if (!head || !head->next) return true;

    // Find middle
    Node* slow = head;
    Node* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    Node* second = reverseList(slow->next);
    Node* first = head;

    // Compare halves
    Node* copySecond = second;
    while (second) {
        if (first->data != second->data) return false;
        first = first->next;
        second = second->next;
    }

    // Optional: Restore list using reverseList(copySecond);
    return true;
}

// 10. Copy List with Random Pointer
class RandomNode {
public:
    int data;
    RandomNode* next;
    RandomNode* random;

    RandomNode(int val) : data(val), next(nullptr), random(nullptr) {}
};

RandomNode* copyRandomList(RandomNode* head) {
    if (!head) return nullptr;

    unordered_map<RandomNode*, RandomNode*> mp;

    RandomNode* curr = head;
    while (curr) {
        mp[curr] = new RandomNode(curr->data);
        curr = curr->next;
    }

    curr = head;
    while (curr) {
        mp[curr]->next = mp[curr->next];
        mp[curr]->random = mp[curr->random];
        curr = curr->next;
    }

    return mp[head];
}
// Time: O(N), Space: O(N)

//for constant space solution, we can use the next pointer to create a copy of each node right after the original node, then set the random pointers, and finally separate the two lists.
// This approach uses O(1) space but modifies the original list, so it may not be suitable for all use cases.
//but at last we can restore the original list by separating the two lists.
// Time: O(N), Space: O(1) (in-place modification)

RandomNode* copyRandomListConstantSpace(RandomNode* head) {
    if (!head) return nullptr;

    RandomNode* curr = head;
    // Step 1: Create a copy of each node and insert it after the original node
    while (curr) {
        RandomNode* copy = new RandomNode(curr->data);
        copy->next = curr->next;
        curr->next = copy;
        curr = copy->next;
    }

    // Step 2: Set the random pointers for the copied nodes
    curr = head;
    while (curr) {
        if (curr->random) {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }

    // Step 3: Separate the two lists
    curr = head;
    RandomNode* newHead = head->next;
    RandomNode* copyCurr = newHead;

    while (curr) {
        curr->next = copyCurr->next; // restore original list
        curr = curr->next;
        if (copyCurr->next) {
            copyCurr->next = copyCurr->next->next; // move to next copied node
        }
        copyCurr = copyCurr->next;
    }

    return newHead; // return the head of the copied list
}
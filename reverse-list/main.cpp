#include <iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        if(head==NULL){
            return head;
        } 

        cout << "next: " << next << endl;
        cout << "curr: " << curr->val << ", " << curr << ", pointing at: " << curr->next << endl;
        cout << "prev: " << prev << endl;
        cout << "---" << endl;
            
        while(curr) {
            if (curr) {cout << "curr: " << curr->val << ", " << curr << ", pointing at: " << curr->next << endl;}

            next = curr->next;
            cout << "set next to: " << next << endl;

            curr->next = prev;
            if (curr) {cout << "set curr->next to: " << prev << " from: " << next << endl;}

            prev = curr;
            cout << "set prev to: " << curr << endl;

            curr = next;
            if (curr) {cout << "curr: " << curr->val << ", " << curr << ", pointing at: " << curr->next << endl;}
            

            cout << "---" << endl;

        }
        return prev;
    }
};
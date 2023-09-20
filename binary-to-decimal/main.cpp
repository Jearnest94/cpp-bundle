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
    int getDecimalValue(ListNode* head) {
      string numbers_in_binary;
      ListNode* curr = head;

      while (curr) {
        string stri  = to_string(curr->val);
        numbers_in_binary = numbers_in_binary+stri;
        curr = curr->next;
        cout << numbers_in_binary << endl;
      }
      
      int decimal = stoi(numbers_in_binary, 0, 2);

      return decimal;
        
    }
};
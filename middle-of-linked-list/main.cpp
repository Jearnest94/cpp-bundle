#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        int number_of_items = 1;
        int half_of_total_items = 0;
        ListNode *current_node;

        if (head->next != nullptr)
        {
            number_of_items += 1;
            current_node = head->next;
        }
        else
        {
            return head;
        }

        while (current_node->next != nullptr)
        {
            number_of_items += 1;
            current_node = current_node->next;
        }

        half_of_total_items = number_of_items / 2 + 1;

        int counter = 1;
        ListNode *node_in_the_middle;
        ListNode *cur_node;
        cur_node = head->next;

        while (counter != half_of_total_items)
        {
            node_in_the_middle = cur_node;
            counter++;
            cur_node = cur_node->next;
        }

        return node_in_the_middle;
    }
};
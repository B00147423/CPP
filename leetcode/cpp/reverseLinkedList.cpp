#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int numberReturnList(ListNode *list) {
  ListNode *curr = list;
  int number = 0;
  while (curr != nullptr) {
    number = number * 10 + curr->val;
    curr = curr->next;
  }

  return number;
}

int reverseList(ListNode *list) {
  int number = numberReturnList(list); // Get the number from the list

  int reversedNumber = 0;

  // Reverse the number
  while (number != 0) {
    reversedNumber = reversedNumber * 10 + number % 10;
    number /= 10;
  }

  return reversedNumber;
}
int main() {
  // Create a linked list 1 -> 2 -> 3 -> 4
  ListNode *list = new ListNode(1);
  list->next = new ListNode(2);
  list->next->next = new ListNode(3);
  list->next->next->next = new ListNode(4);

  // Example usage:
  int originalNumber = numberReturnList(list);
  int reversedNumber = reverseList(list);

  cout << "Number from list: " << originalNumber << endl;
  cout << "Reversed number: " << reversedNumber << endl;
  return 0;
}

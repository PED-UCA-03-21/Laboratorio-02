#include <iostream>
#include <string>

using namespace std;

struct Node {
  int value;
  Node *next;
};

class SimpleList {
  private:
    Node *head;
    
    int _sum(Node *p) {
      if (!p) return 0;
      return p->value + _sum(p->next);
    }

  public:
    SimpleList();
    int sum();
    void insert(int value);
    void printData();
    void concatList(SimpleList l);
    void inverted(Node *p, SimpleList newList);
    string toString();
    Node *getLastNode(Node *p);
    Node *getHead();
};

SimpleList::SimpleList() {
  //Set head pointer to null -> Can be 0
  head = NULL;
}

Node *SimpleList::getLastNode(Node *p) {
  if(!p) return NULL;

  if(!p->next) {
    return p;
  }else {
    getLastNode(p->next);
  }
}

Node *SimpleList::getHead() {
  return head;
}

void SimpleList::insert(int value) {
  Node *newNode = new Node;
  newNode->value = value;
  newNode->next = NULL;

  if(!head) {
    head = newNode;
  } else {
    Node *n = head;

    while (n->next) {
      n = n->next;
    }
    
    n->next = newNode;
  }
}

void SimpleList::printData() {
  Node *n = head;

  cout << "Printing List Data" << endl;

  while(n) {
    cout << n->value << " ";
    n = n->next;
  }

  cout << endl;
}

string SimpleList::toString() {
  Node *n = head;

  if(!n) return "";

  string result = "Data [ " + n->value;
  n = n->next;

  while (n) {
    result += " -> " + n->value;
    n = n->next;
  }

  result += " ]";

  return result;
}

int SimpleList::sum() {
  /* Node *n = head;

  if (!n) return 0;

  int sum = 0;

  while (n) {
    sum += n->value;
    n = n->next;
  }

  return sum; */

  return _sum(head);
}

void SimpleList::concatList(SimpleList l) {
  Node *lastOwnNode = getLastNode(head);
  Node *headSecondList = l.getHead();

  if(!lastOwnNode) {
    head = headSecondList;
  } else {
    lastOwnNode->next = headSecondList;
  }
}

void SimpleList::inverted(Node* listNode, SimpleList newList) {
  if(!listNode) return;

  if(listNode->next) {
    inverted(listNode->next, newList);
  }
   
  newList.insert(listNode->value);
}

int main() {



  return 0;
}
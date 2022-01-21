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

    Node *_getLastNode(Node *p) {
      if(!p) return NULL;

      if(!p->next) {
        return p;
      }else {
        return _getLastNode(p->next);
      }
    }

    void _inverted(Node *listNode, SimpleList *newList) {
      if(!listNode) return;

      if(listNode->next) {
        _inverted(listNode->next, newList);
      }
      
      newList->insert(listNode->value);
    }

  public:
    SimpleList();
    int sum();
    void insert(int value);
    void printData();
    void concatList(SimpleList l);
    SimpleList inverted();
    string toString();
    Node *getLastNode();
    Node *getHead();
};

SimpleList::SimpleList() {
  //Set head pointer to null -> Can be 0
  head = NULL;
}

Node *SimpleList::getLastNode() {
  return _getLastNode(head);
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

  string result = "Data [ " + to_string(n->value);
  n = n->next;

  while (n) {
    result = result + " -> " + to_string(n->value);
    n = n->next;
  }

  result = result + " ]";

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
  Node *lastOwnNode = getLastNode();
  Node *headSecondList = l.getHead();

  if(!lastOwnNode) {
    head = headSecondList;
  } else {
    lastOwnNode->next = headSecondList;
  }
}

SimpleList SimpleList::inverted() {
  SimpleList invertedList = SimpleList();

  _inverted(head, &invertedList);
  return invertedList;
}

int main() {

  SimpleList l1 = SimpleList();
  SimpleList l2 = SimpleList();

  cout << "INGRESE LOS VALORES DE LA LISTA 1" << endl;

  int dato;

  while(cin >> dato) {
    l1.insert(dato);
  }

  l1.printData();

  string listString = l1.toString();
  cout << listString << endl;

  int listSum = l1.sum();
  cout << "La Suma de todos los valores es: " << listSum << endl;

  cout << "INGRESE LOS VALORES DE LA LISTA 2" << endl;

  for(int i=0; i < 10; i++) {
    l2.insert(i);
  }

  l2.printData(); 

  cout << "Concatenando..." << endl;

  l1.concatList(l2);

  cout << "Lista 1: ";
  l1.printData();

  cout << "Invirtiendo las listas" << endl;

  SimpleList invL1 = l1.inverted();
  SimpleList invL2 = l2.inverted();

  cout << "L1: " << invL1.toString() << endl;
  cout << "L2: " << invL2.toString() << endl;

  return 0;
}
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

    Node *_getTail(Node *p) {
      if(!p)  return NULL;

      if(!p->next) {
        return p;
      }else {
        return _getTail(p->next);
      }
    }

    void _inverted(Node *p, SimpleList *nl) {
      if(!p) return;

      if(p->next) {
        _inverted(p->next, nl);
      }

      nl->insert(p->value);
    }

  public:
    SimpleList();
    void insert(int value);
    void printData();
    void concat(SimpleList toConcat);
    int sum();
    string toString();
    Node *getHead();
    Node *getTail();
    SimpleList inverted();
};

SimpleList::SimpleList() {
  head = NULL;
}

Node *SimpleList::getHead() {
  return head;
}

Node *SimpleList::getTail() {
  return _getTail(head);
}

void SimpleList::insert(int value) {
  Node *newNode = new Node;
  newNode->value = value;
  newNode->next = NULL;

  if(!head) {
    head = newNode;
  } else {
    Node *n = getTail();

    //Estoy seguro que n es el ultimo elemento
    n->next = newNode;
  }
}

void SimpleList::printData() {
  Node *n = head;

  cout << "Monstrando datos de la lista: ";

  while(n) {
    cout << n->value << " ";
    n = n->next;
  } 

  cout << endl;
}

string SimpleList::toString() {
  string result = "Data [";

  Node *n = head;
  while(n) {
    result = result + "-> " + to_string(n->value); 
    n = n->next;
  }

  result = result + " ]";
  return result;
}

int SimpleList::sum() {
  return _sum(head);
}

void SimpleList::concat(SimpleList toConcat) {
  Node *ownTail = getTail();
  Node *toConcatHead = toConcat.getHead();

  if(!ownTail) {
    head = toConcatHead;
  } else {
    ownTail->next = toConcatHead;
  }
}

SimpleList SimpleList::inverted() {
  SimpleList result = SimpleList();

  _inverted(head, &result);

  return result;
}


int main() {
  SimpleList l1 = SimpleList();
  SimpleList l2 = SimpleList();

  int data;

  cout << "Ingrese los valores L1" << endl;
  while (cin >> data) {
    l1.insert(data);
  }

  cout << "------ Lista 1 ------" << endl;
  l1.printData();

  cout << "L1: " << l1.toString() << endl;

  cout << "La suma de l1 es: " << l1.sum() << endl <<endl;

  cout << "------ Lista 2 ------" << endl;
  for(int i=0; i<10; i++) {
    l2.insert(i*2);
  }
  cout << "L2: " << l2.toString() << endl << endl;

  cout << "Concatenado..." << endl;
  l1.concat(l2);
  cout << "L1: " << l1.toString() << endl << endl;

  cout << "Invirtiendo..." << endl;
  SimpleList l1Inv = l1.inverted();
  cout << "L1: " << l1.toString() << endl;
  cout << "LI: " << l1Inv.toString() << endl << endl;

  return 0;
}
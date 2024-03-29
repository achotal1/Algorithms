#include "LinkedList.h"

LinkedList::LinkedList() {
  head = nullptr;
}

Node * LinkedList::getHead() {
  return head;
}

bool LinkedList::isEmpty() {
  if (head == nullptr) //Check whether the head points to null
    return true;
  else
    return false;
}

bool LinkedList::printList() {
  if (isEmpty()) {
    cout << "List is Empty!";
    return false;
  }
  Node * temp = head;
  cout << "List : ";

  while (temp != nullptr) {
    cout << temp->data << "->";
    temp = temp->nextElement;
  }
  cout << "null " << endl;
  return true;
}

//Function inserts a value/new Node as the first Element of list
void LinkedList::insertAtHead(int value) {
  Node * newNode = new Node();
  newNode->data = value;
  newNode->nextElement = head; //Linking newNode to head's nextNode
  head = newNode;
  cout << value << " Inserted!";
}

string LinkedList::elements() { // this function will return all values of linked List
  string elementsList = "";
  Node * start = head;
  Node * check = head;

  elementsList += std::to_string(start->data);
  elementsList += "->";
  start = start->nextElement;

  while (start != nullptr && start->data != check->data) {
    elementsList += std::to_string(start->data);
    elementsList += "->";
    start = start->nextElement;
  }

  if(start == nullptr)
    return elementsList+"null";

  elementsList += std::to_string(check->data);
  return elementsList;
}

void LinkedList::insertAtTail(int value) {
  if (isEmpty()) { // inserting first element in list
    insertAtHead(value);
  } else {
    Node * newNode = new Node();
    Node * last = head;

    while (last->nextElement != nullptr) {
      last = last->nextElement;
    }

    newNode->data = value;
    cout << value << " Inserted!    ";
    newNode->nextElement = nullptr;
    last->nextElement = newNode;
  }
}

bool LinkedList::search(int value) {
  Node * temp = head; // pointing temp to the head

  while (temp != nullptr) {
    if (temp->data == value) { // if passed value matches with temp's data
      return true;
    }
    temp = temp->nextElement; // pointig to temp's nextElement
  }
  return false; // if not found
}

bool LinkedList::deleteAtHead() {
  if (isEmpty()) { // check if lis is empty
    cout << "List is Empty" << endl;
    return false;
  }
  //if list is not empty, start traversing it from the head
  Node * currentNode = head; // currentNode pointing to head
  head = head->nextElement; //nextNode point to head's nextElement
  
  delete currentNode;
  return true;
}

bool LinkedList::Delete(int value) {
  bool deleted = false; //returns true if the node is deleted, false otherwise

  if (isEmpty()) { //check if the list is empty
    cout << "List is Empty" << endl;
    return deleted; //deleted will be false
  }

  //if list is not empty, start traversing it from the head
  Node * currentNode = head; //currentNode to traverse the list
  Node * previousNode = nullptr; //previousNode starts from null

  if (currentNode->data == value) { // deleting value of head
    deleted = deleteAtHead();
    cout << value << " deleted!" << endl;
    deleted = true; // true because value found and deleted
    return deleted; //returns true if the node is deleted
  }
  previousNode = currentNode;
  currentNode = currentNode->nextElement; // pointing current to current's nextElement
  //Traversing/Searching for Node to Delete
  while (currentNode != nullptr) {

    //Node to delete is found
    if (value == currentNode->data) {
      // pointing previousNode's nextElement to currentNode's nextElement
      previousNode->nextElement = currentNode->nextElement;
      delete currentNode;
      currentNode = previousNode->nextElement;
      deleted = true;
      break;
    }
    previousNode = currentNode;
    currentNode = currentNode->nextElement; // pointing current to current's nextElement
  }
  //deleted is true only when value is found and delted
  if (deleted == false) {
    cout << value << " does not exist!" << endl;
  } else {
    cout << value << " deleted!" << endl;
  }
  return deleted;
} 

int LinkedList::length() {
  Node * current = head; // Start from the first element
  int count = 0; // in start count is 0

  while (current != nullptr) { // Traverse the list and count the number of nodes
    count++; // increment everytime as element is found
    current = current->nextElement; // pointing to current's nextElement
  }
  return count;
}

string LinkedList::reverse() {
  Node * previous = nullptr; //To keep track of the previous element, will be used in swapping links
  Node * current = head; //firstElement
  Node * next = nullptr;

  //While Traversing the list, swap links
  while (current != nullptr) {
    next = current->nextElement;
    current->nextElement = previous;
    previous = current;
    current = next;
  }

  head = previous; // pointing head to start of the list
  return elements(); // calling elements to return a string of values in list
}

void LinkedList::insertLoop() {
  Node * temp = head;
  // traversing to get to last element of the list
  while (temp->nextElement != nullptr) {
    temp = temp->nextElement;
  }
  temp->nextElement = head; // pointing last element to head of the list
}
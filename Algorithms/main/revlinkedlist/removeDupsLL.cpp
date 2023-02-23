#include "LinkedList.h"
#include <unordered_map>
string LinkedList::removeDuplicates() {  
  unordered_map<int,int> map;
  Node *trav = head;
  Node *prev = head;
 
  Node *first = head;
  for(int i = 0; i<length(); i++){
    map[trav->data]++;
    //cout<<i<<" "<<trav->data<<endl;
    if(map[trav->data] > 1){
      cout<<i<<endl;
      Node *temp = trav;
      if(trav->nextElement == nullptr){
        prev->nextElement = nullptr;
        cout<<"PLS";
        map[temp->data]--;
        delete(temp);
        break;
      }
      trav = trav->nextElement;
      prev->nextElement = trav;
      map[temp->data]--;
      
      if(map[temp->data] == 0){
        map.erase(temp->data);
      }
      delete(temp);
    }
    else{
      //cout<<trav->data<<" ";

      cout<<i<<endl;
      prev = trav;
      if(trav->nextElement == nullptr){
        trav = nullptr;
      }
      else
      trav = trav->nextElement;
    }
  }
  Node *newnode = head;
  while(newnode != nullptr){
    cout<<newnode->data<<" ";
    newnode = newnode->nextElement;
  }
  
  return elements();
}
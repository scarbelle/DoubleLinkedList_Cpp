#ifndef DLLIST_H
#define DLLIST_H

#include "dNode.h"


class DLList
{
 public:
  DLList();
  ~DLList();

  DNode* addNode(int val);
  DNode* findNode(int id);
  void removeNode(DNode *);
  void printList();
  bool isEmpty();

 private:
  DNode* _headp;
  DNode* _tailp;
  int    _lastId;
  
};


#endif //DLLIST_H

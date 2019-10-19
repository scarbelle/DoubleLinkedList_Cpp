#ifndef DLLIST_SHDP_H
#define DLLIST_SHDP_H

#include "dNode_shdp.h"


class DLList
{
 public:
  
  DLList();
  ~DLList();

  std::shared_ptr<DNode> addNode(int val);
  std::shared_ptr<DNode> findNode(int id);
  void removeNode(std::shared_ptr<DNode> dnode);
  void printList();
  bool isEmpty();

 private:
  
  std::shared_ptr<DNode> _headp;
  std::shared_ptr<DNode> _tailp;
  int    _lastId;
};


#endif //DLLIST_SHDP_H

#ifndef DNODE_H
#define DNODE_H

#include <memory>


class DNode
{
 public:
  
  DNode(int id=0, int val=0);
  ~DNode();

  int    getId();
  void   setId(int id);
  int    getVal();
  void   setVal(int val);
  DNode* getPrev();
  void   setPrev(DNode* node);
  DNode* getNext();
  void   setNext(DNode* node);

 private:
  
  int    _id;
  int    _val;
  DNode* _prev;
  DNode* _next;
};


#endif //DNODE_H

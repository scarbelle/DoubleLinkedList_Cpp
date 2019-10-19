#ifndef DNODE_SHDP_H
#define DNODE_SHDP_H

#include <memory>           // shared_ptr


class DNode
{
 public:
  
  DNode(int id=0, int val=0);
  ~DNode();

  int    getId();
  void   setId(int id);
  int    getVal();
  void   setVal(int val);
  std::shared_ptr<DNode> getPrev();
  void   setPrev(std::shared_ptr<DNode> node);
  std::shared_ptr<DNode> getNext();
  void   setNext(std::shared_ptr<DNode> node);

 private:
  
  int    _id;
  int    _val;
  std::shared_ptr<DNode> _prev;
  std::shared_ptr<DNode> _next;
};


#endif //DNODE_SHDP_H

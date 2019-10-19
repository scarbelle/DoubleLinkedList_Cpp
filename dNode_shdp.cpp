#include "dNode_shdp.h"


DNode::DNode(int id, int val)
  : _id(id), _val(val), _prev(nullptr), _next(nullptr)
{}

DNode::~DNode()
{}

int DNode::getId()
{return _id;}

void DNode::setId(int id)
{_id = id;}

int DNode::getVal()
{return _val;}

void DNode::setVal(int val)
{_val = val;}

std::shared_ptr<DNode> DNode::getPrev()
{return _prev;}

void  DNode::setPrev(std::shared_ptr<DNode> prev)
{ _prev = prev;}

std::shared_ptr<DNode> DNode::getNext()
{return _next;}

void  DNode::setNext(std::shared_ptr<DNode> next)
{_next = next;}

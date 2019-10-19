#include "dNode.h"


DNode::DNode(int id, int val)
  : _id(id), _val(val), _prev(nullptr), _next(nullptr)
{}

DNode::~DNode()
{}

int DNode::getId()
{return _id;}

void DNode::setId(int id)
{_id = id;}

int  DNode::getVal()
{return _val;}

void  DNode::setVal(int val)
{_val = val;}

DNode* DNode::getPrev()
{return _prev;}

void  DNode::setPrev(DNode* prev)
{ _prev = prev;}

DNode* DNode::getNext()
{return _next;}

void  DNode::setNext(DNode* next)
{_next = next;}

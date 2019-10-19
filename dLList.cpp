#include <iostream>
#include <memory>
#include "dLList.h"

//
// Constructor
//
DLList::DLList()
  : _headp(nullptr), _tailp(nullptr), _lastId(-1)
{
}

//
// Destructor
//
DLList::~DLList()
{
  DNode* newTail;
  while (_tailp != nullptr)
    {
      newTail = _tailp->getPrev();
      removeNode(_tailp);
      _tailp = newTail;
    }
}

//
// Adds a new node to end of list
//
// To prevent memory leaks: 
// * dynamic allocation requires node deletion prior to exit
//
DNode* DLList::addNode(int val)
{
  // allocates memory size of DNode, then constructs object
  // on failure throws bad alloc
  DNode* newNode = new DNode(++_lastId, val);

  if (_headp == nullptr)
    {
      _headp = newNode;
      _tailp = newNode;
    }
  
  else if (newNode)
    {
      _tailp->setNext(newNode);
      newNode->setPrev(_tailp);
      _tailp = newNode;
    }

  return newNode;
}

//
// Removes Node from List
//
void DLList::removeNode(DNode* node)
{
  DNode* prev;
  DNode* next;
 
  if (node)
    {
      prev = node->getPrev();
      next = node->getNext();

      if (node == _headp)
	{
	  _headp = next;
	}

      if (node ==_tailp)
	{
	  _tailp = prev;
	}

      if (prev)
	{
	  prev->setNext(next);
	}
 
      if (next)
	{
	  next->setPrev(prev);
	}

      delete node;
    }
}

//
// Finds Node in List by Id
// If node found, returns pointer to node
// If node not found, returns nullptr
//
DNode* DLList::findNode(int id)
{
  bool found = false;
  DNode* curr = _headp;

  while (!found && (curr))
    {
      if (curr->getId() == id)
	{
	  found = true;
	}
      else
	{
	  curr = curr->getNext();
	}
    }
  return curr;   
}

//
// Print Nodes in List
//
void DLList::printList()
{
  if (!_headp)
    {
      std::cout << "\nList is EMPTY" << std::endl;
    }

  else
    {
      DNode* curr = _headp;
      std::cout << std::endl;
      while (curr)
	{
	  std::cout << "Id:  " << curr->getId();
	  std::cout << "\tVal:  " << curr->getVal() << std::endl;
	  curr = curr->getNext();
	}
    }
 
  std::cout << std::endl;
}

//
// Checks if list is Empty
//
// Returns:
//    true - list is empty
//    false - list is not empty
//
bool DLList::isEmpty()
{
  return ((!_headp && !_tailp) ? true : false);
}


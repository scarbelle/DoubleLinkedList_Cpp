#include <iostream>
#include <exception>
#include "dLList_shdp.h"

//
// Main.cpp
//
// Purpose C++ Code Sample demonstrating:
//  * Dynamically allocated Doublely Linked List (new, delete)
//  * OOP concepts: abstraction, encapsulation, composition
//
// Execution - Exercises User Defined Double Link List
//  * Variable length, runtime resolved
//  * methods:  addNode, findNode, removeNode, printlist
//
//  TODO: 1) fix to resolve valgrind w/ no leaks
//        2) update to use same main for
//              both regular pointer and shared pointer implementations
//              <templatize??> or simply different include files
//
//
int main()
{
  unsigned ninput;
  int num;
  DLList myDLList;
  // DNode*  currNode;
  std::shared_ptr<DNode>  currNode;

  // User Info
  std::cout << "Welcome to Build-A-Numbers-List" << std::endl;

  // Get User Input
  std::cout << "Enter how many values you would like to enter: " << std::endl;
  std::cin >> ninput;
  std::cout << std::endl;

  // Create Double Linked List
  for (unsigned i = 0; i < ninput; i++)
    {
      std::cout << "Enter a number [" << i + 1 << "]: ";
      std::cin >> num;
      try
        {
          currNode = myDLList.addNode(num);
        }
      catch(std::exception& e)
        {
          std::cout << "Bye-Bye - Error allocating Memory: " << e.what() << std::endl;
          return 0;
        }
    }

  // Show User Results - Print Double Linked List
  std::cout << "The numbers you have entered are: ";
  myDLList.printList();

  // Offer User Option to Remove Entries until User Done or List is Empty
  bool done = (ninput > 0) ? false : true;
  char answer;
  int  id = -1;
  while (!done && !myDLList.isEmpty())
    {
      answer = 'N';
      // Get User Input - to remove entry or be done
      std::cout << "Would you like to remove a number from the list? [Y for Yes]\n";
      std::cin >> answer;
      done = ((answer == 'Y') || (answer == 'y')) ? false : true;

      // Not Done
      if (!done)
        {
          // Get User Input - select id of entry to be removed
          std::cout << "\nEnter the Id of the number you wish to remove.\n";
          std::cin >> id;

          // Find number w/ Id = id
          // DNode* tmp = myDLList.findNode(id);
          std::shared_ptr<DNode> tmp = myDLList.findNode(id);
          if (tmp)
            {
              std::cout << "Removing number w Id: " << id;
              std::cout << "\t val: " << tmp->getVal() << std::endl;
              myDLList.removeNode(tmp);
              std::cout << "Below is the updated list";
              myDLList.printList();
            }
          else
            {
              std::cout << "Invalid Id - Not Found" << std::endl;
            }
        }

      // Done      
      else
        {
          std::cout << "\nOK, Good-Bye!" << std::endl;
        }
    }
}

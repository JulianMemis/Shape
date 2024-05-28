/************************************************************/
/* Author: Julian Memis 									*/
/* Major: Computer Science 									*/
/* Filename: LinkedList.hpp 								*/
/* Purpose: The LinkedList class stores the shapes from the */ 
/* shape class into a linked list.							*/
/************************************************************/

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include "shape.hpp"

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

template <class T>
class LinkedList
{
	T *head; //Pointing to first shape
		
	public:
		LinkedList<T>()
		{
			head = NULL;
		}
				
		/***************************************************************************/
		/* Function name: insertShape */
		/* Description: Inserst a new shape into the linked list */
		/* Parameters: T – myShape: Shape object */
		/* Return Value: Void */
		/***************************************************************************/
		void insertShape(T myShape)
		{ 
		    // Create the new Node. 
		    T* newNode = new T(myShape);
		  
		    // Assign to head 
		    if (head == NULL)
			{ 
		        head = newNode; 
		        return; 
		    } 
		  
		    // Traverse till end of list 
		    T* temp = head; 
		    while (temp->next != NULL) 
			{
		        // Update temp 
		        temp = temp->next; 
		    } 
		  
		    // Insert at the last. 
		    temp->next = newNode; 
		} 
		
		
		/***************************************************************************/
		/* Function name: findNode */
		/* Description: Finds the desired shape using the name of the shape */
		/* Parameters: string – name: The name of the desired shape */
		/* Return Value: object – the shape searched for */
		/***************************************************************************/
		Shape findNode(string name)
		{
			T* temp = head;
			
			if (head == NULL)
			{
				cout << "Shape not found" << endl;
			} 
			
			while(temp != NULL)
			{
				if(temp->getName() == name)
				{					
					return *temp;
				}
				else
				{
					temp = temp->next;
				}
			}
		}
			
		/***************************************************************************/
		/* Function name: printList */
		/* Description: Prints each shape and the associated properties in the linked list */
		/* Return Value: void */
		/***************************************************************************/
		void printList()
		{ 
		    T* temp = head; 
		  
		    // Check for empty list. 
		    if (head == NULL)
			{ 
		        cout << "List empty" << endl; 
		        return; 
		    } 
		  
		    // Traverse the list. 
		    while (temp != NULL)
			{ 
				cout << temp->getName() << ":";
				cout << "\nNumber of sides: ";
				cout << temp->getSides();
				cout << "\nLength of each side: ";
				cout << temp->getLength();
				cout << "\n\n"; 
		        temp = temp->next;
		    } 
		} 
		
		/***************************************************************************/
		/* Function name: totalPerimeter */
		/* Description: Calculates the total perimeter for all the shapes in the linked list */
		/* Return Value: void */
		/***************************************************************************/
		void totalPerimeter()
		{
			 T* temp = head; 
			 float perimeter = 0;
		  
		    // Check for empty list. 
		    if (head == NULL)
			{ 
		        cout << "There are no shapes. Add shapes" << endl; 
		        return; 
		    } 
		  
		    // Traverse the list. 
		    while (temp != NULL)
			{ 
		    	perimeter += temp->computePerimeter(temp->getSides(), temp->getLength());   
			    temp = temp->next;
		    } 
		    
		    cout << "\nTotal Perimeter: " << perimeter << endl;
		}
		
		/***************************************************************************/
		/* Function name: totalArea */
		/* Description: Calculates the total area for all the shapes in the linked list */
		/* Return Value: void */
		/***************************************************************************/
		void totalArea()
		{
			 T* temp = head; 
			 float area = 0;
		  
		    // Check for empty list. 
		    if (head == NULL)
			{ 
		        cout << "There are no shapes. Add shapes" << endl; 
		        return; 
		    } 
		  
		    // Traverse the list. 
			while (temp != NULL)
			{ 
		    	area += temp->computeArea(temp->getSides(), temp->getLength());   
			    temp = temp->next;
		    } 
		    
		    cout << "\nTotal Area: " << area << endl;
		}
		
		//**************************************************
		// The deleteNode function searches for a node     *
		// with num as its value. The node, if found, is   *
		// deleted from the list and from memory.          *
		//**************************************************
		void deleteNode(T myShape)
		{
			T *nodePtr, *previousNode = NULL;
		
			// If the list is empty, do nothing.
			if (!head)
		    	return;
		   
			// Determine if the first node is the one.
			if (head->getName() == myShape.getName())
			{
		    	nodePtr = head->next;
		    	delete head;
		    	head = nodePtr;
			}
		   
			else
			{
		   		// Initialize nodePtr to head of list
		    	nodePtr = head;
		
		    	// Skip all nodes whose value member is 
		    	// not equal to num.
				while (nodePtr != NULL && nodePtr->getName() != myShape.getName())
			    {  
					previousNode = nodePtr;
			        nodePtr = nodePtr->next;
			    }
		
				// If nodePtr is not at the end of the list, 
				// link the previous node to the node after
				// nodePtr, then delete nodePtr.
				if (nodePtr)
				{
					previousNode->next = nodePtr->next;
					delete nodePtr;
				}
			}
		}
			
	private:
};

#endif

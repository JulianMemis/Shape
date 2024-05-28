/************************************************************/
/* Author: Julian Memis */
/* Major: Computer Science */
/* Creation Date: November 28th, 2023 */
/* Due Date: December 3rd, 2023 */
/* Course: CS100-01 */
/* Professor Name: Professor Shimkanon */
/* Assignment: #6 Classes (Shape) */
/* Filename: shape_Main.cpp */
/* Purpose: This program allows the user to add a shape */
/* to a linked list. The user can then choose various actions from a menu */
/* and add a shape, delete a shape, or receive calculations of the shapes (perimeter and area). */
/************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include "shape.hpp"
#include "LinkedList.hpp"

using namespace std;

int main()
{
	//Variables:
	char menuChoice; //Menu Choice
	string shapeName; //Shape name user selected
	int numSides; //Number of sides
	float sideLength; //Length of sides
	Shape myShape; //Shape object
	LinkedList<Shape> list; //Create Linked List
	
	//Display First Menu:
	cout << "I) Insert shape object" << endl;
	cout << "E) Exit the program" << endl;
	cout << "- User Choice: ";
	cin >> menuChoice;
	
	//Insert Shape or Exit:
	if(menuChoice == 'I')
	{		
		cout << "--> Insert\n";
		cout << "\nEnter a new name for the shape: ";
		cin >> shapeName;
		cout << "Enter the number of sides: ";
		cin >> numSides;
		while(numSides < 3) //Shape side check
		{
			cout << "Shape must have 3 or more sides.\n\n" << "Number of sides: ";
			cin >> numSides;
		}
		cout << "Enter the length of each side: ";
		cin >> sideLength;
	}
	else if (menuChoice == 'E')
	{
		cout << "--> Exit";
		return 0;
	}
	else
	{
		cout << "--> Invalid Selection. Program Shutdown";
		return 0;
	}
	
	//Set Shape and add to Linked List:
	myShape.setSides(numSides);
	myShape.setLength(sideLength);
	myShape.setName(shapeName);
	list.insertShape(myShape); //Insert Shape
		
	//Menu:
	do {
		cout << "\nV) View linked list" << endl;
		cout << "I) Insert shape object (into linked list)" << endl;
		cout << "D) Delete shape object (from linked list)" << endl;
		cout << "Q) Query an individual shape" << endl;
		cout << "T) Calculate the total perimeter or area of the shapes" << endl;
		cout << "E) Exit the program" << endl;
		cout << "\n- User Choice: ";
		cin >> menuChoice;
		
		switch(menuChoice)
		{
			case 'V': //View
				cout << "--> View\n" << endl;
				list.printList();
				break;
				 
			case 'I': //Insert
				cout << "--> Insert" << endl;				
				cout << "\nEnter a new name for the shape: ";
				cin >> shapeName;	
				cout << "Enter the number of sides: ";
				cin >> numSides;
				while(numSides < 3) //Shape side check
				{
					cout << "Shape must have 3 or more sides. \n\n" << "Number of sides: ";
					cin >> numSides;
				}
				cout << "Enter the length of each side: ";
				cin >> sideLength;
				
				//Set Shape and add to Linked List:
				myShape.setSides(numSides);
				myShape.setLength(sideLength);
				myShape.setName(shapeName);
				list.insertShape(myShape);//Insert Shape
				break;
			
			case 'D': //Delete
				cout << "--> Delete\n\n" << endl;
				cout << "Enter the name of the shape you want to delete: ";
				cin >> shapeName;
				myShape = list.findNode(shapeName);
				list.deleteNode(myShape);
				break;
				
			case 'Q': //Query
				cout << "--> Query\n\nEnter the name of the shape you want: ";
				cin >> shapeName;
				myShape = list.findNode(shapeName);
						
				//Menu Query:
				do {
					cout << "\nP) Perimeter" << endl;
					cout << "A) Area" << endl;
					cout << "B) Back" << endl;
					cout << "E) Exit" << endl;
					cout << "\n- User Choice: ";
					cin >> menuChoice;
				
					switch(menuChoice)
					{
						case 'P': //Perimeter 
							cout << "--> Perimeter \n\nPerimeter: " << myShape.computePerimeter(myShape.getSides(), myShape.getLength()) << "\n";
							break;
							
						case 'A': //Area
							cout << "--> Area \n\nArea: " << myShape.computeArea(myShape.getSides(), myShape.getLength()) << "\n"; 
							break;	
											
						case 'B': //Back
							cout << "--> Back \n\n";
							break;
							
						case 'E': //Exit
							cout << "--> Exit";
							return 0;
					}
				} while(menuChoice != 'B');
				break;
				
			case 'T': //Calculate
				cout << "--> Calculate\n\nCalculate total area (A) or total perimeter (P): ";
				cin >> menuChoice;
							
				if(menuChoice == 'A')
				{
					cout << "--> Area\n";
					list.totalArea();
				}
				else if(menuChoice == 'P')
				{
					cout << "--> Perimeter\n";
					list.totalPerimeter();
				}	
				break;	
				
			default:
				cout << "\n--> Invalid Selection. Program Shutdown" << endl;
				return 0;
		}
	} while(menuChoice != 'E');	
		
	return 0;
}	

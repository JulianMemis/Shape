/************************************************************/
/* Author: Julian Memis */
/* Major: Computer Science */
/* Creation Date: November 9th, 2023 */
/* Due Date: December 3rd, 2023 */
/* Course: CS100-01 */
/* Professor Name: Professor Shimkanon */
/* Assignment: #6 Classes (Shape) */
/* Filename: shape.hpp */
/* Purpose: The Shape class is the blueprint for the information */
/* contained in each shape. It also provides various functions for */
/* calculations of the shapes */
/************************************************************/

#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

class Shape
{
	public:		
		Shape *next;
		Shape *value;
	
		//Default Shape constructor
		Shape()
		{
			next = NULL;
			value = NULL;
		}
		
		//Shape Construtor 
		Shape(string shapeName, int numSides, float sideLength)
		{
			name = shapeName;
			sides = numSides;
			length = sideLength;
			next = NULL;
			value = NULL;
		}
		
		/***************************************************************************/
		/* Function name: setSides */
		/* Description: Sets the number of sides for the shape */
		/* Parameters: int - ssides: The number of sides for the shape */
		/***************************************************************************/
		void setSides(int ssides)
		{
			sides = ssides;
		}
			
		/***************************************************************************/
		/* Function name: setLength */
		/* Description: Sets the length of each side for the shape */
		/* Parameters: float - slength: The length of each side for the shape */
		/***************************************************************************/
		void setLength(float slength)
		{
			length = slength;
		}
		
		/***************************************************************************/
		/* Function name: setName */
		/* Description: Sets the name for the shape */
		/* Parameters: string - sname: The name of the selected shape */
		/***************************************************************************/
		void setName(string sname)
		{
			name = sname;
		}
			
		/***************************************************************************/
		/* Function name: getName */
		/* Description: Returns the name for the shape */
		/* Return Value: string – the name of the shape */
		/***************************************************************************/
		string getName()
		{
			return name;
		}	
			
		/***************************************************************************/
		/* Function name: getSides */
		/* Description: Returns the number of sides for the shape */
		/* Return Value: int – the number of each sides for the shape */
		/***************************************************************************/
		int getSides()
		{
			return sides;
		}
		
		/***************************************************************************/
		/* Function name: getLength */
		/* Description: Returns the length of each side for the shape */
		/* Return Value: float – the length of each side for the shape */
		/***************************************************************************/
		float getLength()		
		{
			return length;
		}
		
		/***************************************************************************/
		/* Function name: computePerimeter */
		/* Description: Calculates the perimeter for a shape */
		/* Parameters: int – numSides: The number of sides for the shape */
		/* Parameters: float – sideLength: The length of each sides for the shape */
		/* Return Value: float – the perimeter for the shape */
		/***************************************************************************/
		virtual float computePerimeter(int numSides, float sideLength) const
		{
			float perimeter = numSides * sideLength;
			
			return perimeter;
		}
		
		/***************************************************************************/
		/* Function name: computeApothem */
		/* Description: Calculates the apothem for a shape */
		/* Parameters: int – numSides: The number of sides for the shape */
		/* Parameters: float – sideLength: The length of each sides for the shape */
		/* Return Value: float – the apothem for the shape */
		/***************************************************************************/
		virtual float computeApothem(int numSides, float sideLength) const
		{
			float apothem = (sideLength / (tan(M_PI/numSides))*2.0f);
					
			return apothem;
		}
		
		/***************************************************************************/
		/* Function name: computeArea */
		/* Description: Calculates the area for a shape */
		/* Parameters: int – numSides: The number of sides for the shape */
		/* Parameters: float – sideLength: The length of each sides for the shape */
		/* Return Value: float – the area for the shape */
		/***************************************************************************/
		virtual float computeArea(int numSides, float sideLength) const
		{
			float a = computeApothem(numSides, sideLength); //Apothem
			float p = computePerimeter(numSides, sideLength); //Perimeter
			float area = (a*numSides*sideLength) / 8; //Area
			
			return area;
		}

 	private:
 		//Private Variables
 		string name; //Name of shape
		int sides; //Number of sides for shape
		float length; //Length of each side for shape
};

#endif

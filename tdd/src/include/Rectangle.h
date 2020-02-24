//
// Created by mwitt_cjbzle6 on 2/21/2020.
//

#ifndef TDD_RECTANGLE_H
#define TDD_RECTANGLE_H


#include <exception>
#include <string>

using namespace std;

class RectangleException: public exception
{
private:
   string message;

public:
   RectangleException(string message){
      this->message = message;
   }

   virtual const char* what() const throw(){
      return message.c_str();
   }
};


class Rectangle {
private:
   int xmin, ymin, xmax, ymax;

public:

   /**
    * Set up a rectangle in a constructor
    * @param xmin
    * @param ymin
    * @param xmax
    * @param ymax
    */
   Rectangle(int xmin, int ymin, int xmax, int ymax);

   /**
    * Compute rectangle area
    * @return
    */
   int area();
};


#endif //TDD_RECTANGLE_H

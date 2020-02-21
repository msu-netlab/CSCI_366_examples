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
   void initialize(int xmin, int ymin, int xmax, int ymax);
};


#endif //TDD_RECTANGLE_H

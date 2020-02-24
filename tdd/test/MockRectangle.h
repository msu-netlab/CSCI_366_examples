#include "gmock/gmock.h"

#include "Rectangle.h"

class MockRectangle : public Rectangle {
public:
   MockRectangle(int xmin, int ymin, int xmax, int ymax) : Rectangle(xmin, ymin, xmax, ymax) {};

   MOCK_METHOD(int, get_width, (), (override));
   MOCK_METHOD(int, get_height, (), (override));
   MOCK_METHOD(int, area, (), (override));

};





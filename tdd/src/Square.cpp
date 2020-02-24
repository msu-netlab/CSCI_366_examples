#include "Square.h"

Square::Square(Rectangle *r) {
   this->r = r;
}

int Square::area() {
   return r->area();
}

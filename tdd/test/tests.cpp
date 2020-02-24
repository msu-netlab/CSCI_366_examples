#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Rectangle.h"

/**
 * Discussion:
 * - EXPECT vs ASSERT
 * - string comparison: ASSERT_STREQ
 * - floating point comparison: ASSERT_DOUBLE_EQ
 * - testing with objects
 * - using fixtures
 * - FAIL() (for example in switch default)
 * - testing with exceptions
 */

TEST(BasicTest, Success){
   EXPECT_EQ(0,1);
   printf("after expect\n");
   ASSERT_EQ(0,1);
   printf("after assert\n");
}


TEST(RectangleInitializeBasic, Initialize_Correct){
   EXPECT_NO_FATAL_FAILURE(Rectangle r(0, 0, 1, 1));
}

TEST(RectangleInitializeBasic, Initialize_Point_Rectangle){
  ASSERT_ANY_THROW(Rectangle r(0,0,0,0));
}

TEST(RectangleAreaBasic, Correct_Area_Calculated){
   Rectangle r(0,0, 2, 2);
   ASSERT_EQ(4, r.area());
}


class RectangleArea: public ::testing::Test{
protected:
   // Create rectangle object so that it may be referenced inside class functions,
   // including tests
   Rectangle *r;

   // called before each fixture test
   RectangleArea(){
      printf("Constructor called\n");
      // set up the rectangle
      r = new Rectangle(0,0,2,2);
   }

   // called before each fixture test after constructor
   void SetUp() override {
      printf("SetUp called\n");
   }

   // called after each fixture test before destructor
   void TearDown() override {
      printf("TearDown called\n");
   }

   // called after each fixture test
   ~RectangleArea(){
      printf("Destructor called\n");
      // destroy the dynamically allocated r
      delete r;
   }
};

TEST_F(RectangleArea, Area_Correct){
   ASSERT_EQ(r->area(),4);
}





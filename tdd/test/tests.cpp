#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MockRectangle.h"

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
 * - parameterized tests
 */


// Basic tests showing comparisons

//TEST(BasicTest, Success){
//   EXPECT_EQ(0,1);
//   printf("after expect\n");
//   ASSERT_EQ(0,1);
//   printf("after assert\n");
//}


// Basic tests showing single function testing

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


// Fixture tests including setup and teardown

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


// Parameterized tests

class RectangleAreaParams : public testing::TestWithParam<std::tuple<int,int,int>> {
protected:
   Rectangle *r;

   RectangleAreaParams(){
      r = new Rectangle(0,0, std::get<0>(GetParam()), std::get<1>(GetParam()));
   }

   ~RectangleAreaParams(){
      delete r;
   }
};

TEST_P(RectangleAreaParams, AreaCorrect) {
   ASSERT_EQ(r->area(), std::get<2>(GetParam()));
}

INSTANTIATE_TEST_CASE_P(
        RandomTestName,
        RectangleAreaParams,
        ::testing::Values(
                std::make_tuple(1, 1, 1),
                std::make_tuple(2, 2, 4)));


// Google Mock test

using ::testing::AtLeast;
using ::testing::Return;


TEST(PainterTest, CanDrawSomething) {
   MockRectangle mockr(0, 0, 1, 1);

   EXPECT_CALL(mockr, get_width())
              .Times(AtLeast(1))
              .WillRepeatedly(Return(1));

   EXPECT_CALL(mockr, get_height())
           .Times(AtLeast(1))
           .WillRepeatedly(Return(1));


   EXPECT_EQ(mockr.area(), 1);      
}


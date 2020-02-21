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
 * - testing with exception
 */

TEST(BasicTest, Success){
   ASSERT_EQ(1,1);
}


TEST(RectangleInitializeBasic, Initialize_Correct){
   Rectangle r;
   EXPECT_NO_FATAL_FAILURE(r.initialize(0, 0, 1, 1));
}


//class RectangleInitialize: public ::testing::Test{
//protected:
//   Rectangle r;
//
//   void SetUp() override {
//      r.initialize(0,0,1,1);
//   }
//
//   void TearDown() override {
//      ;
//   }
//};
//
//TEST_F(RectangleInitialize, Initialize_Correct){
//   ASSERT_EQ(1,1);
//}





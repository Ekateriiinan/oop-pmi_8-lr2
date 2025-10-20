#include <gtest/gtest.h>
#include "Twelve.h"

TEST(TwelveTest, StringConstructor) {
    Twelve num("A1B");
    EXPECT_EQ(num.toString(), "A1B");
}


TEST(TwelveTest, InitializerListConstructor) {
    Twelve num({'1', 'A', '2', 'B'});
    EXPECT_EQ(num.toString(), "1A2B");
}

TEST(TwelveTest, SizeConstructor) {
    Twelve num(4, '5');
    EXPECT_EQ(num.getSize(), 4);
    EXPECT_EQ(num.toString(), "5555");
}

TEST(TwelveTest, InvalidDigit) {
    EXPECT_THROW(Twelve("A1Z"), std::invalid_argument);
    EXPECT_THROW(Twelve({'1', 'C'}), std::invalid_argument);
    EXPECT_THROW(Twelve(3, 'Z'), std::invalid_argument);
}

TEST(TwelveTest, CopyConstructor) {
    Twelve num1("A1B");
    Twelve num2 = num1;
    EXPECT_TRUE(num1.equals(num2));
}

TEST(TwelveTest, AddOperation) {
    Twelve a("1A3");
    Twelve b("B2");
    Twelve result = a.add(b);
    EXPECT_EQ(result.toString(), "295");
}

TEST(TwelveTest, SubtractOperation) {
    Twelve a("1A3");
    Twelve b("B2");
    Twelve result = a.subtract(b);
    EXPECT_EQ(result.toString(), "B1");
}

TEST(TwelveTest, SubtractNegativeResult) {
    Twelve a("B2");
    Twelve b("1A3");
    EXPECT_THROW(a.subtract(b), std::invalid_argument);
}

TEST(TwelveTest, ComparisonOperations) {
    Twelve a("1A3");
    Twelve b("B2");
    Twelve c("1A3");
    
    EXPECT_TRUE(a.equals(c));
    EXPECT_FALSE(a.equals(b));
    EXPECT_TRUE(b.lessThan(a));
    EXPECT_TRUE(a.greaterThan(b));
}

TEST(TwelveTest, LeadingZerosRemoval) {
    Twelve num("000A1B");
    EXPECT_EQ(num.toString(), "A1B");
    
    Twelve num2({'0', '0', '1', 'A'});
    EXPECT_EQ(num2.toString(), "1A");
}

TEST(TwelveTest, CopyMethod) {
    Twelve original("A1B");
    Twelve copy = original.copy();
    EXPECT_TRUE(original.equals(copy));
}

TEST(TwelveTest, EdgeCases) {
    Twelve zero1("0");
    Twelve zero2("000");
    EXPECT_TRUE(zero1.equals(zero2));
    
    Twelve max("BBB");
    Twelve one("1");
    Twelve result = max.add(one);
    EXPECT_EQ(result.toString(), "1000");
}

TEST(TwelveTest, DefaultConstructor) {
    Twelve num;
    EXPECT_EQ(num.toString(), "0");
    EXPECT_EQ(num.getSize(), 1);
}

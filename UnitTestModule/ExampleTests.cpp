#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include "../Example.hpp"

class CalcTextFixture : public ::testing::Test
{
public:
    Calculator *test_calc;
    std::vector<double> vect1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<double> vect2{12.2, 15.4, 90.05, 10, 20};
    std::vector<double> vect3{1, 5, 9, 0, 50.3, 12.98};

    void SetUp() override
    {
        test_calc = new Calculator();
    }

    void TearDown() override
    {
        delete test_calc;
    }
};

TEST(CalculatorTest, TestAddFunction)
{
    Calculator test_calc;
    EXPECT_EQ(test_calc.get_sum(), 0);

    test_calc.add(10);
    EXPECT_EQ(test_calc.get_sum(), 10);

    test_calc.add(1500.689);
    EXPECT_EQ(test_calc.get_sum(), 1510.689);
}

TEST(CalculatorTest, TestSubtractFunction)
{
    Calculator test_calc;
    EXPECT_EQ(test_calc.get_sum(), 0);

    test_calc.subtract(10);
    EXPECT_EQ(test_calc.get_sum(), -10);

    test_calc.subtract(1500.689);
    EXPECT_EQ(test_calc.get_sum(), -1510.689);
}

TEST(CalculatorTest, TestDivideFunction)
{
    Calculator test_calc;
    EXPECT_EQ(test_calc.get_sum(), 0);

    test_calc.add(100);
    test_calc.divide(3);
    EXPECT_NEAR(test_calc.get_sum(), 33.3, 0.3);

    EXPECT_ANY_THROW(test_calc.divide(0));
    EXPECT_THROW(test_calc.divide(0), std::invalid_argument);
}

TEST_F(CalcTextFixture, TestAddVectFunction)
{
    long double sum_val;
    test_calc->add(10);

    sum_val = test_calc->add_vect(vect1);
    EXPECT_EQ(sum_val, test_calc->get_sum());
    EXPECT_EQ(sum_val, 55);

    sum_val = test_calc->add_vect(vect2);
    EXPECT_EQ(sum_val, test_calc->get_sum());
    EXPECT_DOUBLE_EQ(sum_val, 147.65) << ">> The sum = " << sum_val << std::endl;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

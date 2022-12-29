#ifndef APP_DEMO_HPP
#define APP_DEMO_HPP

#include <vector>

class Calculator
{

private:
    long double sum;

public:
    Calculator();

    void clear_sum();
    long double add(double num);
    long double subtract(double num);
    long double divide(double num);
    long double multiply(double num);

    long double add_vect(std::vector<double> vect_num);
    long double multiply_vect(std::vector<double> vect_num);

    void set_sum(long double sum_val);
    long double get_sum();
};

#endif /* APP_DEMO_HPP */

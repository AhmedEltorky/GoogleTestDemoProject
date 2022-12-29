#include "Example.hpp"
#include <stdexcept>

Calculator::Calculator() : sum{0}
{
}

void Calculator::clear_sum()
{
    this->sum = 0;
}

long double Calculator::add(double num)
{
    this->sum += num;
    return this->sum;
}

long double Calculator::subtract(double num)
{
    this->sum -= num;
    return this->sum;
}

long double Calculator::divide(double num)
{
    if (num > 0)
    {
        this->sum /= num;
    }
    else
    {
        throw std::invalid_argument("cannot divide by zero!!!");
    }

    return this->sum;
}

long double Calculator::multiply(double num)
{
    this->sum *= num;
    return this->sum;
}

long double Calculator::add_vect(std::vector<double> vect_num)
{
    this->sum = 0;

    for (auto num : vect_num)
    {
        this->sum += num;
    }

    return this->sum;
}

long double Calculator::multiply_vect(std::vector<double> vect_num)
{
    this->sum = 1;

    for (auto num : vect_num)
    {
        this->sum *= num;
    }

    return this->sum;
}

void Calculator::set_sum(long double sum_val)
{
    this->sum = sum_val;
}

long double Calculator::get_sum()
{
    return this->sum;
}

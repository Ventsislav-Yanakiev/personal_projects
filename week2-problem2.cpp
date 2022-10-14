//Check if year is leap or not
//if output is true then it is a leap year, if it is false it is not a leap year
#include<iostream>
int main ()
{
    int current_year;
    std::cin >> current_year;
    bool year_check(current_year%4 ==0 && current_year%100 != 0 || current_year%4 ==0 && current_year%400 == 0 );
    std::cout << std::boolalpha << year_check << std::endl;
}

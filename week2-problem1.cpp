#include<iostream>
int main ()
{
    int age;
    std::cin >> age;
    bool vote_check(age >= 18);
    std::cout << std::boolalpha << vote_check << '\n';
}

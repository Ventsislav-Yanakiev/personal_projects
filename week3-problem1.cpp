#include<iostream>
int main ()
{
    int first, second, third;
    std::cin >> first >> second >> third;
    if(first > second && second > third)
    {
        std::cout<< third << " "<< second << " "<< first;
    }
    if(first > third && third > second)
    {
        std::cout<< second << " "<< third << " "<< first;
    }
    if(second > first && first > third)
    {
        std::cout<< third << " "<< first << " "<< second;
    }
    if(second > third && third > first)
    {
        std::cout<< first << " "<< third << " "<< second;
    }
    if(third > first && first > second)
    {
        std::cout<< second << " "<< first << " "<< third;
    }
    if(third > second && second > first)
    {
        std::cout<< first << " " << " " << second<< " " << third;
    }
    if(first == second && second > third)
    {
        std::cout << third << " " << second << " " << first;
    }
    if(first == second && second < third)
    {
        std::cout << first << " " << second << " " << third;
    }
    if(third == second && second < first)
    {
        std::cout << third << " " << second << " " << first;
    }
    if(third == second && second > first)
    {
        std::cout << first << " " << second << " " << third;
    }
    if(third == first && first > second)
    {
        std::cout << second << " " << first << " " << third;
    }
    if(third == first && first < second)
    {
        std::cout << first << " " << third << " " << second;
    }
    return 0;
}

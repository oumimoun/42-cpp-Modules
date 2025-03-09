#include "Span.hpp"

int main()
{
    try
    {
        std::cout << "Basic Test:" << std::endl;
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

        std::cout << "\nTesting large range addition:" << std::endl;
        Span largeSpan(10000);
        std::vector<int> numbers;
        srand(time(0));
        for (int i = 0; i < 10000; ++i)
        {
            numbers.push_back(rand());
        }
        largeSpan.addNumbers(numbers.begin(), numbers.end());
        std::cout << "Shortest Span: " << largeSpan.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << largeSpan.longestSpan() << std::endl;

        std::cout << "\nTesting exception handling:" << std::endl;
        Span smallSpan(2);
        smallSpan.addNumber(10);
        try
        {
            std::cout << smallSpan.shortestSpan() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }
        smallSpan.addNumber(20);
        std::cout << "Shortest Span: " << smallSpan.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << smallSpan.longestSpan() << std::endl;

        try
        {
            smallSpan.addNumber(30);
        }
        catch (const std::exception &e)
        {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Unhandled exception: " << e.what() << std::endl;
    }
    return 0;
}

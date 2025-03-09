#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Usage: ./RPN <input numbers>" << std::endl;
        return 1;
    }
    RPN rpn;

    rpn.processInput(av[1]);

    return 0;
}
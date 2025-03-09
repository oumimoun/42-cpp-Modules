#include <iostream>

int main(int ac, char **av)
{
    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    
    for (int j = 1; j < ac; ++j)
    {
        for (int i = 0; av[j][i] != '\0'; ++i)
        {
            av[j][i] = std::toupper((av[j][i]));
        }
    }

    for (int i = 1; i < ac; ++i)
    {
        std::cout << av[i];
    }
    std::cout << '\n';
    return 0;
}

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    PmergeMe sorter;

    if (ac < 2)
    {
        std::cerr << "Error: Usage ./Pmerge <numbers> " << std::endl;
        return 1;
    }

    std::vector<int> vec;
    std::deque<int> deq;

    PmergeMe::parseInput(ac, av, vec, deq);

    PmergeMe::printSequence("Before: ", vec);

    clock_t startVec = clock();
    sorter.sortVector(vec);
    clock_t endVec = clock();
    double durationVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1e6;

    clock_t startDeq = clock();
    sorter.sortDeque(deq);
    clock_t endDeq = clock();
    double durationDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1e6;

    PmergeMe::printSequence("After: ", vec);

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: "
              << durationVec << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque: "
              << durationDeq << " us" << std::endl;

    return 0;
}

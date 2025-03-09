#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <algorithm>

class PmergeMe
{
public :
	PmergeMe(void);
	PmergeMe(PmergeMe const &other);
	~PmergeMe(void);
	PmergeMe &operator = (PmergeMe const &other);

	void sortVector(std::vector<int>& vec);
    void sortDeque(std::deque<int>& deq);

    static void parseInput(int ac, char **av, std::vector<int>& vec, std::deque<int>& deq);
    static void printSequence(const std::string& message, const std::vector<int>& vec);

};

#endif
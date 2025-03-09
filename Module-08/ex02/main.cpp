#include "MutantStack.hpp"

int main(void)
{
    std::cout << "------ subject main ------" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "Stack elements (using iterator):" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    std::stack<int> s(mstack);

    std::cout << "\n------ additional tests ------" << std::endl;

    MutantStack<int> copyStack = mstack;
    std::cout << "Copy stack size: " << copyStack.size() << std::endl;
    std::cout << "Copy stack elements: ";
    MutantStack<int>::iterator copyStackIt = copyStack.begin();
    while (copyStackIt != copyStack.end())
    {
        std::cout << *copyStackIt << " ";
        copyStackIt++;
    }
    std::cout << std::endl;
    

    std::cout << "Reverse iteration:" << std::endl;
    MutantStack<int>::reverse_iterator rit = copyStack.rbegin();
    MutantStack<int>::reverse_iterator rite = copyStack.rend();
    while (rit != rite)
    {
        std::cout << *rit << " ";
        ++rit;
    }
    std::cout << std::endl;

    std::cout << "\n------ string tests ------" << std::endl;
    MutantStack<std::string> strStack;
    strStack.push("Hello");
    strStack.push("42");
    strStack.push("students");
    strStack.push("my");
    strStack.push("name");
    strStack.push("is");
    strStack.push("OUSSAMA");
    std::cout << "String stack elements:" << std::endl;
    MutantStack<std::string>::iterator sit;
    for (sit = strStack.begin(); sit != strStack.end(); ++sit)
    {
        std::cout << *sit << " ";
    }
    std::cout << std::endl;

    std::cout << "\n------ popping elements until empty ------" << std::endl;
    while (!mstack.empty())
    {
        std::cout << "Popped: " << mstack.top() << std::endl;
        mstack.pop();
    }
    std::cout << "Is empty? " << (mstack.empty() ? "Yes" : "No") << std::endl;

    return 0;
}

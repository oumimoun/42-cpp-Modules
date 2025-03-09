#include "iter.hpp"

int main(void)
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    size_t len = sizeof(array) / sizeof(array[0]);

    std::cout << "Original Array: ";
    iter(array, len, printElem<int>);
    std::cout << "\n";

    std::cout << "Incremented Array: ";
    iter(array, len, incrementElem<int>);
    iter(array, len, incrementElem<int>);
    iter(array, len, printElem<int>);
    std::cout << "\n";

    std::cout << "Decremented Array: ";
    iter(array, len, decrementElem<int>);
    iter(array, len, printElem<int>);
    std::cout << "\n";

    std::string strArr[] = {"Hello", "42", "Students", "My", "Name", "Is", "OUSSAMA"};
    size_t strArrSize = sizeof(strArr) / sizeof(strArr[0]);

    std::cout << "String array: ";
    iter(strArr, strArrSize, printElem<std::string>);
    std::cout << std::endl;

    return 0;
}
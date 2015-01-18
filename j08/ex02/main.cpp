#include "mutantstack.hpp"

int main()
{
    MutantStack<int> mstack;

    mstack.push(43434534);
    mstack.push(-586317);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(48643);
    mstack.push(546);
    mstack.push(7637);
    mstack.push(6448);
    mstack.push(646466);
    mstack.push(-42);
    mstack.push(42);
    
    MutantStack<int>::iterator ite = mstack.end();
    MutantStack<int>::iterator it = mstack.begin();

    ++it;
    --it;

    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    return 0;
}

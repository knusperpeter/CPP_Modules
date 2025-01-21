#include "MutantStack.hpp"
#include <list>
#include <vector>

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	// Test iterator
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	// Test copy constructor
	MutantStack<int> mstack_copy(mstack);
	std::cout << "Copied stack elements: ";
	for (MutantStack<int>::iterator it = mstack_copy.begin(); it != mstack_copy.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	// Test assignment operator
	MutantStack<int> mstack_assigned;
	mstack_assigned = mstack;
	std::cout << "Assigned stack elements: ";
	for (MutantStack<int>::iterator it = mstack_assigned.begin(); it != mstack_assigned.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::stack<int> s(mstack);


	// output with list instead of stack
	std::list<int> mlist;
	mlist.push_back(5);
	mlist.push_back(17);
	std::cout << mlist.back() << std::endl;
	mlist.pop_back();
	std::cout << mlist.size() << std::endl;
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	mlist.push_back(0);
	std::list<int>::iterator lit = mlist.begin();
	std::list<int>::iterator lite = mlist.end();
	++lit;
	--lit;
	while (lit != lite)
	{
	std::cout << *lit << std::endl;
	++lit;
	}
	std::list<int> t(mlist);
	std::vector<int> lol(2, 2);
	lol.at(0) = 69;
	std::vector<int>::iterator lcit = lol.begin();
	std::cout << *lcit << std::endl;
	lcit++;
	std::cout << *lcit << std::endl;

	//check for const iterator
	return 0;
}
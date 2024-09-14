#include "MutantStack.hpp"

// int main()
// {
// 	MutantStack<int> mstack;
// 	mstack.push(5);
// 	mstack.push(17);

// 	std::cout << mstack.top() << std::endl;
// 	mstack.pop();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	mstack.push(0);
	
// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	std::stack<int> s(mstack);
// 	s.push(7542);
// 	s.push(37);
// 	std::cout << s.top() << std::endl;
// 	s.pop();
// 	s.pop();
// 	s.pop();
// 	std::cout << s.top() << std::endl;

// 	return 0;
// }

int main()
{
	MutantStack<int> st;
	st.push(10);
	st.push(15);
	st.push(-20);
	st.push(25);
	st.push(-30);
	st.pop();
	std::cout << st.size() << std::endl;

	MutantStack<int>::const_reverse_iterator cr_it = st.rbegin();
	MutantStack<int>::const_reverse_iterator cr_ite = st.rend();
	std::cout << "---reversed-but-const---" << std::endl;
	while (cr_it != cr_ite)
	{
		std::cout << *cr_it << std::endl;
		++cr_it;
	}

	MutantStack<int>::reverse_iterator r_it = st.rbegin();
	MutantStack<int>::reverse_iterator r_ite = st.rend();
	std::cout << "---reversed-and-changed---" << std::endl;
	while (r_it != r_ite)
	{
		*r_it += 5;
		std::cout << *r_it << std::endl;
		++r_it;
	}

	MutantStack<int>::const_iterator c_it = st.begin();
	MutantStack<int>::const_iterator c_ite = st.end();
	std::cout << "----const---" << std::endl;
	while (c_it != c_ite)
	{
		std::cout << *c_it << std::endl;
		++c_it;
	}

	return 0;
}
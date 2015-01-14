#include <cstdlib>
#include <ctime>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
	int r = rand() % 3;
	if (r == 0){
		std::cout << "Created A" << std::endl;
		return new A();
	}
	if (r == 1){
		std::cout << "Created B" << std::endl;
		return new B();
	}
	if (r == 2){
		std::cout << "Created C" << std::endl;
		return new C();
	}
	std::cout << "No class created" << std::endl;
	return NULL;
}

void identify_from_pointer(Base* p)
{
	A* ptrA = dynamic_cast<A*>(p);
	if (ptrA != NULL){
		std::cout << "A" << std::endl;
		return ;
	}
	B* ptrB = dynamic_cast<B*>(p);
	if (ptrB != NULL){
		std::cout << "B" << std::endl;
		return ;
	}
	C* ptrC = dynamic_cast<C*>(p);
	if (ptrC != NULL){
		std::cout << "C" << std::endl;
		return ;
	}
	std::cout << "No class identified" << std::endl;
}

void identify_from_reference(Base& p)
{
	try{
		A& ptrA = dynamic_cast<A&>(p);
		std::cout << ptrA << std::endl;
		return ;
	}catch(std::exception& e){
	}
	try{
		B& ptrB = dynamic_cast<B&>(p);
		std::cout << ptrB << std::endl;
		return ;
	}catch(std::exception& e){
	}
	try{
		C& ptrC = dynamic_cast<C&>(p);
		std::cout << ptrC << std::endl;
		return ;
	}catch(std::exception& e){
	}
	std::cout << "No class identified" << std::endl;
}

int main()
{
	srand (time(NULL));
	Base* r = generate();
	identify_from_pointer(r);
	identify_from_reference(*r);
	return 0;
}

#include <iostream>
#include "FunctorOne.h"

using namespace std;

void FunctorOne::MemberFunction()
{
	cout << "\n" << "8. MEMBER FUNCTION WITHOUT ARGUMENTS" << "\n";
}

void FunctorOne::MemberFunctionWArg(int a, float& b, char* c)
{
	cout << "\n" << "AFTER PASSING" << "\n";
	printf("\n a(%p) = % d\n b(%p) = % f\n c(%p) = % s\n", &a, a, &b, b, &c, c);
}

void FunctorOne:: operator() ()
{
	cout << "\n" << "3: NO ARGUMENTS FUNCTOR" << "\n";
}

void FunctorOne::operator()(int x, float& y, char* p)
{
	//cout << "\n" << "4: ARGUMENTS FUNCTOR" << "\n";
	cout << "\n" << "AFTER PASSING" << "\n";
	printf("\n x(%p) = % d\n y(%p) = % f\n p(%p) = % s\n", &x, x, &y, y, &p, p);
}

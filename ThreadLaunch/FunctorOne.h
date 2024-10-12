#ifndef FUNCTOR_ONE_H
#define FUNCTOR_ONE_H

class FunctorOne
{
public:
	FunctorOne() = default;
	FunctorOne(const FunctorOne&) = default;
	FunctorOne& operator = (const FunctorOne&) = delete;
	~FunctorOne() = default;

public:

	void MemberFunction();
	void MemberFunctionWArg(int a, float& b, char* c);

	void operator() (); //Functor;

	void operator() (int x, float& y, char* p); //Functor;
};

#endif
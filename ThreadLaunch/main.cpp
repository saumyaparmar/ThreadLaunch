#include <iostream>
#include <thread>
#include "ThreadFunctions.h"
#include "FunctorOne.h"

using namespace std;


void T1_Main()
{
	//NO ARGUMENTS//
	cout << "\n" << "1: NO ARGUMENTS THREAD FUNCTION" << "\n";
}

void T2_Main(int x, float& y, char* p)
{
	//WITH ARGUMENTS//
	//cout << "\n" << "2: ARGUMENTS THREAD FUNCTION" << "\n";
	cout << "\n" << "AFTER PASSING" << "\n";
	printf("\n x(%p) = % d\n y(%p) = % f\n p(%p) = % s\n",&x,x,&y,y,&p,p);
}


int main()
{
	//1: NO ARGUMENTS//
	std::thread t1(T1_Main);
	t1.join();

	//2. WITH ARGUMENTS//
	int x = 69;
	float y = 420.0f;
	char* p = new char[7];
	memset(p, 0x0, 7);
	strcpy_s(p, 7,"Lisbon"); //One space of null terminator '\0' //

	cout << "\n" << "2: ARGUMENTS THREAD FUNCTION" << "\n";
	cout << "\n" << "BEFORE PASSING" << "\n";
	printf("\n x(%p) = % d\n y(%p) = % f\n p(%p) = % s\n", &x, x, &y, y, &p, p);
	std::thread t2(T2_Main, x, std::ref(y), p);
	t2.join();


	//3. FUNCTOR WITH NO ARGUMENTS//
	FunctorOne F1;
	std::thread t3(F1); //Call the operator function
	t3.join();


	//4. FUNCTOR WITH ARGUMENTS//
	FunctorOne F2;
	cout << "\n" << "4: ARGUMENTS FUNCTOR" << "\n";
	cout << "\n" << "BEFORE PASSING" << "\n";
	printf("\n x(%p) = % d\n y(%p) = % f\n p(%p) = % s\n", &x, x, &y, y, &p, p);
	std::thread t4(F2,x,std::ref(y),p); //Call the operator function
	t4.join();

	//5. LAMDA WITH NO ARGUMENTS//
	std::thread t5([]() {cout << "\n" << "5: LAMDA WITH NO ARGUMENTS" << "\n"; });
	t5.join();


	//6. LAMDA WITH ARGUMENTS//
	cout << "\n" << "6: LAMDA WITH ARGUMENTS" << "\n";
	int a = 95;
	float b = 40.0f;
	char* c = new char[7];
	memset(c, 0x0, 7);
	strcpy_s(c, 7, "Patric"); //One space of null terminator '\0' //
	cout << "\n" << "BEFORE PASSING" << "\n";
	printf("\n a(%p) = % d\n b(%p) = % f\n c(%p) = % s\n", &a, a, &b, b, &c, c);

	std::thread t6([](int a, float& b, char* c) 
		{ 
		  cout << "\n" << "AFTER PASSING" << "\n";
		  printf("\n a(%p) = % d\n b(%p) = % f\n c(%p) = % s\n", &a, a, &b, b, &c, c);
		},a,std::ref(b),c);
	t6.join();

	//7. LAMBA BY VALUE// 
	cout << "\n" << "7: LAMDA BY VALUE" << "\n";
	cout << "\n" << "BEFORE PASSING" << "\n";
	printf("\n a(%p) = % d\n b(%p) = % f\n c(%p) = % s\n", &a, a, &b, b, &c, c);
	std::thread t7([=]()
		{
			cout << "\n" << "AFTER PASSING" << "\n";
			printf("\n a(%p) = % d\n b(%p) = % f\n c(%p) = % s\n", &a, a, &b, b, &c, c);
		});
	t7.join();


	//8. LAMBA BY VALUE// 
	cout << "\n" << "8: LAMDA BY REFERENCE" << "\n";
	cout << "\n" << "BEFORE PASSING" << "\n";
	printf("\n a(%p) = % d\n b(%p) = % f\n c(%p) = % s\n", &a, a, &b, b, &c, c);
	std::thread t8([&]()
		{
			cout << "\n" << "AFTER PASSING" << "\n";
			printf("\n a(%p) = % d\n b(%p) = % f\n c(%p) = % s\n", &a, a, &b, b, &c, c);
		});
	t8.join();



	//8. MEMBER FUNCTION WITHOUT ARGUMENTS// 
	FunctorOne f1;
	std::thread t9(&FunctorOne::MemberFunction,f1);
	t9.join();


	FunctorOne f2;
	cout << "\n" << "9. MEMBER FUNCTION WITH ARGUMENTS" << "\n";
	cout << "\n" << "BEFORE PASSING" << "\n";
	printf("\n a(%p) = % d\n b(%p) = % f\n c(%p) = % s\n", &a, a, &b, b, &c, c);
	std::thread t10(&FunctorOne::MemberFunctionWArg, f2,a,std::ref(b),c);
	t10.join();


}



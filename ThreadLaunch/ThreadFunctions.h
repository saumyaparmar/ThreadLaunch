#ifndef THREAD_FUNCTIONS_H
#define THREAD_FUNCTIONS_H

class ThreadFunctions
{
public:
	ThreadFunctions() = default;
	ThreadFunctions(const ThreadFunctions&) = delete;
	ThreadFunctions& operator = (const ThreadFunctions&) = delete;
	~ThreadFunctions() = default;

public:
	//void T1_Main(); //NO ARGUMENTS//

	void operator() (); //Functor;

};

#endif
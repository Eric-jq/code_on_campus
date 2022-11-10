#pragma once
#include<pthread.h>
#include<iostream>
#include "CLExecutive.h"

class CLThread:public CLExecutive
{
public:
            CLThread(CLExecutiveFunctionProvider * pExecutiveFunctionProvider);
            ~CLThread();
            virtual void Run();
	virtual void WaitForDeath();
	private:
		static void *StartFunctionOfThread(void* pContext);
	private:
		pthread_t mthreadID;
};
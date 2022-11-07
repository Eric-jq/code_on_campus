#pragma once
#include "CLExecutive.h"
#include<pthread.h>
#include<iostream>
class CLThread:public CLExecutive
{
public:
            CLThread(CLExecutiveFunctionProvider * pExecutiveFunctionProvider)
            :CLExecutive(pExecutiveFunctionProvider){};
            ~CLThread();
            virtual void Run();
	virtual void WaitForDeath();
	private:
		static void *StartFunctionOfThread(void* pContext);
	private:
		pthread_t mthreadID;
};

CLThread::CLThread(CLExecutiveFunctionProvider * pExecutiveFunctionProvider)
{
}

CLThread::~CLThread(){}

void CLThread::Run(){
            int r=pthread_create(&mthreadID,0,StartFunctionOfThread,this);
	if(r != 0){
		std::cout<<"Error: fail to start a thread!"<<std::endl;
		return;
	}
}

void CLThread::WaitForDeath(){
	int r=pthread_join(mthreadID,0);
	if(r != 0){
		std::cout<<"Thread join error: ID = "<<mthreadID<<std::endl;
		return;
	}
}

void *CLThread::StartFunctionOfThread(void * pThis){
            CLThread* pThreadThis=(CLThread *)pThis;
	pThreadThis->m_pExecutiveFunctionProvider->RunExecutiveFunction();
	return 0;
}


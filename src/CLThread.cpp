#pragma once
#include "CLThread.h"
#include <pthread.h>


CLThread::CLThread(CLExecutiveFunctionProvider * pExecutiveFunctionProvider)
            :CLExecutive(pExecutiveFunctionProvider){};

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


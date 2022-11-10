#pragma once
#include<iostream>
#include"CLFindValue.h"
#include"CLInsertPiece.h"
#include"CLThread.h"

//using namespace std;
int main(){

            
           CLExecutiveFunctionProvider * actOnSheet1 = new CLFindValue(-300,300,1);
            CLThread *pThread1 = new CLThread(actOnSheet1 );
            //  CLExecutiveFunctionProvider *actOnSheet2 = new CLFindValue(30,1);
            // CLThread *pThread2 = new CLThread(actOnSheet2 );
            CLExecutiveFunctionProvider *actOnSheet3 = new CLInsertPiece();
            CLThread *pThread3 = new CLThread(actOnSheet3 );
            // CLExecutiveFunctionProvider *actOnSheet4 = new CLFindValue(-300,300,1);
            // CLThread *pThread4 = new CLThread(actOnSheet4 );

            pThread1->Run();
            // pThread2->Run();
            pThread3->Run();
            // pThread4->Run();

            pThread1->WaitForDeath();
            // pThread2->WaitForDeath();
            pThread3->WaitForDeath();
            // pThread4->WaitForDeath();
            // std::cout<<"BeforedeleteIN main"<<std::endl;
            Sheet *msheet = Sheet::GetSheet();
            // std::cout<<"after get in main"<<std::endl;
            delete msheet;
            // std::cout<<"after deletein main"<<std::endl;
}
#pragma once
#include"CLExecutiveFunctionProvider.h"
#include"Sheet.h"

class CLInsertPiece:public CLExecutiveFunctionProvider{
            public:
                        CLInsertPiece(){};
                        virtual void RunExecutiveFunction(){     
                                    std::cout<<"Start to insert..."<<std::endl;
                                    Sheet* msheet=Sheet::GetSheet();
                                    msheet->InsertPiece();
                        }
};
#pragma once
#include"CLExecutiveFunctionProvider.h"
#include"Sheet.h"

class CLInsertPiece:public CLExecutiveFunctionProvider{
            public:
                        CLInsertPiece();
                        virtual~ CLInsertPiece();
                        virtual void RunExecutiveFunction(){
                                    Sheet* msheet=Sheet::GetSheet();
                                    msheet->InsertPiece();
                        }

};
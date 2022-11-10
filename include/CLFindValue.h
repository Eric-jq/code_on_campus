#pragma once
#include "CLExecutiveFunctionProvider.h"
#include "Sheet.h"
#include <stdint.h>

class CLFindValue : public CLExecutiveFunctionProvider
{
public:
            // CLFindValue(int64_t minVal, int64_t maxVal, int colNum);
            // CLFindValue(int64_t minVal, int64_t colNum);
            CLFindValue(int64_t minVal, int64_t maxVal, int colNum):mminVal(minVal),mmaxVal(maxVal),mcolNum(colNum){
                                    flag = true;
                        };
            CLFindValue(int64_t minVal, int64_t  colNum):mminVal(minVal),mcolNum(colNum){
                                    flag = false;
                        };
            virtual void RunExecutiveFunction()
            {
                        Sheet *msheet = Sheet::GetSheet();
                        std::cout<<"Start to find..."<<std::endl;
                        if (flag)
                        {
                                    msheet->FindPieces(mminVal, mmaxVal, mcolNum);
                        }
                        else
                        {
                                    msheet->FindPieces(mmaxVal, mcolNum);
                        }
            }

private:
            bool flag;
            int64_t mminVal;
            int64_t mmaxVal;
            int mcolNum;
};
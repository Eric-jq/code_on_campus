#pragma once
#include"CLExecutiveFunctionProvider.h"
#include"Sheet.h"
#include<stdint.h> 
class CLFindValue:public CLExecutiveFunctionProvider{
            public:
                        CLFindValue(int64_t minVal, int64_t manVal, int colNum):mminVal(minVal),mmanVal(manVal),mcolNum(mcolNum){
                                    flag = true;
                        };
                          CLFindValue(int64_t minVal, int64_t  colNum):mminVal(minVal),mcolNum(mcolNum){
                                    flag = false;
                        };
                        virtual void RunExecutiveFunction(){
			Sheet* msheet=Sheet::GetSheet();
                                    if(flag){
                                                msheet->FindPieces(mminVal, mmanVal,mcolNum);
                                    }
                                    else{
                                                msheet->FindPieces(mmanVal,mcolNum);
                                    }
			
		}
                        
            private:
                        bool flag;
                        int64_t mminVal;
                        int64_t mmanVal;
                        int  mcolNum;
};
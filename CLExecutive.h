#pragma once

#include "CLExecutiveFunctionProvider.h"
class CLExecutive{
	public:
		explicit CLExecutive(CLExecutiveFunctionProvider *pExecutiveFunctionProvider)
                        {
			m_pExecutiveFunctionProvider=pExecutiveFunctionProvider;
		}
		virtual ~CLExecutive(){}
		virtual void Run()=0;
		virtual void WaitForDeath()=0;
	protected:
		CLExecutiveFunctionProvider *m_pExecutiveFunctionProvider;
};

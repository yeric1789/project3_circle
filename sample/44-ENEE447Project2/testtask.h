#ifndef _testtask_h
#define _testtask_h

#include <circle/sched/task.h>
#include <circle/screen.h>
#include <circle/types.h>
#include <circle/time.h>
 
class CTestTask : public CTask
{
public:
	CTestTask (CScreenDevice *pScreen);
	~CTestTask (void);

	void Run (void);

private:
	CScreenDevice  *m_pScreen;
	
};

#endif

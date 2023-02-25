#include "testtask.h"

#include <circle/sched/scheduler.h>
#include <circle/string.h>
#include <circle/util.h>
#include <circle/timer.h>

CTestTask::CTestTask (CScreenDevice *pScreen)
:	m_pScreen (pScreen)
{
}

CTestTask::~CTestTask (void)
{
}

void CTestTask::Run (void)
{
	CTimer *pTimer = CTimer::Get();

	time_t now, last_print_time;
	last_print_time = pTimer->GetTime();

	while (1) {
		now = pTimer->GetTime();
		if (now - last_print_time >= 1) {
			CString Line;
			Line.Format ("Task %s is running.\n", GetName());
			m_pScreen->Write (Line, Line.GetLength());
			
			last_print_time = now;
		}
	}
}

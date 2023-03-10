#include "testtask.h"

#include <circle/sched/scheduler.h>
#include <circle/string.h>
#include <circle/util.h>
#include <circle/timer.h>
#include <circle/logger.h>
#include "common.h"

CTestTask::CTestTask (void)
{
}

CTestTask::~CTestTask (void)
{
}

void CTestTask::Run (void)
{
#ifdef TEST_COOPERATIVE_MULTITASKING
	CLogger::Get ()->Write ("TestTask", LogDebug, "TestTask is done.");
#endif
}

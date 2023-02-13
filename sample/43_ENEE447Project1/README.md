# ENEE447 2023 Spring Project 1

## What are we doing in this project
- We will modify the scheduler in circle so that it implements priority scheduling
	- Currently, the scheduler is a ["cooperative non-preemtive scheduler that uses the round-robin policy, without priorities"](https://github.com/sklaw/circle/blob/master/include/circle/sched/scheduler.h#L31-L33).
		- What is a cooperative non-preemtive scheduler? Read this wikipedia on [cooperative multitasking](https://en.wikipedia.org/wiki/Cooperative_multitasking).
	- We want to modify it so that it will prioritize scheduling tasks with highest priority.

## How to test your solution
- Make and run [this sample](https://github.com/sklaw/circle/tree/master/sample/43_ENEE447Project1) on your Raspberry Pi.
- Originally, the three types of tasks (CScreenTask, CPrimeTask, CLEDTask) [here](https://github.com/sklaw/circle/blob/master/sample/43_ENEE447Project1/kernel.cpp#L84-L94) will run parallelly.
- After you implements prioritize scheduling, they should run serially in this order: CScreenTask->CPrimeTask->CLEDTask.
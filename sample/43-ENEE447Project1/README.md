# ENEE447 2023 Spring Project 1

## What are we doing in this project
- We will modify the scheduler in circle so that it implements priority scheduling.
	- Currently, the scheduler is a ["cooperative non-preemtive scheduler that uses the round-robin policy, without priorities"](https://github.com/sklaw/circle/blob/master/include/circle/sched/scheduler.h#L31-L33).
		- What is a cooperative non-preemtive scheduler? Read this wikipedia on [cooperative multitasking](https://en.wikipedia.org/wiki/Cooperative_multitasking).
	- We want to modify it so that it will prioritize scheduling tasks with highest priority.

## How to test your solution

- ~~Make and run [this sample](https://github.com/sklaw/circle/tree/master/sample/43_ENEE447Project1) on your Raspberry Pi.~~

- ~~Originally, the three types of tasks (CScreenTask, CPrimeTask, CLEDTask) [here](https://github.com/sklaw/circle/blob/master/sample/43-ENEE447Project1/kernel.cpp#L84-L94) will run parallelly.~~

- ~~After you implement prioritize scheduling, they should run serially in this order: CScreenTask->CPrimeTask->CLEDTask.~~
	- It turns out it is not easy to test priority scheduling using the three tasks in the sample because two of them (CScreenTask and CLEDTask) run forever and sleep for the most of time. 
	- **As an additional challenge in this project, you need to design a test for your implementation of priority scheduling.** 
	- (TAs will have some undisclosed tests for testing your code).

## What to submit on ELMS before your lab in the week of Feb 27:
1. A pdf that has:
	- Members of your group.
	- A brief description of the test you design for testing your solution and a brief reasoning of why the test shows your solution is correct.
	- A screenshot/photo that shows the test is passed.
1. The file `scheduler.cpp` in which you modified the function `GetNextTask`.
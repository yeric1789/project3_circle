# ENEE447 2023 Spring Project 1

## What are we doing in this project
- We will modify the scheduler in circle so that it implements priority scheduling.
	- Currently, the scheduler is a ["cooperative non-preemtive scheduler that uses the round-robin policy, without priorities"](https://github.com/sklaw/circle/blob/master/include/circle/sched/scheduler.h#L31-L33).
		- What is a cooperative non-preemtive scheduler? Read this wikipedia on [cooperative multitasking](https://en.wikipedia.org/wiki/Cooperative_multitasking).
	- We want to modify it so that it will prioritize scheduling tasks with highest priority.

## How to test your solution 
- **As an additional challenge in this project, you need to design a test for your implementation of priority scheduling.** (TAs will have some undisclosed tests for testing your code).
- Hint: The test can be developed based on the codes we already have in this sample. Specifically, you can modify the `Run` functions of [CScreenTask](screentask.cpp#L34-L51)/[CPrimeTask](primetask.cpp#L42-L84)/[CLEDTask](ledtask.cpp#L32-L47), then [create them in kernel.cpp with different priorities](kernel.cpp#L84-L94), then run the sample, then check the output to see whether those tasks are run from high priority to low priority.

### How to "run" a task?
- You may notice that every task defined here has a `Run` function, **does that mean we need to call a task's `Run` function ourselves to run the task? No.**
- Here is how a task starts running:
	- When we create an instance of a task, we will call `CTask`'s constructor because all tasks are subclasses of CTask. 
		- For example, [`CScreenTask` inherits `CTask` and thus is a subclass of `CTask`](screentask.h#L26).
	- [`CTask`'s constructor will call `InitializeRegs`](../../lib/sched/task.cpp#L48).
		- [`InitializeRegs` will initialize a task's `lr` register to point to `TaskEntry`](../..//lib/sched/task.cpp#L148).
			- **NOTE: This means when the scheduler schedules this task for the first time, the task will start running at `TaskEntry`.**
		- When scheduled to run, [`TaskEntry` will call the task's `Run` function](../..//lib/sched/task.cpp#L181).
			- Moreover, when the `Run` function returns, meaning the task is done, [`TaskEntry` will clean up the task by setting its state to `TaskStateTerminated` and yield to next task](../..//lib/sched/task.cpp#L183-L185).
	- [`Ctask`'s constructor will add the task to the scheduler](../..//lib/sched/task.cpp#L55) so that the task will be considered in future scheduling.

## What to submit on ELMS before your lab in the week of Feb 27:
1. A pdf that has:
	- Members of your group.
	- A brief description of the test you design for testing your solution and a brief reasoning of why the test shows your solution is correct.
	- A screenshot/photo that shows the test is passed.
1. The file `scheduler.cpp` in which you have modified the function `GetNextTask`.


## FAQs
### 1. How do I run this sample in qemu?
- First, install qemu on your computer.
	- If you are using MacOS, follow [these instructions](https://www.qemu.org/download/#macos).
	- If you are using Linux, follow [these instructions](https://www.qemu.org/download/#linux).
	- If you are using Windows, follow [these instructions](https://www.qemu.org/download/#windows).
- Then, type `qemu-system-arm --version` in your terminal to make sure it has been sucessfully installed.
- Then, cd into the root directory of circle and type:
	- `./configure --qemu -f`
	- `./makeall clean && ./makeall`
- You should have `sample/43-ENEE447Project1/kernel.img` generated if the compilation is successful.
- Then, to run the generated kernel in qemu, type `qemu-system-arm -M raspi0 -bios sample/43-ENEE447Project1/kernel.img `
	- A new Window should pop up which emulates the code running on Raspberry Pi Zero.

### 2. How do I run this sample on my Raspberry Pi?
- Follow these [instructions](https://github.com/sklaw/circle#installation).

### 3. After I modify some codes, how do I compile and get the latest kernel?
- If you have modified source codes of the library (any code in `lib` or `include`), run `./makeall clean && ./makeall`.
- If you have modified _only_ codes in the sample but not in the library, run `cd sample/43-ENEE447Project1/`, then run `make clean && make`.


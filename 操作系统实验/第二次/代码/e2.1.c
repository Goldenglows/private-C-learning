#include <unistd.h>
#include <stdio.h>

int main(){
	//调用fork()系统调用创建新进程
	pid_t PID = fork();
	
	//创建新进程出错
	if(PID < 0){
		printf("fork error!\n");
		return -1;
	}

	//子进程执行代码
	else if(PID == 0)
		printf("I'm the child process, my PID is %d, my parent's PID is %d\n", getpid(), getppid());

	//父进程执行代码
	else
		printf("I'm the parent process, my PID is %d, my child's PID is %d\n", getpid(), PID);

	return 1;
}

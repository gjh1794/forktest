#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#define CHILD_NUM 3

int main() {
	printf("I'm parent.\n");
	for(int i = 0; i < CHILD_NUM; i++) {
		pid_t pid = fork();
		if(pid < 0) {
			printf("fork failed.\n");
			exit(1);
		}
		else if(pid == 0) {
			//in child process
			char* argvec[] = {"./cmd_args", "test", "TEST", NULL};
			if(execvp(argvec[0], argvec) < 0) {
				printf("Exec Fails.\n");
				exit(1);
			}
			printf("end of exec.\n");
			exit(0);
		}
	}
	wait(NULL);
	printf("Parent process is doing something here.\n");
}

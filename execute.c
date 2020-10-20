#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<unistd.h> 


void execute_normal(char **argv);
void execute_redirect(char **argv, char *outPath);

void execute_normal(char **argv)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0) 
	{
		perror("ERROR! Fork failed");
		printf("\n");
		exit(1);
	}
	else if (pid == 0) //child process
	{
		if (execvp(*argv, argv) < 0)
		{
			perror("ERROR! Cannot execute process");
			exit(1);
		}	
	}
	else
	{
		while (wait(&status) != pid) {} //parent, waits for completion
	}

}

void execute_redirect(char **argv, char *outPath)
{
	pid_t pid;
	int status;
	int defout;
	int fd;

	pid = fork();
	if (pid < 0) 
	{
		perror("ERROR! Fork failed");
		printf("\n");
		
		exit(1);
	}
	else if (pid == 0) //child thread
	{
		defout = dup(1);
		fd=open(outPath,O_RDWR|O_CREAT,0644);
		dup2(fd,1);
		if (execvp(*argv, argv) < 0)
		{
			perror("ERROR! Cannot execute process");
			exit(1);
		}
		close(fd);	
	}
	else
	{
		while (wait(&status) != pid) {} //parent, waits for completion
	}

}

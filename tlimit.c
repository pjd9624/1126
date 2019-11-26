#include <stdio.h>
#include <unistd.h>
#include <signal.h>
int pid;
void alarmHandler();

int main(int argc, char*argv[])
{
	int child, sttus, limit;
	signal(SIGALRM, alarmHandler);
	sscanf(argv[1], "%d", &limit);
	alarm(limit);
	pid = fork();
	if(pid == 0){
		execvp(argv[2], &argv[2]);
		fprintf(stderr, "%s: ����ζ�\n", argv[1]);
	} else {
		child = wait(&status);
		printf("[%d]�ڽ� ���μ��� %d ����\n", getpid(), pid);
	}
}
void alarmHandler()
{
	printf("[�˶�] �ڽ� ���μ��� %d �ð� �ʰ�\n", pid);
	kill(pid, SIGINT);
}

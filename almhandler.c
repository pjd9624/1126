#include <stdio.h>
#include <signal.h>

void alarmHandler();

int main()
{
	signal(SIGALRM, alarmHandler);
	alarm(5);
	printf("���ѷ���\n");
	while(1){
		sleep(1);
		printf("1�� ���\n");
	}
	printf("������� ����\n");
}
void alarmHandler()
{
	printf("�Ͼ����\n");
	exit(0);
}

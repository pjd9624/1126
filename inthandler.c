#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void intHandler();

int main()
{
	signal(SIGINT, intHandler);
	while(1)
		pause();
	printf("������� ����\n");
}
void intHandler(int signo)
{
	printf("���ͷ�Ʈ �ñ׳� ó��\n");
	printf("�ñ׳� ��ȣ: %d\n", signo);
	exit(0);
}

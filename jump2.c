#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <signal.h>
void p1();
void intHandler();
jmp_buf env;

int main() 
{
    signal(SIGINT, intHandler);
    if (setjmp(env) != 0) {
         printf("���͸�Ʈ�� ���� ����\n");
         exit(0);
    }
    else printf("ó�� ���\n");
    p1(); 
} 
void p1()
{ 
    while (1) {
        printf("����\n");
        sleep(1);
    }
}

void intHandler() 
{

    printf("���ͷ�Ʈ\n");
    longjmp(env, 1);
}


#include <stdio.h>
#include <stdlib.h>
#include <setjump.h>
void p1(),p2();
jmp_buf env;

int main()
{
	if(setjum(env)!=0){
		printf("������ ���� ����\n");
		exit(0);
	}
	else printf("ó�� ���\n");
	
	p1();
}
void p1()
{
	p2();
}
void p2()
{
    int error;
    
    error = 1;
    if (error) {
        printf("���� \n");
        longjmp(env, 1);
    }
}


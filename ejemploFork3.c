#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	int num = 0;
	int nuevo;

	for (num= 0; num< 2; num++) 
	{
		nuevo= fork();
		wait();
		if (nuevo== 0)
			break;
	}

	nuevo= fork();
	wait();		
	nuevo= fork();
	wait();
	printf("Soy el proceso %d y mi padre es %d\n", getpid(), getppid());
	return 0;
}

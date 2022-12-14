/*************************************************************************
    > File Name: main.c
    > Author: Schorsch
    > Mail: sh19931026@163.com
    > Created Time: Mi 27 Jul 2022 17:29:32 CEST
    > Description: 
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "%s: invalid number of arguments\n", argv[0]);
		return 1;
	}
	char *expr=argv[1];
	printf(".globl main\n");
	printf("main:\n");
	printf("  li a0, %ld\n",strtol(expr,&expr,10));
	while(*expr)
	{
		if(*expr=='+')
		{
			++expr;
			printf("  addi a0, a0, %ld\n", strtol(expr,&expr,10));
			continue;
		}
		if(*expr=='-')
		{
			++expr;
			printf("  addi a0, a0, -%ld\n", strtol(expr,&expr,10));
			continue;
		}
	}
//	printf(" li a0, %d\n", atoi(argv[1]));
	printf(" ret\n");

	return 0;
}


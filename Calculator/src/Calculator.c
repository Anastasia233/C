/*
 ============================================================================
 Name        : Calculator.c
 Author      : Anastasia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	float a,b,c;
	printf("������� ����� a: ");
	scanf("%f", &a);

	int k;
	printf("������� �������: ");
	scanf("%i", &k);
	if (k!=5) {
		printf("������� ����� b: ");
		scanf("%f", &b);
	}
	switch(k) {
		case 1:					//��������
			printf("%.2f", a+b);
			break;
		case 2:					//���������
			printf("%.2f", a-b);
			break;
		case 3:					//���������
			printf("%.2f", a*b);
			break;
		case 4:					//�������
			printf("%.2f", a/b);
			break;
		case 5:					//���������
			c=1;
			for(int i = 1; i<=a; i++) {
				c = c*i;
			}
			printf("%.2f", c);
			break;
		case 6:					//���������� � �������
			c = a;
			if (b!=0) {
				for(int i=1; i<b; i++) {
					a = a*c;
				}
				printf("%.2f", a);
			}
			else
				puts("1");
			break;
		default:
			printf("����� ������� �� ����������");
			break;

	}
	return EXIT_SUCCESS;
}

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
	printf("Введите число a: ");
	scanf("%f", &a);

	int k;
	printf("Введите команду: ");
	scanf("%i", &k);
	if (k!=5) {
		printf("Введите число b: ");
		scanf("%f", &b);
	}
	switch(k) {
		case 1:					//Сложение
			printf("%.2f", a+b);
			break;
		case 2:					//Вычитание
			printf("%.2f", a-b);
			break;
		case 3:					//Умножение
			printf("%.2f", a*b);
			break;
		case 4:					//Деление
			printf("%.2f", a/b);
			break;
		case 5:					//Факториал
			c=1;
			for(int i = 1; i<=a; i++) {
				c = c*i;
			}
			printf("%.2f", c);
			break;
		case 6:					//Возведение в степень
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
			printf("Такой команды не существует");
			break;

	}
	return EXIT_SUCCESS;
}

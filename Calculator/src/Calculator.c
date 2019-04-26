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
int nmb() {
	float a, b, c;
	printf("Enter the first number a: ");
	scanf("%f", &a);

	int k;
	printf("All commands: \n 1 - Addition\n 2 - Subtraction\n 3 - Multiplication\n 4 - Division\n 5 - Factorial\n 6 - Involution or Raise to power\n");
	printf("Enter the command: ");
	scanf("%i", &k);
	if (k != 5) {
		printf("Enter the second number b: ");
		scanf("%f", &b);
	}
	switch (k) {
	case 1:					//Сложение
		printf("%.2f", a + b);
		break;
	case 2:					//Вычитание
		printf("%.2f", a - b);
		break;
	case 3:					//Умножение
		printf("%.2f", a * b);
		break;
	case 4:					//Деление
		printf("%.2f", a / b);
		break;
	case 5:					//Факториал
		c = 1;
		for (int i = 1; i <= a; i++) {
			c = c * i;
		}
		printf("%.2f", c);
		break;
	case 6:					//Возведение в степень
		c = a;
		if (b != 0) {
			for (int i = 1; i < b; i++) {
				a = a * c;
			}
			printf("%.2f", a);
		} else
			puts("1");
		break;
	default:
		printf("This command doesn't exist");
		break;
	}
	return EXIT_SUCCESS;
}
float vct() {
	float *V1, *V2; //Вектор 1 и вектор 2
	int size; //Размертность вектора
	printf("Enter the number of coordinates of vectors: ");
	scanf("%i", &size);
	if (size != 0) {
		V1 = calloc(size, sizeof(V1));
		V2 = calloc(size, sizeof(V2));
	}
	printf("Enter coordinates of first vector: ");
	for (int i = 0; i < size; i++) {
		scanf("%f",&V1[i]);
	}
	printf("Enter coordinates of second vector: ");
	for (int i = 0; i < size; i++) {
		scanf("%f",&V2[i]);
	}
	int k;
	printf("All commands: \n 1 - Addition\n 2 - Subtraction\n 3 - Scalar product\n");
	printf("Enter the command: ");
	scanf("%i", &k);
	printf("Result: ");
	float c=0;
	switch(k) {
		case 1: //Сложение векторов
			printf("Coordinates of new vector: ");
			for (int i = 0; i < size; i++) {
				printf("%.1f ",V1[i]+V2[i]);
			}
			break;
		case 2: //Вычитание векторов
			printf("Coordinates of new vector: ");
			for (int i = 0; i < size; i++) {
				printf("%.1f ",V1[i]-V2[i]);
			}
			break;
		case 3: //Скалярное произведение векторов
			for(int i = 0; i < size; i++)
				c = c + V1[i]*V2[i];
			printf("%.1f", c);
			break;
		}
		free(V1);
		free(V2);
	return EXIT_SUCCESS;
}

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int w;
	printf("All kind of calculator: \n 1 - calculator with numbers\n 2 - calculator with vectors\n");
	printf("Enter kind of calculator: ");
	scanf("%i", &w);
	switch (w) {
	case 1:
		nmb();
		break;
	case 2:
		vct();
		break;
	default:
		printf("This calculator doesn't exist");
		break;
	}
	return EXIT_SUCCESS;
}

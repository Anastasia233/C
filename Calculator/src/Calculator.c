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
		scanf("%f", &V1[i]);
	}
	printf("Enter coordinates of second vector: ");
	for (int i = 0; i < size; i++) {
		scanf("%f", &V2[i]);
	}
	char k;
	printf(
			"All commands: \n 1 - Addition\n 2 - Subtraction\n 3 - Scalar product\n");
	printf("Enter the command: ");
	scanf("%c", &k);
	printf("Result: ");
	float c = 0;
	switch (k) {
	case '+': //Сложение векторов
		printf("Coordinates of new vector: ");
		for (int i = 0; i < size; i++) {
			printf("%.1f ", V1[i] + V2[i]);
		}
		break;
	case '-': //Вычитание векторов
		printf("Coordinates of new vector: ");
		for (int i = 0; i < size; i++) {
			printf("%.1f ", V1[i] - V2[i]);
		}
		break;
	case '*': //Скалярное произведение векторов
		for (int i = 0; i < size; i++)
			c = c + V1[i] * V2[i];
		printf("%.1f", c);
		break;
	}
	free(V1);
	free(V2);
	return EXIT_SUCCESS;
}
void nmb_file(FILE *file, char op, FILE *result) {
	float a, b, r;
	if (op == '!')
		fscanf(file, "%f", &a);
	else
		fscanf(file, "%f %f", &a, &b);
	switch (op) {
	case '+':
		fprintf(result, "%.0f %c %.0f = %.0f", a, op, b, a + b);
		break;
	case '-':
		fprintf(result, "%.0f %c %.0f = %.0f", a, op, b, a - b);
		break;
	case '*':
		fprintf(result, "%.0f %c %.0f = %.0f", a, op, b, a * b);
		break;
	case '/':
		fprintf(result, "%.0f %c %.0f = %.0f", a, op, b, a / b);
		break;
	case '!':
		r = 1;
		for (int i = 1; i <= a; i++) {
			r = r * i;
		}
		fprintf(result, "%.0f ! = %.0f", a, r);
		break;
		break;
	case '^':
		r = a;
		if (b != 0) {
			for (int i = 1; i < b; i++) {
				a = a * r;
			}
			fprintf(result, "%.0f ^ %.0f = %.0f", r, b, a);
		} else
			fprintf(result, "%.0f ^ %.0f = 1", r, b);
		break;
		break;

	}
}
void vct_file(FILE *file, char op, FILE *result) {
	float *V1, *V2;
	int size;
	fscanf(file, "%i", &size);
	V1 = calloc(size, sizeof(V1));
	V2 = calloc(size, sizeof(V2));
	for (int i = 0; i < size; i++)
		fscanf(file, "%f", &V1[i]);
	for (int i = 0; i < size; i++)
		fscanf(file, "%f", &V2[i]);
	float r = 0;
	switch (op) {
	case '+':
		fprintf(result, "(");
		for (int i = 0; i < size; i++) {
			if (i == size - 1)
				fprintf(result, "%.0f", V1[i]);
			else
				fprintf(result, "%.0f ", V1[i]);
		}
		fprintf(result, ") + (");
		for (int i = 0; i < size; i++) {
			if (i == size - 1)
				fprintf(result, "%.0f", V2[i]);
			else
				fprintf(result, "%.0f ", V2[i]);
		}
		fprintf(result, ") = (");
		for (int i = 0; i < size; i++) {
			if (i == size - 1)
				fprintf(result, "%.0f", V1[i] + V2[i]);
			else
				fprintf(result, "%.0f ", V1[i] + V2[i]);
		}
		fprintf(result, ")");
		break;
	case '-':
		fprintf(result, "(");
		for (int i = 0; i < size; i++) {
			if (i == size - 1)
				fprintf(result, "%.0f", V1[i]);
			else
				fprintf(result, "%.0f ", V1[i]);
		}
		fprintf(result, ") + (");
		for (int i = 0; i < size; i++) {
			if (i == size - 1)
				fprintf(result, "%.0f", V2[i]);
			else
				fprintf(result, "%.0f ", V2[i]);
		}
		fprintf(result, ") = (");
		for (int i = 0; i < size; i++) {
			if (i == size - 1)
				fprintf(result, "%.0f", V1[i] - V2[i]);
			else
				fprintf(result, "%.0f ", V1[i] - V2[i]);
		}
		fprintf(result, ")");
		break;
	case '*':
		for (int i = 0; i < size; i++)
			r = r + V1[i] * V2[i];
		fprintf(result, "<a,b> = %.0f", r);
		break;
	}
}
float c_file() {
	char op, c;
	FILE *file, *result;
	file = fopen("file.txt", "r");
	result = fopen("result.txt", "w");
	while (!feof(file)) {
		fscanf(file, " %c %c", &op, &c);
		if (c == 'v') {
			vct_file(file, op, result);
		} else {
			nmb_file(file, op, result);
		}
		fprintf(result, "\n");
	}
	fclose(file);
	fclose(result);
	return EXIT_SUCCESS;
}

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int w;
	printf(
			"All kind of calculator: \n 1 - calculator with numbers\n 2 - calculator with vectors\n 3 - calculator with file\n");
	printf("Enter kind of calculator: ");
	scanf("%i", &w);
	switch (w) {
	case 1:
		nmb();
		break;
	case 2:
		vct();
		break;
	case 3:
		c_file();
		break;
	default:
		printf("This calculator doesn't exist");
		break;
	}
	return EXIT_SUCCESS;
}


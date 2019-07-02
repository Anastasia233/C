/*
 ============================================================================
 Name        : LIST.c
 Author      : Anastasia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// Структура, где хранятся исходные данные из файла
typedef struct list {
	char operation;
	char calculator;
	int size;
	float *A;
	float *B;
	struct list *next;
} list;

// Структура, где хранится результат выполнения калькулятора
typedef struct list_of_result {
	float* result;
	struct list_of_result *next;
} list_of_result;

// Функция получения последнего элемента списка
list* get_last_element_list(list* element){ //getLastData
	if(element == NULL){
		return NULL;
	}
	while(element->next){
		element = element->next;
	}
	return element;
}
list_of_result* getLastResult(list_of_result* element){
	if(element == NULL){
		return NULL;
	}
	while(element->next){
		element = element->next;
	}
	return element;
}
												  // Функция добавления первого элемента
void add_head_list(list** head, FILE* read_file){ //addHeadData, element_n = tmp
	list* element_n = (list*)malloc(sizeof(list));
	fscanf(read_file, "%c %c", &element_n->operation, &element_n->calculator); // Читаем первые два символа из файла и записываем их в элемент списока
	if(element_n->calculator == 'v'){
		fscanf(read_file, "%d", &element_n->size);
	} else {
		element_n->size = 1;
	}
	element_n->A = malloc(element_n->size * sizeof(float));
	element_n->B = malloc(element_n->size * sizeof(float));
	for(int i = 0; i < element_n->size; i++){				// Считываем числа в первую переменную
		fscanf(read_file, "%f", &element_n->A[i]);
	}

	for(int i = 0; i < element_n->size; i++){     // Считываем числа в вторую переменную
		fscanf(read_file, "%f", &element_n->B[i]);
	}
	element_n->next = (*head);
	(*head) = element_n;
}

void Calculator_with_nmb(list* element, list_of_result* result);
void Calculator_with_vct(list* element, list_of_result* result);

void add_head_element_result(list* element, list_of_result** head_main){ //addHeadResult
	list_of_result* element_n = (list_of_result*)malloc(sizeof(list_of_result));// Выделяем память для временного елемента списка с результатами
	if(element->calculator == 'v')
		Calculator_with_vct(element, element_n);
	else
		Calculator_with_nmb(element, element_n);
	element_n->next = (*head_main);
	(*head_main) = element_n;
}

// Функция добавления элемента в конец списка
void add_end_list(list* head_main, FILE* disaster){
	list* last = get_last_element_list(head_main);
	list* element_n = (list*)malloc(sizeof(list));
	fscanf(disaster, " %c %c", &element_n->operation, &element_n->calculator);
	if(element_n->calculator == 'v'){
		fscanf(disaster, "%d", &element_n->size);
	} else {
		element_n->size = 1;
	}
	element_n->A = malloc(element_n->size * sizeof(float));
	element_n->B = malloc(element_n->size * sizeof(float));

	for(int i = 0; i < element_n->size; i++){				 // Считываем числа в первую переменную
		fscanf(disaster, "%f", &element_n->A[i]);
	}

	for(int i = 0; i < element_n->size; i++){		// ...затем во вторую
		fscanf(disaster, "%f", &element_n->B[i]);
	}
	element_n->next = NULL;
	last->next = element_n;
}

// Функция добавления результата в другой список
void add_result_list(list* element, list_of_result* head_main){ //addResult
	list_of_result* last = getLastResult(head_main);
	list_of_result* element_n = (list_of_result*)malloc(sizeof(list_of_result)); // Создаём временный элемент
	if(element->calculator == 'v')
		Calculator_with_vct(element, element_n);
	else
	 Calculator_with_nmb(element, element_n);
	element_n->next = NULL;
	last->next = element_n;
}
void Calculator_with_nmb (list* element, list_of_result* result) {
	result->result = malloc(sizeof(float));
	switch(element->operation){
	case '+':
		result->result[0] = element->A[0] + element->B[0];
		break;
	case '-':
		result->result[0] = element->A[0] - element->B[0];
		break;
	case '*':
		result->result[0] = element->A[0] * element->B[0];
		break;
	case '/':
		result->result[0] = element->A[0] / element->B[0];
		break;
	case '^':
		result->result[0] = element->A[0];
		if (element->B[0] != 0) {
			for (int i = 1;i < element->B[0]; i++) {
				result->result[0] = result->result[0] * element->A[0];
			}
		} else
		result->result[0] = 1;
		break;
	case '!':
		result->result[0] = 1;
		for (int i = 1; i <= element->A[0]; i++) {
			result->result[0] = result->result[0] * i;
		}
		break;
	}
}

void Calculator_with_vct(list* element, list_of_result* result) {
	result->result = malloc(element->size * sizeof(float));
	switch(element->operation){
	case '+':
		for(int i = 0; i < element->size; i++){
			result->result[i] = element->A[i] + element->B[i];
		}
		break;
	case '-':
		for(int i = 0; i < element->size; i++){
			result->result[i] = element->A[i] - element->B[i];
		}
		break;
	case '*':
		for(int i = 0; i < element->size; i++){
			result->result[i] = element->A[i] * element->B[i];
		}
		break;
	}
}

void write_in_file(list* element, list_of_result* result, FILE* disaster){
	if(element->calculator == 'v' && element->operation != '*'){
		fprintf(disaster, "(");
		for (int i = 0; i < element->size; i++) {
			fprintf(disaster, "%.0f", element->A[i]);
			if (i != element->size - 1) fprintf(disaster, " ");
		}
		fprintf(disaster, ") %c (", element->operation);
		for (int i = 0; i < element->size; i++) {
			fprintf(disaster, "%.0f", element->B[i]);
			if (i != element->size - 1) fprintf(disaster, " ");
		}
		fprintf(disaster, ") = (");
		for (int i = 0; i < element->size; i++) {
			fprintf(disaster, "%.0f", result->result[i]);
			if (i != element->size - 1)
				fprintf(disaster, " ");
		}
		fprintf(disaster, ")");
	} else {
		if (element->calculator == 'v') {
			fprintf(disaster, "(a, b) = ");
		} else if (element->operation != '!') {
			fprintf(disaster, "%.0f %c %.0f = ", element->A[0], element->operation, element->B[0]);
		} else {
			fprintf(disaster, "%.0f! = ", element->A[0]);
		}
		fprintf(disaster, "%.0f", result->result[0]);
	}
	fprintf(disaster, "\n");
}

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	FILE *file, *disaster;
	file = fopen("file.txt", "r");
	disaster = fopen("result.txt", "w");
	list* head_main = NULL; //Начало списка
	add_head_list(&head_main, disaster); // Записываем данные первого калькулятора в начало списка
	while(!feof(file)){
		add_end_list(head_main, file);
	}
	list* start_list = head_main;  // Создаём start_list, чтобы не потерять начало списка
	list_of_result* start_result = NULL;
	add_head_element_result(start_list, &start_result); // Записываем первый результат в другой список

	start_list = start_list->next;
	// Записываем оставшиеся результаты в другой список, если они имеются
	while(start_list){
		add_result_list(start_list, start_result);
		start_list = start_list->next;
	}

	list_of_result* sign_result = start_result;
	start_list = head_main;
	while(start_list){
		write_in_file(start_list , sign_result, disaster);
		start_list = start_list->next;
		sign_result = sign_result->next;
	}
	fclose(file);
	fclose(disaster);
	return EXIT_SUCCESS;
}

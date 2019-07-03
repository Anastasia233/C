/*
 ============================================================================
 Name        : calculator_5.c
 Author      : Anastasia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
//стек

typedef struct list {
	int size;
	char *element;
	struct list *next;
} list;

typedef struct stack { //cтек для хранения результатов
	float result;
	struct stack *next;
} stack;

typedef struct number {  //cписок для хранения чисел
	char value;
	struct number *next;
} number;

list *get_last_element(list* head_end) { // функция, которая находит последний элемент списка
	if (head_end == NULL)
		return NULL;
	while (head_end->next) { 			//пока существует след элем, переходим к нему
		head_end = head_end->next;
	}
	return head_end;
}

list* put_last_list(FILE* file, char c) { 		//функция добавления последнего элемента в список
	number* head_list = (number*) malloc(sizeof(number));
	number* last_list = (number*) malloc(sizeof(number));
	last_list = head_list;
	list* element_n = (list*) malloc(sizeof(list));
	int size = 0;
	while (c != ' ') {
		size++;
		if (size == 1) {
			head_list->value = c;
			head_list->next = NULL;
			last_list = head_list;
		} else {
			element_n->next = NULL;
			number* element_n_number = (number*) malloc(sizeof(number));
			element_n_number->value = c;
			element_n_number->next = NULL;
			last_list->next = element_n_number;
			last_list = last_list->next;
		}
		//если это конец файла, то выполняется выход из цикла
		if (feof(file) != 0) {
			break;
		} else {  //если не конец файла, то считываются следующие символы
			if (c != '$')
				fscanf(file, "%c", &c);
			else
				break;
		}
	}
	last_list = head_list;
	element_n->size = size;
	element_n->element = malloc(size * sizeof(char));
	for (int i = 0; i < size; i++) {
		element_n->element[i] = last_list->value;
		if (last_list->next)
			last_list = last_list->next;
	}
	return element_n;
}

stack* add_elements(char *number, stack* headstack) { //добавление чисел в стек
	stack* element_n = (stack*) malloc(sizeof(stack));
	element_n->next = headstack;
	element_n->result = atof(number);
	return element_n;
}

stack* Disaster(char operation, stack* element) {
	switch (operation) {
	case '+':
		element->next->result = element->next->result + element->result;
		break;

	case '-':
		element->next->result = element->next->result - element->result;
		break;

	case '*':
		element->next->result = element->next->result * element->result;
		break;

	case '/':
		element->next->result = element->next->result / element->result;
		break;
	}
	free(element);
	return element->next;
}
int main(void) {
	FILE *file_R, *file_W;
	file_R = fopen("file.txt", "r");
	char c;
	list* head_list = (list*) malloc(sizeof(list));
	fscanf(file_R, "%c", &c);
	head_list = put_last_list(file_R, c); //создаем 1й элемент  списка
	list* current = (list*) malloc(sizeof(list));
	current = head_list;
	//читаем операции
	while (!feof(file_R)) {
		fscanf(file_R, "%c", &c);
		current->next = put_last_list(file_R, c);
		current = current->next;
	}
	fclose(file_R);


	current = head_list;//возвращаемся в начало списка
	file_W = fopen("result.txt", "w");
	stack* headstack = (stack*) malloc(sizeof(stack*));
	headstack = add_elements(current->element, headstack);
	current = current->next;

	while (current) {
		if (current->element[0] != '$') {
			if (current->element[0] == '+'
					|| (current->element[0] == '-' && current->size == 1)
					|| current->element[0] == '*'
					|| current->element[0] == '/') {
				headstack = Disaster(current->element[0], headstack);

			} else
				headstack = add_elements(current->element, headstack);
			current = current->next;
		} else {
			fprintf(file_W, "%.0f\n", headstack->result);
			headstack = headstack->next;
			current = current->next;
		}
	}
	fclose(file_W);

	return EXIT_SUCCESS;
}

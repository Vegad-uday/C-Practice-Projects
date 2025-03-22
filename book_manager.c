#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
struct books {
	char *title, *author_name;
	int pages;
	struct books *next;

}*head;
 
void add_book();
void show_book();
void search_book();
void delete_book();
 
void not_assigned() {
	printf("Memory Not Assigned To Book Detail:\n");
	exit(1);
}
 
void books_info(struct books *temp) {
	printf("Enter Book Name: ");
	temp->title = (char *)malloc(100 * sizeof(char));
	
	if (temp->title == NULL) {
		not_assigned();
	}
	scanf(" %[^\n]s", temp->title);
	temp->title = realloc(temp->title, strlen(temp->title) + 1);
	
	if (temp->title == NULL) {
		not_assigned();
	}
 
	printf("Enter Author Name: ");
	temp->author_name = (char *)malloc(100 * sizeof(char));
	if (temp->author_name == NULL) {
		not_assigned();
	}

	scanf(" %[^\n]s", temp->author_name);
	temp->author_name = realloc(temp->author_name, strlen(temp->author_name) + 1);
	if (temp->author_name == NULL) {
		not_assigned();
	}
 
	printf("Enter Book pages: ");
	scanf("%d", &temp->pages);
	if (temp->pages == 0) {
		printf("\nBook Pages Are Not Allowed\nPlease Try Again later\n");
		exit(1);
	}
	printf("\n");
}
 
void add_book() {
	struct books *temp, *new_book;
 
	temp = (struct books *)malloc(sizeof(struct books));
	if (temp == NULL) {
		printf("Memory Not Assigned to Structure\n");
		exit(1);
	}
 
	books_info(temp);
	temp->next = NULL;
 
	if (head == NULL) {
		head = temp;
	} 
	else {
		new_book = head;
		while (new_book->next != NULL) {
			new_book = new_book->next;
		}
	new_book->next = temp;
	}
}
 
void show_book() {
	struct books *print;
	print = head;
	if (head == NULL) {
		printf("\nDon't Have Any Book on List:\nFirst Add Book Details:\n\n");
	}
	while (print != NULL) {
		printf("Book Name: %s\n", print->title);
		printf("Author Name: %s\n", print->author_name);
		printf("Book Pages: %d\n", print->pages);
		printf("\n");
 
		print = print->next;
	}
}
 
void search_book() {
	struct books *find;
	char *book;
 
	book = (char *)malloc(1000 * sizeof(char));
	if (book == NULL) {
		printf("Memory Not Allocated to Book\nPlease Try Again later\n");
		exit(1);
	}
 
	printf("Enter Book Name for Search Book Details: ");
	scanf(" %[^\n]", book);
	book = realloc(book, strlen(book) + 1);
	if (book == NULL) {
		printf("Memory Not Allocated to Book\nPlease Try Again later\n");
		exit(1);
	}
 
	if (book[0] == '\0') {
		printf("You did not Enter Book Name.\n");
		free(book);
	return;
	}
 
	find = head;
 
	int f = 0;
 
	while (find != NULL) {
		if (!(strcmp(book, find->title))) {
			printf("Book Name: %s\n", find->title);
			printf("Author Name: %s\n", find->author_name);
			printf("Book Pages: %d\n", find->pages);
			printf("\n");
			
			f = 1;
		}
		find = find->next;
	}
 
	if (f == 0) {
		printf("Book Not Found\n\n");
	}
	free(book);
}
 
void delete_book() {
	struct books *delete, *prev;
	char *book;
 
	book = (char *)malloc(100 * sizeof(char));
	if (book == NULL) {
		printf("Memory Not Allocated to Book\nPlease Try Again later\n");
		exit(1);
	}
 
	printf("Enter Book Name to Delete: ");
	scanf(" %[^\n]", book);
	book = realloc(book, strlen(book) + 1);
	
	if (book == NULL) {
		printf("Memory Not Allocated to Book\nPlease Try Again later\n");
		exit(1);
	}
 
	if (book[0] == '\0') {
		printf("You did not Enter Book Name.\n");
		free(book);
		return;
	}
 
	prev = NULL;
	delete = head;
 
	while (delete != NULL) {
		if (strcmp(delete->title, book) == 0) {
			if (prev == NULL) {
				head = delete->next;
			} else {
				prev->next = delete->next;
			}
			printf("Book Deleted Successfully!\n\n");
			
			free(delete->title);
			free(delete->author_name);
			free(delete);
			break;
		}
		prev = delete;
		delete = delete->next;
	}
 
	if (delete == NULL) {
		printf("Book Not Found.\nPlease Try Again Leter\n\n");
	}
 
	free(book);
}
 
int main() {
	while (1) {
		int input;
		printf("Enter 1.For Add Book\nEnter 2.For Show Books\nEnter 3.For Search Book\nEnter 4.For Delete\nEnter 5.For Exit : ");
		scanf(" %d", &input);
		printf("\n");
		if (input >= 5) {
			printf("You Eneterd Wrong Option\nPlease Try Again later\n");
			exit(1);
		}
		switch (input) {
			case 1:
				add_book();
				break;
			case 2:
				show_book();
				break;
			case 3:
				search_book();
				break;
			case 4:
				delete_book();
				break;
			case 5:
				exit(0);
			default:
				printf("You Entered a Wrong Option\n");
				exit(1);
		}
	}
 
	return 0;
}

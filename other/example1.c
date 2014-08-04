#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct addr {
	char name[20];
	char street[20];
	char city[20];
	char state[20];
	int zip;
} addr_list[MAX];

void init(void);
void enter(void);
void delete(void);
void list(void);
void save(void);
void load(void);
int menu_select(void);
int find_free(void);

int main(void) {
	int choice;
	init();
	while(1) {
		choice = menu_select();
		switch(choice) {
			case 1: enter(); break;
			case 2: delete(); break;
			case 3: list(); break;
			case 4: save(); break;
			case 5: load(); break;
			case 6: exit(0);
		}
	}
	return 0;
}

void init(void) {
	for (int i = 0; i < MAX; i++) {
		addr_list[i].name[0] = '\0';
	}
}

void enter(void) {
	int slot;
	char str[80];
	slot = find_free();
	if(slot == -1) {
		printf("\nList is full");
		return;
	}
	printf("Enter name: ");
	gets(addr_list[slot].name);

	printf("Enter street: ");
	gets(addr_list[slot].street);

	printf("Enter city: ");
	gets(addr_list[slot].city);

	printf("Enter zip: ");
	gets(str);
	addr_list[slot].zip = atoi(str);
}

int find_free(void) {
	int key;
	for (key = 0; addr_list[key].name[0] != '\0' && key < MAX; key++);

	if (key >= MAX)
		return -1;

	return 1;
}

void delete(void) {
	int slot;
	printf("\nDelete record #: ");
	scanf("%d", &slot);

	if(slot >= 0 && slot <= MAX) {
		addr_list[slot].name[0] = '\0';
		printf("Delete #:%d record sucessed.\n", slot);
	}
}

void list(void) {
	for (int i = 0; i < MAX; i++) {
		if (addr_list[i].name[0]) {
			printf("%s\n",addr_list[i].name);
			printf("%s\n",addr_list[i].street);
			printf("%s\n",addr_list[i].city);
			printf("%d\n\n",addr_list[i].zip);
		}
	}
	printf("\n\n");
}

void save(void) {
	FILE *fp;
	if ((fp = fopen("maillist.txt", "wb")) == NULL)
		printf("Cannot open the file.\n");
	for (int i = 0; i < MAX; i++) {
		if(addr_list[i].name[0]) {
			if(fwrite(&addr_list[i], sizeof(struct addr), 1, fp) != 1)
				printf("File write error.\n");
		}
	}
	fclose(fp);
}

void load(void) {
	FILE *fp;
	if ((fp = fopen("maillist.txt", "rb")) == NULL) {
		printf("Can not open the file.\n");
	}
	for (int i = 0; i < MAX; i++) {
		if (fread(&addr_list[i], sizeof(struct addr), 1, fp) != 1) {
			if (feof(fp))
				break;
			printf("File read error.\n");
		}
	}
	fclose(fp);
}



int menu_select(void) {
	char str[80];
	int c;
	printf("1.Enter a name\n");
	printf("2.Delete a name\n");
	printf("3.List the file\n");
	printf("4.Save the file\n");
	printf("5.Load the file\n");
	printf("6.Quit\n");

	while (1) {
		printf("\nEnter your choice: ");
		gets(str);
		c = atoi(str);
		if (c <= 0 || c > 6) {
			printf("Enter the number between 1-6 please.\n");
			continue;
		} else 
			break;
	}
	return c;
}

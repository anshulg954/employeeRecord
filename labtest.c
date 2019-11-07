#include<stdio.h>
#include<malloc.h>
#include <stdlib.h>
struct emp{
  char empType;
  int year;
  int month;
  int no;
};
struct add
{
  char town[32];
  char city[32];
  char state[32];
  int pin;
};
struct record{
  struct emp empNo;
  char name[32];
  char fatherName[32];
  struct add address;
  struct record *next;
};
typedef struct record list;
list *start=NULL;
list* create(list* start) {
  /* code */
  char buff[100];
  list *newnode;
  newnode =(list*)malloc(sizeof(list));
  printf("\nEnter record");
  printf("\nEnter employee type (M for multitasking, O for Officer, C for Clerk):");
  scanf(" %c",&newnode->empNo.empType);
  printf("\nEnter employee year of join:");
  scanf(" %d",&newnode->empNo.year);
  printf("\nEnter employee Join month");
  scanf(" %d",&newnode->empNo.month);
  printf("\nEnter employee no.");
  scanf(" %d",&newnode->empNo.no);
  gets(buff);
  printf("\nEnter employee Name");
  gets(newnode->name);
  fflush(stdin);
  printf("Enter employee Father's Name:\n");
  gets(newnode->fatherName);
  fflush(stdin);
  printf("\nEnter employee Address:\n");
  printf("Enter employee TOWN:\n");
  gets(newnode->address.town);
  fflush(stdin);
  printf("Enter employee CITY:\n");
  gets(newnode->address.city);
  fflush(stdin);
  printf("Enter employee STATE:\n");
  gets(newnode->address.state);
  fflush(stdin);
  printf("Enter employee PIN:\n");
  scanf("%d",&newnode->address.pin);
  newnode->next=NULL;
  if(start==NULL){
    start=newnode;
  }
  else{
    newnode->next=start;
    start=newnode;
  }
  return start;
}
void display(list* head) {
	if (head == NULL) {
		printf("Record empty, exiting.");
		return;
	}
	while (head != NULL) {
		printf("\nEmployee Number in order (O Y M N)\n  %c %d %d %d", head->empNo.empType, head->empNo.year, head->empNo.month, head->empNo.no);
		printf("\nName of the Employee \n %s", head->name);
		printf("\nFather's Name of the Employee\n %s", head->fatherName);
		printf("\nName of town/village of the Employee\n %s", head->address.town);
		printf("\nCity of the Employee\n  %s", head->address.city);

		printf("\nState of the Employee\n %s", head->address.state);

		printf("\nEnter the PIN code of the Employee\n %d",head->address.pin);
		head = head->next;
	}
	return;
}
void searchNo(list* head, int no) {
	int flag = 0;
	while ((head != NULL)&& flag==0) {
		if (head->empNo.no == no) {
			printf("\nRecord Found");
      printf("\nEmployee Number in order (O Y M N)\n  %c %d %d %d", head->empNo.empType, head->empNo.year, head->empNo.month, head->empNo.no);
      printf("\nName of the Employee \n %s", head->name);
      printf("\nFather's Name of the Employee\n %s", head->fatherName);
      printf("\nName of town/village of the Employee\n %s", head->address.town);
      printf("\nCity of the Employee\n  %s", head->address.city);

      printf("\nState of the Employee\n %s", head->address.state);

      printf("\nEnter the PIN code of the Employee\n %d",head->address.pin);
			flag = 1;
		}
    else
      head=head->next;
	}
	if (flag == 0)
    printf("\nRecord not found");
}
int main()
{
	list* head;
	head = NULL;
	int choice,no;
	char ans = 'y';
	do{
		printf("\t\t MAIN MENU\n");
		printf("1.Create new record list.\n");
		printf("2.Display the records.\n");
		printf("3.Search the record for a given employee number.\n");
		scanf(" %d", &choice);
		switch (choice) {
		case 1:
			head=create(head);
			printf("\nDo you want to return to main menu(Y/N)");
			scanf(" %c", &ans);
			break;
    case 2:
      display(head);
      printf("\nDo you want to return to main menu(Y/N)");
			scanf(" %c", &ans);
    case 3:
      printf("\nEnter the emp No. you want to search in the record\n");
      scanf(" %d", &no);
      searchNo(head, no);
      printf("\nDo you want to return to main menu(Y/N)");
      scanf(" %c", &ans);
      break;
    default:
			printf("\n Wrong choice selected.");
			printf("\nDo you want to return to main menu(Y/N)");
			scanf(" %c", &ans);
			break;
		}
	} while (ans == 'y' || ans == 'Y');

	return 0;
}

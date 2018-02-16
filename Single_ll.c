#include <stdio.h>
#include <stdlib.h>

void append(void);
void Addatafter(void);
void Addatbegin(void);
void Delete(void);
void display(void);
int Length(void);

struct node {
	int data;
	struct node* link;
};

struct node* root = NULL;
unsigned int list_len;
int main(int argc, char* argv[])
{
	unsigned int k=0,j=0;
	while(1)
	{
		printf("single link list operation : \n");
		printf("1)Append : \n");
		printf("2)Addatbegin : \n");
		printf("3)Addatafter : \n");
		printf("4)Length : \n");
		printf("5)Display : \n");
		printf("6)Delete : \n");
		printf("7)Quit : \n");

		printf("Enter a choice :\n");
		scanf("%d",&k);
		switch(k)
		{
			case 1:
				append();
				break;
			case 2:
				Addatbegin();
				break;
			case 3:
				Addatafter();
				break;
			case 4:
				j = Length();
				printf("lenght of List is = %d\n\r",j);
				break;
			case 5:
				display();
				break;
			case 6:
				Delete();
				break;
			case 7:
				exit(1);
			default:
				printf("You have enter wrong choice...Please try again..\n\r");
		}

	}
}
void append(void)// Insert a node at end of Link list
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));

	printf("Insert data in node :");
	scanf("%d",&temp->data);
	temp->link = NULL;

	if(root == NULL)// list is empty
	{
		root = temp;
	}
	else
	{
		struct node* p;
		p=root;

		while(p->link != NULL)
		{
			p = p->link;
		}

		p->link = temp;
	}

}
void Addatbegin(void)
{
	struct node* temp;

	temp = (struct node*)malloc(sizeof(struct node));
	printf("Insert data in new node:");
	scanf("%d",&temp->data);
	temp->link = NULL;

	if(root == NULL) {
		root = temp;
	} else {
		temp->link = root;
		root = temp;
	}
}
void Addatafter(void)
{
	struct node* temp,*p;
	unsigned int loc,len,i=1;

	temp = (struct node*)malloc(sizeof(struct node));
	printf("Insert data in new node :");
	scanf("%d",&temp->data);
	temp->link = NULL;
	printf("Enter location to which add this node:");
	scanf("%d",&loc);
	p=root;

	len = Length();
	if(loc > len)
	{
		printf("You have insert invalid input len of list is %d\n",len);
	}
	else
	{
		while(i < loc)
		{
			p = p->link;
			i++;
		}
		temp->link = p->link;
		p->link = temp;
	}


}

int Length(void)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	list_len = 0;
	temp = root;

	while(temp != NULL)
	{
		list_len++;
		temp = temp->link;
	}
	return list_len;
}

void display(void)
{
	struct node* temp;

	printf("Contents of link list are: \n");

	temp = root;
	if(temp == NULL)
	{
		printf("linked list is empty!");
	}
	while(temp != NULL)
	{
		printf("%d ",temp->data);
		temp=temp->link;
	}
	printf("\n\r\n\r");

}
void Delete(void)
{
	int i=0,loc=0;
	printf("1)Delete node from begin of the list\n");
	printf("2)Delete node from end of the list\n");
	printf("3)Delete node from middle of the list\n");

	scanf("%d",&i);

	struct node* temp,*temp1;
	temp = root;
	switch(i)
	{
		case 1:
			root = temp->link;
			break;
		case 2:
			while(temp->link != NULL)
			{
				temp1=temp;
				temp=temp->link;
			}
			temp1->link=NULL;
			break;
		case 3:
			i=1;
			printf("Enter location to which delete noe :");
			scanf("%d",&loc);
			while(i < loc)
			{
				temp1=temp;
				temp=temp->link;
				i++;
			}
			temp1->link = temp->link;
			break;
		default : printf("Invalid Input");
	}
}

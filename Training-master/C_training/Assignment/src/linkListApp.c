/*
@Aim	:Write an application for the link list using linkList library api
@Author	:Gaurang
@Date	:12 Oct 2017
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include"../include/linkList.h"


/*/////////////////////////////////////////////////////////////////////////////
///@brief	:check the number is positive digit or not
///@param	:*s : string with user given data
//		*data : data variable into which number is store
///@return	:returns 0 if no error else returns -1 for not positive number
/////////////////////////////////////////////////////////////////////////////*/
int validNumber(char *s, uint32_t *data)
{
	char *c = s;
	while (*c) {
		if (!isdigit(*c++))
			return -1;
	}
	*data = atoi(s);
	return 0;
}

int main(void)
{
	int flag = 0, stat;
	uint32_t data, pos, size, index, selection;
	char s[10], *c;
	node *start = NULL;
	while (1) {
		printf(".................................................\n");
		printf("Link list operation menu\n");
		printf("1. Insert a node at top position\n");
		printf("2. Insert a node at user given position\n");
		printf("3. Get a node from top position\n");
		printf("4. Get a node from user given position\n");
		printf("5. Remove a node from top position\n");
		printf("6. Remove a node from user gven postion\n");
		printf("7. Remove a node using data value\n");
		printf("8. Sort the list\n");
		printf("9. Get number of elements in list\n");
		printf("10. Get index of node for the user given data\n");
		printf("11. Print list\n");
		printf("12. Delete list\n");
		printf("13. Check list is empty or not\n");
		printf("0. To exit\n");
		printf(".................................................\n");
		printf("Select operation:");
		scanf("%s", s);
		c = s;
		while (*c) {
			if (!isdigit(*c++)) {
				fprintf(stderr, "Error: invalid input: %s\n",
					s);
				flag = 1;
				break;
			}
		}
		if (flag) {
			flag = 0;
			continue;
		}
		selection = atoi(s);
		if (!selection) {
			deleteList(&start);
			break;
		}
		switch (selection) {
		case 1:
			printf("Enter data to store:");
			scanf("%s", s);
			if (validNumber(s, &data)) {
				fprintf(stderr,
					"Error: invalid data input: %s\n", s);
				break;
			}
			if (insertNodeAtTop(&start, data)) {
				fprintf(stderr,
					"Error: memory not available\n");
				break;
			}
			printf("Node is inserted at top position in list\n");
			break;
		case 2:
			printf("Enter data to store:");
			scanf("%s", s);
			if (validNumber(s, &data)) {
				fprintf(stderr,
					"Error: invalid data input: %s\n", s);
				break;
			}
			printf("Enter node position:");
			scanf("%s", s);
			if (validNumber(s, &pos)) {
				fprintf(stderr,
					"Error: invalid position input: %s\n",
					s);
				break;
			}
			stat = listInsertNodeAt(&start, pos, data);
			if (stat == MEMERR) {
				fprintf(stderr, "Error: memory not availble\n");
				break;
			} else if (stat == POSERR) {
				fprintf(stderr,
					"Error: invalid position value\n");
				break;
			}
			printf("Node is inserted at %s position in list\n", s);
			break;
		case 3:
			stat = listGetNodeFromTop(&start, &data);
			if (stat) {
				fprintf(stderr, "Error: empty list\n");
				break;
			} else
				printf("Data from top postion = %d\n", data);
			break;
		case 4:
			printf("Enter node position:");
			scanf("%s", s);
			if (validNumber(s, &pos)) {
				fprintf(stderr,
					"Error: invalid position input: %s\n",
					s);
				break;
			}
			stat = listGetNodeFromPosition(&start, pos, &data);
			if (stat == EMPERR) {
				fprintf(stderr, "Error: empty list\n");
				break;
			} else if (stat == POSERR) {
				fprintf(stderr,
					"Error: invalid position value\n");
				break;
			}
			printf("Data from node position %d = %d\n", pos, data);
			break;
		case 5:
			if (listRemoveTopNode(&start)) {
				fprintf(stderr, "Error: empty list\n");
				break;
			}
			printf("Top node is removed\n");
			break;
		case 6:
			printf("Enter node position:");
			scanf("%s", s);
			if (validNumber(s, &pos)) {
				fprintf(stderr,
					"Error: invalid position input: %s\n",
					s);
				break;
			}
			stat = listRemoveNthNode(&start, pos);
			if (stat == EMPERR) {
				fprintf(stderr, "Error: empty list\n");
				break;
			} else if (stat == POSERR) {
				fprintf(stderr,
					"Error: invalid position value\n");
				break;
			} else {
				printf("Node at position %s is removed\n", s);
				break;
			}
		case 7:
			printf("Enter data:");
			scanf("%s", s);
			if (validNumber(s, &data)) {
				fprintf(stderr,
					"Error: invalid data input: %s\n", s);
				break;
			}
			stat = listRemoveNodeByValue(&start, data);
			if (stat == EMPERR) {
				fprintf(stderr, "Error: empty list\n");
				break;
			} else if (stat == DATERR) {
				fprintf(stderr, "Error: data not found\n");
				break;
			} else {
				printf("Node having data %s is removed\n", s);
				break;
			}
		case 8:
			if (listSort(&start)) {
				fprintf(stderr, "Error: empty list\n");
				break;
			}
			printf("List sorted\n");
			break;
		case 9:
			if (getListSize(&start, &size))
				fprintf(stderr, "Error: empty list\n");
			printf("Number of nodes in list: %d\n", size);
			break;
		case 10:
			printf("Enter data:");
			scanf("%s", s);
			if (validNumber(s, &data)) {
				fprintf(stderr,
					"Error: invalid data input: %s\n", s);
				break;
			}
			stat = getNodeIndex(&start, data, &index);
			if (stat == EMPERR) {
				fprintf(stderr, "Error: empty list\n");
				break;
			} else if (stat == DATERR) {
				fprintf(stderr, "Error: data not found\n");
				break;
			} else {
				printf("Data = %d, node index = %d\n",
					data, index);
				break;
			}
		case 11:
			if (printList(stdout, start))
				fprintf(stderr, "Error: empty list\n");
			break;
		case 12:
			if (deleteList(&start)) {
				fprintf(stderr, "Error: empty list\n");
				break;
			}
			printf("List is deleted\n");
			break;
		case 13:
			if (isListEmpty(start))
				printf("List is empty\n");
			else
				printf("List is not empty\n");
			break;
		default:
			fprintf(stderr, "Unknown command : %s\n", s);
			break;
		}
	}
}

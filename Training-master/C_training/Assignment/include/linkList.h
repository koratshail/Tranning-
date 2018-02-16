#ifndef LINKLIST_H_ /* include guard */
#define LINKLIST_H_

#include<stdio.h> /* FILE pointer */
#include<stdint.h> /* uint32_t */

#define MEMERR -1 /* mem not availble */
#define EMPERR -2 /* list empty */
#define POSERR -3 /* position invalid */
#define DATERR -4 /* data not found */

typedef uint32_t uint32;
struct node {
	uint32 data; /* data value in node */
	struct node *next; /* point to next node in list */
};
typedef struct node node;

int initList(node **head, uint32 maxLinkedListSize);
int insertNodeAtTop(node **head, uint32 data);
int listInsertNodeAt(node **linkedList, int position, uint32 data);
int listGetNodeFromTop(node **linkedList, uint32 *data);
int listGetNodeFromPosition(node **linkedList, int position, uint32 *data);
int listRemoveTopNode(node **linkedList);
int listRemoveNthNode(node **linkedList, int position);
int listRemoveNodeByValue(node **linkedList, uint32 data);
int listSort(node **linkedList);
int getListSize(node **linkedList, uint32 *size);
int getNodeIndex(node **linkedList, uint32 data, uint32 *index);
int printList(FILE *fp, node *linkedList);
int deleteList(node **linkedList);
int isListEmpty(node *linkedList);

#endif

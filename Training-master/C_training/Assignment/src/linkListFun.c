/*
Aim	:Link list functions
Author	:Gaurang
Date	:10 Oct 2017
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include"../include/linkList.h"

/*/////////////////////////////////////////////////////////////////////////////
///@brief	:create_node at top position in list
///@param	:**ptr:pointer to struct pointer which points to first node
///		of list
///		data:data value of creating node
///@return	:returns 0 if no error else returns error code
/////////////////////////////////////////////////////////////////////////////*/
int insertNodeAtTop(node **ptr, uint32 data)
{
	if (*ptr == NULL) {
		*ptr = (node *) malloc(sizeof(node));
		if (!(*ptr))
			return MEMERR;	/*memory not available */
		(*ptr)->data = data;
		(*ptr)->next = NULL;
		return 0;
	} else {
		node *temp;
		temp = malloc(sizeof(node));
		if (!(temp))
			return MEMERR;	/* mem not available */
		temp->next = *ptr;
		temp->data = data;
		*ptr = temp;
		return 0;
	}
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief	:create_node at user given position
///@param	:**start: pointer to struct pointer which points to first node
///		of list
///		data:data value of creating node
///		pos: postion where node is to create
///@return	:returns 0 if no error else returns error code
/////////////////////////////////////////////////////////////////////////////*/
int listInsertNodeAt(node **start, int pos, uint32 data)
{
	node *ptr = *start;
	int i = 0;
	if (pos < 1)
		return POSERR; /* invalid position value */
	if (pos == 1) {
		i = insertNodeAtTop(start, data);
		return i;
	}
	while (ptr) {
		i++;
		ptr = ptr->next;
	}
	i++;
	if (i < pos)
		return POSERR; /* invalid position value */
	i = 2;
	ptr = *start;
	while (i++ != pos)
		ptr = ptr->next;
	node *temp = NULL;
	temp = ptr->next;
	ptr->next = (node *) malloc(sizeof(node));
	if (!(ptr->next))
		return MEMERR; /* no mem available */
	(ptr->next)->next = temp;
	(ptr->next)->data = data;
	return 0;
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief	:read node data from top position of list
///@param	:**start: pointer to struct pointer which points to first node
///		of list
///		*data: data address to store data
///@return	:returns 0 if no error else returns error code
/////////////////////////////////////////////////////////////////////////////*/
int listGetNodeFromTop(node **start, uint32 *data)
{
	node *ptr = *start;
	if (!ptr)
		return EMPERR; /* no top node */
	*data = ptr->data;
	return 0;
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief	:read node data from user given position of list
///@param	:**start: pointer to struct pointer which points to first node
///		of list
///		*data: data address to store data
///		pos: postion from where node data to read
///@return	:returns 0 if no error else returns error code
/////////////////////////////////////////////////////////////////////////////*/
int listGetNodeFromPosition(node **start, int pos, uint32 *data)
{
	node *ptr = *start;
	int i = 0;
	if (!ptr)
		return EMPERR; /* list is empty */
	if (pos < 1)
		return POSERR; /* pos is not valid */
	while (ptr) {
		i++;
		ptr = ptr->next;
	}
	if (pos > i)
		return POSERR; /* invalid position value */
	ptr = *start;
	i = 1;
	while (i++ != pos)
		ptr = ptr->next;
	*data = ptr->data;
	return 0;
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief	:remove top node in list
///@param	:**start: pointer to struct pointer which points to first node
///		of list
///@return	:returns 0 if no error else returns error code
/////////////////////////////////////////////////////////////////////////////*/
int listRemoveTopNode(node **start)
{
	if (!(*start))
		return EMPERR; /* list empty */
	node *temp = (*start)->next;
	free(*start);
	*start = temp;
	return 0;
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief	:remove a node from user given position
///@param	:**start: pointer to struct pointer which points to first node
///		of list
///		pos: postion from where node to remove from list
///@return	:returns 0 if no error else returns error code
/////////////////////////////////////////////////////////////////////////////*/
int listRemoveNthNode(node **start, int pos)
{
	node *temp, *ptr = *start;
	int i = 0;
	if (!ptr)
		return EMPERR; /* list is empty */
	if (pos < 1)
		return POSERR; /* pos is not valid */
	if (pos == 1) {
		i = listRemoveTopNode(start);
		return i;
	}
	while (ptr) {
		i++;
		ptr = ptr->next;
	}
	if (pos > i)
		return POSERR; /* invalid position value */
	ptr = *start;
	i = 2;
	while (i++ != pos)
		ptr = ptr->next;
	temp = ptr->next;
	ptr->next = (ptr->next)->next;
	free(temp);
	return 0;
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief	:remove a node using data value
///@param	:**start: pointer to struct pointer which points to first node
///		of list
///		data: node to remove which match data value
///@return	:returns 0 if no error else returns error code
/////////////////////////////////////////////////////////////////////////////*/
int listRemoveNodeByValue(node **start, uint32 data)
{
	node *ptr = *start;
	int i = 1;
	if (!ptr)
		return EMPERR; /* list empty */
	if (ptr->data == data)
		return listRemoveTopNode(start);
	while (ptr->next) {
		i++;
		if ((ptr->next)->data == data) {
			i = listRemoveNthNode(start, i);
			return i;
		}
		ptr = ptr->next;
	}
	return DATERR; /* data not found */
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief	:sort the list according to ascending order
///@param	:**start: pointer to struct pointer which points to first node
///		of list
///@return	:returns 0 if no error else returns error code
/////////////////////////////////////////////////////////////////////////////*/
int listSort(struct node **start)
{
	struct node *bubl1 = (struct node *)malloc(sizeof(struct node));
	struct node *bubl2 = (struct node *)malloc(sizeof(struct node));
	if (*start == NULL) /* empty list */
		return EMPERR;
	else {	/* bubble sort algorithm */
		bubl1 = (*start);
		while (bubl1->next != NULL) {
			bubl2 = bubl1->next;
			while (bubl2->next != NULL) {
				if ((bubl1->data) > (bubl2->data)) {
					/* swapping */
					bubl1->data = bubl1->data + bubl2->data;
					bubl2->data = bubl1->data - bubl2->data;
					bubl1->data = bubl1->data - bubl2->data;
				}
				bubl2 = bubl2->next;
			}
			/* for last node */
			if ((bubl1->data) > (bubl2->data)) {
				/* swapping */
				bubl1->data = bubl1->data + bubl2->data;
				bubl2->data = bubl1->data - bubl2->data;
				bubl1->data = bubl1->data - bubl2->data;
			}
		bubl1 = bubl1->next;
		}
	}
	return 0;
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief	:to find the number of nodes in list
///@param	:**start: pointer to struct pointer which points to first node
///		of list
///		*size: to store the number of nodes
///@return	:returns 0 if no error else returns error code
/////////////////////////////////////////////////////////////////////////////*/
int getListSize(node **start, uint32 *size)
{
	node *ptr = *start;
	int i = 1;
	if (!(*start))
		return EMPERR; /* empty list */
	while (ptr->next) {
		i++;
		ptr = ptr->next;
	}
	*size = i;
	return 0;
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief	:find the node position which has data same as user given data
///@param	:**start: pointer to struct pointer which points to first node
///		of list
///		data: node to search which has this data value
///		*index: to store the index of node which has data
///@return	:returns 0 if no error else returns error code
/////////////////////////////////////////////////////////////////////////////*/
int getNodeIndex(node **start, uint32 data, uint32 *index)
{
	node *ptr = *start;
	int i = 0;
	if (!ptr)
		return EMPERR; /* list empty */
	while (ptr) {
		i++;
		if (ptr->data == data) {
			*index = i;
			return 0;
		}
		ptr = ptr->next;
	}
	return DATERR; /* data not found */
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief	:delete the list
///@param	:**start: pointer to struct pointer which points to first node
///		of list
///@return	:returns 0 if no error else returns error code
/////////////////////////////////////////////////////////////////////////////*/
int deleteList(node **start)
{
	node *ptr = *start, *temp = NULL;
	*start = NULL;
	if (!ptr)
		return EMPERR; /* list empty */
	while (ptr) {
		temp = ptr->next;
		free(ptr);
		ptr = temp;
	}
	return 0;
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief	:check list is empty or not
///@param	:**start: pointer to struct pointer which points to first node
///		of list
///@return	:returns 0 if not empty list else returns 1 for empty list
/////////////////////////////////////////////////////////////////////////////*/
int isListEmpty(node *start)
{
	if (start)
		return 0; /* list is not empty */
	else
		return 1; /* list is empty */
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief	:print list
///@param	:*ptr: pointer to struct pointer which points to first node
///		of list
///@return	:returns 0 if no error else return error code
/////////////////////////////////////////////////////////////////////////////*/
int printList(FILE *fp, node *ptr)
{
	if (!ptr)
		return EMPERR; /* no data to print */
	while (ptr) {
		fprintf(fp, "Data: %d\n", ptr->data);
		ptr = ptr->next;
	}
	return 0;
}

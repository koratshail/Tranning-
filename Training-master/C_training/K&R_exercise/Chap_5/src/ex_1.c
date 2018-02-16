/*Chap_5_Ex_1
@Aim:	Our binary search makes two tests inside the loop, when one would
	suffice	(at the price of more tests outside). Write a version with only
	one test inside the loop and measure the difference in run-time.
@Author:Gaurang
@date:	27 Sept 2017
*/

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

int binsearch(int x, int v[], int n);

int main(void)
{
	int i, x, n, indx, w, k = 0;
	char *c, s[10];
	printf("Enter number of element in array\n");
	scanf("%s", s);
	c = s;
	while (*c) {
		if (!isdigit(*c++)) {
			printf("Wrong input\n");
			return 1;
		}
	}
	w = atoi(s);
	int v[w];
	printf("Enter sorted integer array element for binary search\n");
	n = -99 * 99; /* to generate large value */
	for (i = 0; i < w; i++) {
		if (!scanf("%d", &v[i])) {
			printf("input is not int type\n");
			return 1;
		}
		if (v[i] < n) {
			printf("Wrong input\nEnter sorted array form\n");
			return 1;
		}
		n = v[i];
	}
	n = sizeof(v) / sizeof(v[0]);
	printf("Sorted array for binary search program is as below\n");
	while (k != n) {
		printf("v[%d] = %d\n", k, v[k]);
		k++;
	}
	printf("Enter number to search in array: ");
	scanf("%d", &x);
	indx = binsearch(x, v, n);
	if (indx < 0)
		printf("Number %d is not found in given sorted array\n", x);
	else
		printf("Number %d is found at position %d in sorted \
array\n", x, indx+1);
	return 0;
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief :	search a number x from the sorted array v
///@param :	x:number to be search in array
		v:sorted array address
		n:number of element in an array
///@return:	return position of a number in an array if found otherwise -1
/////////////////////////////////////////////////////////////////////////////*/
int binsearch(int x, int *v, int n)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	mid = (low + high) / 2;
	while (low <= high && x != v[mid]) {
		mid = (low+high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	if (x == v[mid])
		return mid;
	else
		return -1;
}

/*Expected Output:
Enter number of element in array):5
Enter sorted array for binary search element
11
22
33
44
55
Sorted array for binary search program is as below
v[0] = 11
v[1] = 22
v[2] = 33
v[3] = 44
v[4] = 55
Enter number to search in array: 44
Number 44 is found at position 4 in sorted array
*/

/*Chap_7/Ex_7
@Aim:	Rewrite readlines to store lines in an array supplied by main,rather
	than calling alloc to maintain storage. How much faster is the program?
	Remark: instead of dynamically allocating memory for every line at run
	time it is always fast as allocate memory for fixed size line.
@Author:gaurang
@Date:	03 Oct 2017
*/

#include<stdio.h>
#include<string.h>

#define MAXLINES 5000   /* max #lines to be sorted */

char *lineptr[MAXLINES];
char linestor[MAXLINES];

int readlines(char *lineptr[], char *linestor, int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

int main(void)
{
	int nlines; /* number of input lines read */
	printf("Enter strings line by line\n");
	printf("To exit prtess: CNTR+D\n");
	nlines = readlines(lineptr, linestor, MAXLINES);
	if (nlines >= 0) {
		qsort(lineptr, 0, nlines - 1);
		printf("Sorted output:\n");
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}
}

#define MAXLEN 1000 /* max length of any input line */
#define MAXSTOR 5000

int mgetline(char *s, int len);

/*/////////////////////////////////////////////////////////////////////////////
///@brief:	read input lines
///@param:	char *lineptr[]: char pointer array to store string(line) addr
///		char *linestor: instead of malloc, an array is passed to store
///		line
///		int maxlines: maximum number of lines
///@return:	return nlines: number of lines read
///		return -1: on error or maximum number of line reached
/////////////////////////////////////////////////////////////////////////////*/
int readlines(char *lineptr[], char *linestor, int maxlines)
{
	int len, nlines;
	char line[MAXLEN];
	char *p = linestor;
	char *linestop = linestor + MAXSTOR;
	nlines = 0;
	while ((len = mgetline(line, MAXLEN)) > 0) {
		if (nlines >= maxlines || p + len > linestop)
			return -1;
		else {
			line[len-1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
			p += len;
		}
	}
	return nlines;
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief:	write output lines
///@param:	char *lineptr[]: char pointer array point to lines
///		int nlines: number of lines to write
///@return:	void
/////////////////////////////////////////////////////////////////////////////*/
void writelines(char *lineptr[], int nlines)
{
	int i;
	for (i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief:	sort the string array in increasing order
///@param:	char *v[]: char pointer array point to lines
///		int left: index of line used in sorting
///		int right: index of line
///@return:	void
/////////////////////////////////////////////////////////////////////////////*/
void qsort(char *v[], int left, int right)
{
	int i, last;
	void swap(char *v[], int i, int j);
	if (left >= right)
		return;
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief:	interchange v[i] and v[j]
///@param:	char *v[]: char pointer array point to lines
///		int i: ith line in array
///		int j: jth line in array
///@return:	void
/////////////////////////////////////////////////////////////////////////////*/
void swap(char *v[], int i, int j)
{
	char *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief:	read string from stdin and store it into array
///@param:	char *s: address to store string
///		int lim: maximum length to read from stdin
///@return:	void
/////////////////////////////////////////////////////////////////////////////*/
int mgetline(char *s, int lim)
{
	int c;
	char *t = s;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		*s++ = c;
	if (c == '\n')
		*s++ = c;
	*s = '\0';
	return s - t;
}

/* Expected output:

Enter strings line by line
To exit prtess: CNTR+D
zxy
abc
opq
bde
Sorted output:
abc
bde
opq
zxy
*/

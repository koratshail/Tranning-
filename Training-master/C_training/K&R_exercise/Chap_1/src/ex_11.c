/*Chap_1/Ex_11
@Aim:	How would you test the word count program? What kinds of input are most
	likely to uncover bugs if there are any?
@Author:gaurang
@Date:	25 Sep 2017
*/

#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

/* count lines, words, and characters in input */
int main(void)
{
	int c, nl, nw, nc, state;
	state = OUT;
	nl = nw = nc = 0;
	printf("Enter strings for which character, words and lines to be \
count\n");
	printf("To exit: in new line press CNTRL+D\n");
	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			++nw;
		}
	}
	printf("Number of lines: %d\n", nl);
	printf("Number of words: %d\n",  nw);
	printf("Number of characters: %d\n", nc);
	return 0;
}

/* Output:
Bugs is as below
* is also consider a word
India-Pakistan is consider as a single word
123 is also consider a word
Number of lines: 4
Number of words: 23
Number of characters: 115
*/

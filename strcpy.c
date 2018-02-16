#include <stdio.h>

char *my_strcpy(char *dst, char *src)
{
	char *temp = dst;

	printf("src = %s\n\r",src);
	while((*src != NULL) | (*src == " ")) {
		*dst++ = *src++;
	}
	*dst = NULL;

	return temp;
}

char* strcpy(char * dest_ptr, const char * src_ptr)
{
	char* strresult = dest_ptr;
	if((NULL != dest_ptr) && (NULL != src_ptr))
	{
		/* Start copy src to dest */
		while (NULL != *src_ptr)
		{
			*dest_ptr++ = *src_ptr++;
		}
		/* put NULL termination */
		*dest_ptr = NULL;
	}
	return strresult;

}/* End: strcpy() */


int main ()
{
	char src[50];
	char dst[50];

	printf("Enter src string \n\r");
	gets(src);

	my_strcpy(dst,src);
	printf("dst = %s",dst);
	return  0;
}


/*Chap_9_Ex_3
Aim	:Revise minprintf to handle more of the facilities of printf.
Author	:Gaurang
Date	:06 Oct 2017
*/

#include<stdio.h>
#include<stdarg.h>
#include<string.h>

void minprintf(char *fmt, ...);

int main(void)
{
	int a = 10;
	char c = 'Z';
	float f = 9.9;
	char *s = "Ahmedabad";
	minprintf("My printf     :%-10c:\n", c);
	printf("System printf :%-10c:\n", c);
	minprintf("My printf     :%10d:\n", a);
	printf("System printf :%10d:\n", a);
	minprintf("My printf     :%15.10f:\n", f);
	printf("System printf :%15.10f:\n", f);
	minprintf("My printf     :%10.5s:\n", s);
	printf("System printf :%10.5s:\n", s);
	return 0;
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief :	same as printf with the functionality of formatted width
///@param :	char fmt : string and also variable arguments
//@return:	void
/////////////////////////////////////////////////////////////////////////////*/
/* minprintf: minimal printf with variable argument list */
void minprintf(char *fmt, ...)
{
	va_list ap; /* points to each unnamed arg in turn */
	char *p, *sval, buf[50];
	int ival, i, n, nlen, flen, ilen, d;
	int k = 0, f = 0, mn = 0, flag = 0;
	double dval;
	char c = '\0';
	va_start(ap, fmt); /* make ap point to 1st unnamed arg */
	for (p = fmt; *p; p++) {
		if (*p != '%') {
			putchar(*p);
			continue;
		}
		c = *++p;
		if (c == '-') {
			mn = 1;
			c = *++p;
		}
		i = 0;
		while (c >= '0' && c <= '9') {
			flag = 1;
			buf[i++] = c;
			c = *++p;
		}
		buf[i] = '\0';
		if (flag)
			d = sscanf(buf, "%d", &k);
		if (d == EOF) /* error occur */
			break;
		if (c == '.') {
			i = 0;
			c = *++p;
			while (c >= '0' && c <= '9') {
				flag = 1;
				buf[i++] = c;
				c = *++p;
			}
			buf[i] = '\0';
			d = sscanf(buf, "%d", &f);
			if (d == EOF) /* error occur */
				break;
		}
		switch (c) {
		case 'd':
			ival = va_arg(ap, int);
			if (flag) {
				flag = 0;
				if (mn) {
					printf("%d", ival);
					sprintf(buf, "%d", ival);
					ilen = strlen(buf);
					for (i = 0; i < (k-ilen); i++)
						printf(" ");
					mn = 0;
				} else {
					sprintf(buf, "%d", ival);
					ilen = strlen(buf);
					for (i = 0; i < (k - ilen); i++)
						printf(" ");
					printf("%d", ival);
				}
			} else {
				mn = 0;
				printf("%d", ival);
			}
			break;
		case 'f':
			dval = va_arg(ap, double);
			n = dval;
			sprintf(buf, "%d", n);
			ilen = strlen(buf);
			sprintf(buf, "%f", dval);
			nlen = strlen(buf);
			flen = nlen - ilen - 1;
			/* cal */
			if (f) {
				flen = f;
				f = 0;
			}
			if (!flag) {
				printf("%f", dval);
				break;
			}
			flag = 0;
			if (k > (ilen + flen + 1) && (mn == 0)) {
				for (i = 0; i < (k - (ilen + flen + 1)); i++)
					printf(" ");
				if (flen > 6) {
					printf("%f", dval);
					for (i = 0; i < flen - 6; i++)
						printf("0");
				} else {
					for (i = 0; i < (ilen + flen + 1); i++)
						printf("%c", buf[i]);
				}
				mn = 0;
			}
			if (k > (ilen + flen + 1) && (mn == 1)) {
				mn = 0;
				if (flen > 6) {
					printf("%f", dval);
					for (i = 0; i < flen - 6; i++)
						printf("0");
				} else {
					for (i = 0; i < ilen + flen + 1; i++)
						printf("%c", buf[i]);
				}
				for (i = 0; i < (k-(ilen + flen + 1)); i++)
					printf(" ");
			}
			if (k <= (ilen + flen + 1)) {
				mn = 0;
				if (flen > 6) {/*float: 6 digit precsn*/
					for (i = 0; i < (ilen + 6 + 1); i++)
						printf("%c", buf[i]);
					for (i = 0; i < flen - 6; i++)
						printf("0");
				} else {
					for (i = 0; i < (ilen + flen + 1); i++)
						printf("%c", buf[i]);
				}
			}
			break;
		case 's':
			sval = va_arg(ap, char *);
			ilen = strlen(sval);
			if (flag) {
				flag = 0;
				if (f != 0 && f < ilen) {
					ilen = f;
					f = 0;
				}
				if (mn) {
					for (i = 0; i < ilen; i++)
						putchar(*sval++);
					for (i = 0; i < (k - ilen); i++)
						printf(" ");
					mn = 0;
					break;
				} else {
					for (i = 0; i < (k - ilen); i++)
						printf(" ");
					for (i = 0; i < ilen; i++)
						putchar(*sval++);
					break;
				}
			} else {
				mn = 0;
				for (; *sval; sval++)
					putchar(*sval);
					break;
			}
		case 'c':
			ilen = va_arg(ap, int);
			if (flag) {
				flag = 0;
				if (mn) {
					mn = 0;
					printf("%c", ilen);
					for (i = 0; i < k - 1; i++)
						printf(" ");
				} else {
					for (i = 0; i < (k - 1); i++)
						printf(" ");
					printf("%c", ilen);
				}
			} else
				printf("%c", ilen);
			break;
		default:
			putchar(*p);
			break;
		}
	}
	va_end(ap); /* clean up when done */
}
/* Output Example
	My printf     :Z         :
	System printf :Z         :
	My printf     :        10:
	System printf :        10:
	My printf     :   9.9000000000:
	System printf :   9.8999996185:
	My printf     :     Ahmed:
	System printf :     Ahmed:
*/

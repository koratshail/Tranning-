/*Chap_7/Ex_8
@Aim:	There is no error-checking in day_of_year or month_day.
	Remedy this defect.
@Author:gaurang
@Date:	03 Oct 2017
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

static char daytab[2][13] = {
		{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
		{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int main(void)
{
	int day, month, year, d = 0;
	char s[10], *c = NULL;
	printf("Enter Day:");
	scanf("%s", s);
	c = s;
	while (*c) {
		if (!isdigit(*c++)) {
			printf("Wrong input entered\n");
			printf("Only positive int type input is valid\n");
			return 0;
		}
	}
	day = atoi(s);
	printf("Enter Month:");
	scanf("%s", s);
	c = s;
	while (*c) {
		if (!isdigit(*c++)) {
			printf("Wrong input entered\n");
			printf("Only positive int type input is valid\n");
			return 0;
		}
	}
	month = atoi(s);
	printf("Enter Year:");
	scanf("%s", s);
	c = s;
	while (*c) {
		if (!isdigit(*c++)) {
			printf("Wrong input entered\n");
			printf("Only positive int type input is valid\n");
			return 0;
		}
	}
	year = atoi(s);
	d = day_of_year(year, month, day);
	if (d == -1)
		printf("Invalid data entered\n");
	else
		printf("Calculated days for %d:%d:%d is %d\n",
			day, month, year, d);
	printf(".......................................................\n");
	printf("Enter year and days for which day and month to find\n");
	printf("Enter Year:");
	scanf("%s", s);
	c = s;
	while (*c) {
		if (!isdigit(*c++)) {
			printf("Wrong input entered\n");
			printf("Only positive int type input is valid\n");
			return 0;
		}
	}
	year = atoi(s);
	printf("Enter Day:");
	scanf("%s", s);
	c = s;
	while (*c) {
		if (!isdigit(*c++)) {
			printf("Wrong input entered\n");
			printf("Only positive int type input is valid\n");
			return 0;
		}
	}
	d = atoi(s);
	month_day(year, d, &month, &day);
	if (month == -1)
		printf("Invalid data entered\n");
	else
		printf("calculated DD MM YYYY: %d %d %d\n", day, month, year);
	return 0;
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief :	Calculate day in year from month and day
///		also check whether given day, month and year is valid
///@param :	year: days calculated for this given year
///		month: month of year
///		day: day of month
///@return:	return days in a year for the given day, month and year
///		return -1 if wrong data of day, month and year
/////////////////////////////////////////////////////////////////////////////*/
int day_of_year(int year, int month, int day)
{
	int i, leap;
	leap = (((year%4 == 0) && (year%100 != 0)) || (year%400 == 0));
	if (month > 0 && month <= 12 && year >= 0
&& day > 0 && day <= daytab[leap][month]) {
		for (i = 1; i < month; i++)
			day += daytab[leap][i];
		return day;
	}
	return -1;
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief :	Calculate month and day for the given days in a year and year
///		also check whether given days and year is valid
///@param :	year: day and month will be calculated for this given year
///		yearday: day and month is calculated for this days in year
///		pmonth: month of year
///		pday: day of month
///@return:	return void
///		if year and yearday parameter valid then calculated day & month
///		write in their address else -1 will be write into their addr
/////////////////////////////////////////////////////////////////////////////*/
/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;
	leap = (((year%4 == 0) && (year%100 != 0)) || (year%400 == 0));
	if ((year < 0) || (year > 9999) || (yearday < 0) ||
(!leap && yearday > 365) || (leap && yearday > 366)) {
		*pmonth = -1;
		*pday = -1;
		return;
	}
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
}
/*Expected output
	Enter day, month and year in below format
	dd mm yyyy : 04 10 2017
	Calculated days for 4:10:2017 is 277
	.......................................................
	Enter year and days for which day and month to find
	yyyy ddd : 2017 277
	calculated DD MM YYYY: 4 10 2017
*/

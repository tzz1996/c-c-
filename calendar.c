#include <stdio.h>
#include <stdlib.h>

int get_year (void);			//输入年份		
int get_leap_year (int year);			//判断是否是闰年
int get_firstday (int year);			//获取该年份1月的第一天是星期几,0sun,1mon,etc
void print_calendar (FILE *fout, int year, int leap, int firstday);			//打印

int main ()
{
	int year;
	int leap;
	int firstday;
	FILE *fout;

	fout = fopen ("calendar.txt", "w");	

	year = get_year ();

	leap = get_leap_year (year);

	firstday = get_firstday (year);

	print_calendar (fout, year, leap, firstday);

	printf ("Open the 'calendar.txt' to check out\n");

	system ("pause");

	return 0;
}

int get_year ()
{
	int year;
	printf ("enter a year:");
	scanf ("%d", &year);
	return year;
}

int get_leap_year (int year)
{
	int leap;
	if (year%4==0 && year%100!=0 || year%400==0)
		leap == 1;
	else
		leap == 0;
	return leap;
}

int get_firstday (int year)
{
	int firstday;
	int temp1, temp2, temp3;
	temp1 = (year-1)/4;
	temp2 = (year-1)/100;
	temp3 = (year-1)/400;
	firstday = (year + temp1 - temp2 + temp3)%7;
	return firstday;
}

void print_calendar (FILE *fout, int year, int leap, int firstday) 
{
	int month;
	int day;
	int days_of_month;
	int space;

	fprintf (fout, "           %d", year);
	for (month = 1; month <= 12; ++month) {
		switch (month) {
			case 1:
				fprintf (fout, "\n              January");
				days_of_month = 31;
		    	break;
			case 2:
				fprintf (fout, "\n              February");
				days_of_month = (leap? 29:28);
				break;
			case 3:
				fprintf (fout, "\n              March");
				days_of_month = 31;
				break;
			case 4:
				fprintf (fout, "\n              April");
				days_of_month = 30;
				break;
			case 5:
				fprintf (fout, "\n              May");
				days_of_month = 31;
				break;
			case 6:
				fprintf (fout, "\n              June");
				days_of_month = 30;
				break;
			case 7:
				fprintf (fout, "\n              July");
				days_of_month = 31;
				break;
			case 8:
				fprintf (fout, "\n              August");
				days_of_month = 31;
				break;
			case 9:
				fprintf (fout, "\n              September");
				days_of_month = 30;
				break;
			case 10:
				fprintf (fout, "\n              October");
				days_of_month = 31;
				break;
			case 11:
				fprintf (fout, "\n              November");
				days_of_month = 30;
				break;
			case 12:
				fprintf (fout, "\n              December");
				days_of_month = 31;
				break;
		}			//swich
		fprintf(fout, "\n    Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
		for (space=0; space<=firstday; ++space) {
			fprintf(fout, "     ");
		}
		for (day=1; day<=days_of_month; ++day) {
			fprintf(fout, "%2d", day);
			if ( (firstday+day)%7 > 0 )
				fprintf (fout, "   ");
			else
				fprintf (fout, "\n     ");
		}			//for day 1-days_of_month
		firstday = (days_of_month + firstday)%7;
	}			//for month 1-12
}
#include<stdio.h>
int main(void)
{
	int sel;
	printf("Enter selection:\n");
	scanf("%d", &sel);
	switch (sel) {
	case 1:
		printf("Selection %d\n", sel);
		break;
	case 2: goto Label;
		int b;
		b = sel + 10;
		printf("B is %d\n", sel);
		break;
	case 3:
		printf("Selection %d\n", sel);
		break;
	default:
		printf("Default\n");
	}
Label: ;int c;
	c = sel + 2;
	printf("Lable\n");
	return 0;
}

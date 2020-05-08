#include <stdio.h>


int main(void) {
	/*int a = 100,b;
	int *p_a;

	p_a = &a;
	b = *p_a;

	printf("a = %d\tb = %d\t *p_a = %d", a, b, *p_a);*/

	int a[3] = { 30,10,2 };
	int b[2][2] = { { 1 , 2 },{ 2 ,4 } };

	char *mon[3] = {
		"January",
		"February",
		"March"
	};
	//int *p_a,*p_b;
	//char *p_abc;

	//p_a = a;
	//p_b = b[0];
	//int i = 0;
	//while (i<3) {
	//	printf("p_a %d\n", *p_a);
	//	p_a++;
	//	i++;
	//}
	//i = 0;
	//while (i<(2*2)) {
	//	printf("p_b %d\n", *p_b);
	//	p_b++;
	//	i++;
	//}


	char **p_mon;
	p_mon = mon;
	i = 0;
	while (i<3) {
		printf("%s\n", *p_mon++);
		i++;
	}
}
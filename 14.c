#include<stdio.h>

union stock
{
	char name;
	float num;
};
main() {
	union stock data;
	data.name = 'A';
	printf("data.name = %c\n", data.name);
	printf("data.num = %f\n", data.num);
	printf("datasize = %d\n", sizeof(data));

	data.num = 1.2345;
	printf("data.name = %c\n", data.name);
	printf("data.num = %f\n", data.num);
}
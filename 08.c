#include <stdio.h>


int main(void) {
	//int a[5];
	//for (int i = 0; i < 5; i++) {
	//	//a‚Ì”z—ñ‚É”Žš‚ð‘ã“ü
	//	a[i] = i;
	//}
	//for (int i = 0; i < 5; i++) {
	//	printf("a[%d]:%d\n", i, a[i]);
	//}

	int a[3][2] = { { 1,2 }, { 3,4 }, { 5,6 } };
	int b[2][2] = { { 1 , 2 },{ 2 ,4 } };
	char abc[2][255] = { "abcd","cdef" };

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < 2; i++) {
		int j = 0;
		while (abc[i][j] != '\0') {
			printf("%c", abc[i][j]);
			j++;
		}
		printf("\n");
	}

	for (int i = 0; i < 2; i++) {
		int j = 0;
		printf("%s", &abc[i][0]);
		j++;
		printf("\n");
	}

}
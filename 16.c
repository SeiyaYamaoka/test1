#include <stdio.h>        
#include <stdlib.h>
#include <time.h>
main() {
	clock_t start, end, now;
	start = clock();

	now = clock();

	srand((unsigned)time(NULL));

	//1�`100�̗�����100��� 
	for (int i = 1; i <= 10; i++) {
		for (int j = 0; j<10; j++) {
			printf("%3d ", rand() % 100 + 1);
		}
		printf("\n");
	}

	//printf("%f\n", (double)(now - start) / CLOCKS_PER_SEC);

	//while ((double)(now - start) / CLOCKS_PER_SEC < 0.5312) {
	//	now = clock();
	//}

	end = clock();
	printf("%f�b������܂���\n", (double)(end - start) / CLOCKS_PER_SEC);
}
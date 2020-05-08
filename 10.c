#include <stdio.h>
int sum(int a, int b);//プロトタイプ宣言
void tenplus(int *num);

int pluspointa(int *p);
int plushairet(int t[]);
void displushairet(int(*tbl)[3]);
main() {
	//printf("%d", sum(5, 3));
	int a[] = { 30,10,2,-999 }; 
	int b[2][3] = { { 1 , 2 ,3},{ 2 ,4 ,6} };


	displushairet(b);
	//printf("pointa:%d\n", pluspointa(a));
	//printf("hairet:%d\n", plushairet(a));
	//int a = 5;
	//tenplus(&a);
	//printf("%d", a);
}

int sum(int a, int b) {
	return a + b;
}
void tenplus(int *num) {
	*num += 10;
}
int pluspointa(int *p) {
	int gokei = 0;
	while (*p != -999) {
		gokei += *p;
		p++;
	}
	return gokei;
}
int plushairet(int t[]) {
	int gokei = 0;
	int i = 0;
	while (t[i] != -999) {
		gokei += t[i];
		i++;
	}
	return gokei;
}
void displushairet(int (*tbl)[3]) { //tbl[ ][3]  :tbl[2][3]
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d \t", tbl[i][j]);
		}
		printf("\n");
	}
}

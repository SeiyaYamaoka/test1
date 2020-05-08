#include<stdio.h>
#include<string.h>
struct syouhin_data {
	char name[20];
	int tanka;
};
typedef struct syouhin_data syouhin;
void disp4(syouhin *s);
main() {
	//基本的な使い方
	struct syouhin_data syouhin1, syouhin2;
	strcpy(syouhin1.name, "エンピツ");//文字列のコピー
	syouhin1.tanka = 30;
	syouhin2 = syouhin1;
	printf("syouhin1.name = %s\n", syouhin1.name);
	printf("syouhin1.tanka = %d\n", syouhin1.tanka);
	printf("syouhin2.name = %s\n", syouhin2.name);
	printf("syouhin2.tanka = %d\n", syouhin2.tanka);

	//typedefでsyouhin3を宣言
	syouhin syouhin3;
	syouhin3.tanka = 100;
	strcpy(syouhin3.name, "ケシゴム");
	printf("syouhin3.name = %s\n", syouhin3.name);
	printf("syouhin3.tanka = %d\n", syouhin3.tanka);

	//syouhin3をポインタで参照
	syouhin *syouhin3_p;
	syouhin3_p = &syouhin3;
	printf("syouhin3_p->name = %s\n", syouhin3_p->name);
	printf("syouhin3_p->tanka = %d\n", syouhin3_p->tanka);

	//配列
	syouhin syouhin4[] = { { "フデバコ",600 },{ "シャーペン",300 } };
	for (int i = 0; i < 2; i++) {
		printf("syouhin4[%d].name = %s\n", i, syouhin4[i].name);
		printf("syouhin4[%d].tanka = %d\n", i, syouhin4[i].tanka);
	}

	//構造体配列をポインタで参照
	syouhin *syouhin4_p;
	syouhin4_p = &syouhin4[0];
	for (int i = 0; i < 2; i++, syouhin4_p++) {
		printf("syouhin4_p->name = %s\n", syouhin4_p->name);
		printf("syouhin4_p->tanka = %d\n", syouhin4_p->tanka);
	}

	//関数アドレス渡し
	disp4(syouhin4);

}
void disp4(syouhin *s) {
	for (int i = 0; i < 2; i++) {
		printf("s->name = %s\n", s->name);
		printf("s->tanka = %d\n", s->tanka);
		s++;
	}
}
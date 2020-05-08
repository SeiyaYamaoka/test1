#include <stdio.h>
#define DATA_END -1

struct ken {
	int code;
	char name[20];
	char syozaiti[20];
	struct ken *next;
};
main() {
	struct ken ken_data[] = { 
	{ 1,"�k�C��","�D�y�s",NULL },
	{ 2,"�X","�X�s",NULL },
	{ 3,"���","�����s",NULL },
	{ 4,"�{��","���s",NULL },
	{ 5,"�H�c","�H�c�s",NULL },
	{ 6,"�R�`","�R�`�s",NULL },
	{ 7,"����","�����s",NULL },
	{ DATA_END,"","",NULL }, };

	struct ken *p, *wp;

	p = wp = ken_data;

	do {
		p++;
		wp->next = p;
		wp = p;
	} while (p->code != DATA_END);

	for (p = ken_data; p->code != DATA_END; p = p->next) {
		printf("code = %d\tname = %s\tsyozaiti = %s\n", p->code, p->name,p->syozaiti);
	}

}
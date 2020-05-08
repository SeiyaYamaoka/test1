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
	{ 1,"–kŠC“¹","ŽD–yŽs",NULL },
	{ 2,"ÂX","ÂXŽs",NULL },
	{ 3,"ŠâŽè","·‰ªŽs",NULL },
	{ 4,"‹{é","å‘äŽs",NULL },
	{ 5,"H“c","H“cŽs",NULL },
	{ 6,"ŽRŒ`","ŽRŒ`Žs",NULL },
	{ 7,"•Ÿ“‡","•Ÿ“‡Žs",NULL },
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
#include<stdio.h>
#include<string.h>
struct syouhin_data {
	char name[20];
	int tanka;
};
typedef struct syouhin_data syouhin;
void disp4(syouhin *s);
main() {
	//��{�I�Ȏg����
	struct syouhin_data syouhin1, syouhin2;
	strcpy(syouhin1.name, "�G���s�c");//������̃R�s�[
	syouhin1.tanka = 30;
	syouhin2 = syouhin1;
	printf("syouhin1.name = %s\n", syouhin1.name);
	printf("syouhin1.tanka = %d\n", syouhin1.tanka);
	printf("syouhin2.name = %s\n", syouhin2.name);
	printf("syouhin2.tanka = %d\n", syouhin2.tanka);

	//typedef��syouhin3��錾
	syouhin syouhin3;
	syouhin3.tanka = 100;
	strcpy(syouhin3.name, "�P�V�S��");
	printf("syouhin3.name = %s\n", syouhin3.name);
	printf("syouhin3.tanka = %d\n", syouhin3.tanka);

	//syouhin3���|�C���^�ŎQ��
	syouhin *syouhin3_p;
	syouhin3_p = &syouhin3;
	printf("syouhin3_p->name = %s\n", syouhin3_p->name);
	printf("syouhin3_p->tanka = %d\n", syouhin3_p->tanka);

	//�z��
	syouhin syouhin4[] = { { "�t�f�o�R",600 },{ "�V���[�y��",300 } };
	for (int i = 0; i < 2; i++) {
		printf("syouhin4[%d].name = %s\n", i, syouhin4[i].name);
		printf("syouhin4[%d].tanka = %d\n", i, syouhin4[i].tanka);
	}

	//�\���̔z����|�C���^�ŎQ��
	syouhin *syouhin4_p;
	syouhin4_p = &syouhin4[0];
	for (int i = 0; i < 2; i++, syouhin4_p++) {
		printf("syouhin4_p->name = %s\n", syouhin4_p->name);
		printf("syouhin4_p->tanka = %d\n", syouhin4_p->tanka);
	}

	//�֐��A�h���X�n��
	disp4(syouhin4);

}
void disp4(syouhin *s) {
	for (int i = 0; i < 2; i++) {
		printf("s->name = %s\n", s->name);
		printf("s->tanka = %d\n", s->tanka);
		s++;
	}
}
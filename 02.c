#include <stdio.h>

int main(void)
{
	//����
	printf("--------------------����--------------------------\n");
	char ch = 'A';
	char str1[] = "ArrowBlog";
	printf("�ꕶ���\���F%c\n",ch);
	printf("������\���F%s\n",str1);

	////����
	printf("--------------------����--------------------------\n");
	int a = 123;
	printf("�����\���F%d\n", a);
	printf("%6d\n", a);
	printf("%06d\n", a);
	printf("��������F%+d\n", a);
	printf(" 8�i�\���F%#o\n", a);
	printf("16�i�\���F%#x\n", a);

	////����
	printf("--------------------����--------------------------\n");
	float b = 31415.926535;
	printf("�����\���F%f\n", b);
	printf("�����_�ȉ�2���܂ŕ\���F%.2f\n", b);

}

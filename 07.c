#include <stdio.h>


int main(void) {

	//for (int i = 0; i < 10; i++) {
	//	if (i == 3 || i == 5)continue;
	//	if (i == 7)break;
	//	printf("i = %d\n", i);
	//}

	int a=100, b = 10;
	printf("���Z�q����́F");
	char ch;
	scanf("%c", &ch);
	switch (ch)
	{
	case '+':printf("�a�F%d\n",a + b);
		break;
	case '-':printf("���F%d\n",a - b);
		break;
	case '*':printf("��F%d\n",a * b);
		break;
	case '/':printf("���F%d\n",a / b);
		break;
	case '%':printf("���܂�F%d\n",a % b);
		break;
	default:
		printf("���Z�q����͂��Ă�������");
		break;
	}

}
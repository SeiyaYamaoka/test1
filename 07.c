#include <stdio.h>


int main(void) {

	//for (int i = 0; i < 10; i++) {
	//	if (i == 3 || i == 5)continue;
	//	if (i == 7)break;
	//	printf("i = %d\n", i);
	//}

	int a=100, b = 10;
	printf("演算子を入力：");
	char ch;
	scanf("%c", &ch);
	switch (ch)
	{
	case '+':printf("和：%d\n",a + b);
		break;
	case '-':printf("差：%d\n",a - b);
		break;
	case '*':printf("乗：%d\n",a * b);
		break;
	case '/':printf("除：%d\n",a / b);
		break;
	case '%':printf("あまり：%d\n",a % b);
		break;
	default:
		printf("演算子を入力してください");
		break;
	}

}
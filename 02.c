#include <stdio.h>

int main(void)
{
	//文字
	printf("--------------------文字--------------------------\n");
	char ch = 'A';
	char str1[] = "ArrowBlog";
	printf("一文字表示：%c\n",ch);
	printf("文字列表示：%s\n",str1);

	////整数
	printf("--------------------整数--------------------------\n");
	int a = 123;
	printf("整数表示：%d\n", a);
	printf("%6d\n", a);
	printf("%06d\n", a);
	printf("符号あり：%+d\n", a);
	printf(" 8進表示：%#o\n", a);
	printf("16進表示：%#x\n", a);

	////実数
	printf("--------------------実数--------------------------\n");
	float b = 31415.926535;
	printf("実数表示：%f\n", b);
	printf("小数点以下2桁まで表示：%.2f\n", b);

}

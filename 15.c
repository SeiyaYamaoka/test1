#include <stdio.h>
main() {
	char str1[255];
	char str2[255];
	char f_name[255];

	FILE *fp;
	printf("�ۑ��t�@�C����:");
	gets(f_name);
	printf("�ۑ�������e:");
	scanf("%s", str1);
	fp = fopen(f_name, "w");
	fprintf(fp, "%s", str1);
	fwrite(str1, sizeof(str1), 1, fp);
	fclose(fp);

	fp = fopen(f_name, "r");
	fscanf(fp, "%s", str2);
	fclose(fp);
	printf("str1 = %s\n", str1);
	printf("str2 = %s\n", str2);
}
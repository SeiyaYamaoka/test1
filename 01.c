#include <stdio.h>                      //�v���v���Z�b�T�Fprintf�Ƃ��W���̊֐��ǂ�ł�
#include <time.h>
main() {                                //�v���O�����n�܂�
	clock_t start, end,now;
	start = clock();
    int a = 100;                    //int�^�ϐ���100����
    printf("HelloWorld\n");         //HelloWorld�ƕ\�����ĉ��s
    printf("%d\n",a);               //�ϐ�a�̒l��\�����ĉ��s

	now = clock();

	printf("%f\n", (double)(now-start) / CLOCKS_PER_SEC);

	while ((double)(now - start) / CLOCKS_PER_SEC < 1.0) {
		now = clock();
	}
	
	end = clock();
	printf("%f�b������܂���\n", (double)(end - start) / CLOCKS_PER_SEC);
}                                       //�v���O�����I���
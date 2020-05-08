#include <stdio.h>                      //プリプロセッサ：printfとか標準の関数読んでる
#include <time.h>
main() {                                //プログラム始まり
	clock_t start, end,now;
	start = clock();
    int a = 100;                    //int型変数に100を代入
    printf("HelloWorld\n");         //HelloWorldと表示して改行
    printf("%d\n",a);               //変数aの値を表示して改行

	now = clock();

	printf("%f\n", (double)(now-start) / CLOCKS_PER_SEC);

	while ((double)(now - start) / CLOCKS_PER_SEC < 1.0) {
		now = clock();
	}
	
	end = clock();
	printf("%f秒かかりました\n", (double)(end - start) / CLOCKS_PER_SEC);
}                                       //プログラム終わり
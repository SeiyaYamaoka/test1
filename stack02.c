#include "dglib2.h"
#include <conio.h>
char_far gvram;
#define SX 1
#define SY 1
#define PIXEL 1


#define HEIGHT 479
#define WIDTH 639
#define GX (WIDTH - 2)
#define GY (HEIGHT - 2)
int map[HEIGHT][WIDTH]; /*= {
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,1,0,0,1},
	{1,0,1,0,1,0,0,0,1,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,1,0,1,0,1,0,1,0,1},
	{1,0,0,0,0,1,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}
};*/
#define STACKSIZE 32768
int stack[STACKSIZE];
int sp = 0;

int save[32765], cnt = 0;
int mx, my;

int push(int d);
int pop(int *pd);
int susumu(int x, int y);
void meiro_init(void);
void meiro_horu(void);
int meiro_hantei(void);
void meiro_read(void);
main() {
	dg_setscreen(0, 0, WIDTH, HEIGHT, 0, "test");

	int w, h;
	COLORREF color[] = { RGB(0,0,0),RGB(0,255,0) };
	meiro_read();
	for (h = 0; h < HEIGHT; h++) {
		for (w = 0; w < WIDTH; w++) {
			dg_box(gvram, w * PIXEL, h * PIXEL, PIXEL, PIXEL, 1, color[map[h][w]]);

		}
	}
	dg_box(gvram, GX * PIXEL, GY * PIXEL, PIXEL, PIXEL, 1, RGB(255, 0, 0));

	susumu(SX, SY);
	getch();
}
int push(int d) {
	if (sp == STACKSIZE) { return -1; }
	stack[sp] = d;
	sp++;
	return 0;
}
int pop(int *pd) {
	if (sp == 0) { return -1; }
	sp--;
	*pd = stack[sp];
	stack[sp] = 0;
	return 0;
}
int susumu(int x, int y) {
	int i;

	while (1) {

		//dg_printf(160, 0, RGB(255, 255, 255), "x:%2d y:%2d", x, y);
		map[y][x] = 1;
		dg_box(gvram, x * PIXEL, y * PIXEL, PIXEL, PIXEL, 1, RGB(255, 255, 255));
		Sleep(0);
		if (x == GX&&y == GY) { return 0; }
		push(x);
		push(y);

	//	for (i = 0; i < STACKSIZE; i += 2) {
	///*		dg_printf(160, 10 + i / 2 * 10, RGB(255, 255, 255), "%2d %2d", stack[i], stack[i + 1]);*/
	//		if (stack[i] != 0) {
	//			dg_box(gvram, stack[i] * PIXEL, stack[i + 1] * PIXEL, PIXEL, PIXEL, 0, RGB(255, 0, 255));
	//		}
	//	}
		if (map[y - 1][x] == 0) { y -= 1; continue; }
		if (map[y + 1][x] == 0) { y += 1; continue; }
		if (map[y][x - 1] == 0) { x -= 1; continue; }
		if (map[y][x + 1] == 0) { x += 1; continue; }
		pop(&y);
		pop(&x);

		dg_box(gvram, x * PIXEL, y * PIXEL, PIXEL, PIXEL, 1, RGB(0, 0, 0));
		pop(&y);
		if (pop(&x) == -1) { return -1; }

	}
}
void meiro_init(void) {
	int i, j;
	for (i = 0; i < HEIGHT; i++) {//s”•ª‚ÌŒJ‚è•Ô‚µ
		for (j = 0; j < WIDTH; j++) {//—ñ”•ª‚ÌŒJ‚è•Ô‚µ

			map[i][j] = 1;

		}
	}
	return;
}
void meiro_horu(void) {
	int h;

	h = rand() % 4 + 1;
	switch (h) {
	case 1:
		if (my - 2 >= 1 && map[my - 2][mx] == 1) {
			map[my - 1][mx] = 0;
			map[my - 2][mx] = 0;
			my -= 2;
			save[cnt] = h;
			cnt++;
		}
		break;
	case 2:
		if (my + 2 < HEIGHT - 1 && map[my + 2][mx] == 1) {
			map[my + 1][mx] = 0;
			map[my + 2][mx] = 0;
			my += 2;
			save[cnt] = h;
			cnt++;
		}
		break;
	case 3:
		if (mx - 2 >= 1 && map[my][mx - 2] == 1) {
			map[my][mx - 1] = 0;
			map[my][mx - 2] = 0;
			mx -= 2;
			save[cnt] = h;
			cnt++;
		}
		break;
	case 4:
		if (mx + 2 < WIDTH - 1 && map[my][mx + 2] == 1) {
			map[my][mx + 1] = 0;
			map[my][mx + 2] = 0;
			mx += 2;
			save[cnt] = h;
			cnt++;
		}
		break;
	}
	return;
}
int meiro_hantei(void) {
	int flg = 0;
	if (my - 2 >= 1 && map[my - 2][mx] == 1) { flg = 1; }
	if (my + 2 < HEIGHT - 1 && map[my + 2][mx] == 1) { flg = 1; }
	if (mx - 2 >= 1 && map[my][mx - 2] == 1) { flg = 1; }
	if (mx + 2 < WIDTH - 1 && map[my][mx + 2] == 1) { flg = 1; }
	if (flg == 0) {
		cnt--;
		if (cnt < 0) { return 1; }
		if (save[cnt] == 1) { my += 2; }
		if (save[cnt] == 2) { my -= 2; }
		if (save[cnt] == 3) { mx += 2; }
		if (save[cnt] == 4) { mx -= 2; }
		save[cnt] = 0;
	}
	return 0;
}
void meiro_read(void) {
	srand(time(0));

	meiro_init();
	mx = 1;
	my = 1;
	map[my][mx] = 0;

	while (1) {
		meiro_horu();
		if (meiro_hantei() == 1) { break; }
	}
	map[GY][GX] = 0;
	return;
}
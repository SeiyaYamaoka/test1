#include <stdio.h>
#include"dglib2.h"
char_far DEBUG

#define STACKSIZE 1000
int stack[STACKSIZE];
int sp = 0;
int push(int d);
int pop(int *pd);
void paint(int x, int y, COLORREF color);

main() {
	dg_circle(gvram, 100, 100, 12, RGB(0, 0, 255));
	dg_circle(gvram, 120, 100, 22, RGB(255, 0, 0));
	getch();
	paint(100, 100, RGB(0, 255, 0));
	getch();
}
int push(int d) {

}
int pop(int *pd) {

}
void paint(int x, int y, COLORREF color) {

}
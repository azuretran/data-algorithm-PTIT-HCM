#include"graphics.h"
#define Lmargin 10
#define Enter 13
void text_write(int* x, int* y, char* s)
{
	outtextxy(*x, *y, s); *x += textwidth(s);
}
void text_writeln(int* x, int* y, char* s)
{
	outtextxy(*x, *y, s);
	*x = Lmargin;
	*y += textheight(s) + 5;
}
void xoa(char* s, int vt)
{
	strcpy(s + vt, s + vt + 1);
	puts(s);
}

void text_read(int* x, int* y, char *s)
{
	int i = 0; char ch[2];
	ch[1] = 0;
	while (1)
	{
		ch[0] = getch();
		if (ch[0] == Enter) break;
		
		text_write(x, y, ch);
		s[i] = ch[0]; ++i;
	}
	
	s[i] = 0;
}

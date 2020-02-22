#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <curses.h>
#include <math.h>

WINDOW *w;
int num,i;
int isstop=0;
void handle(int s)
{
	if(s==SIGUSR1)
	{
		if(isstop==0) isstop=1;
		else isstop=0;
	}
}
main()
{
	initscr();
	curs_set(0);	//0：隐藏光标  1、2：显示光标（2、高亮光标）
	w=derwin(stdscr,3,11,(LINES-3)/2,(COLS-11)/2);
	keypad(stdscr,TRUE);	//支持功能键
	keypad(w,TRUE);	//支持功能键
	noecho();//关闭回显

	box(w,0,0);
	refresh();
	wrefresh(w);
	
	if(fork())
	{
	signal(SIGUSR1,handle);
	while(1)
	{
		if(isstop==1)
		{
			pause(); //会被信号中断停止
		}
		num = 0;
		for(i=0;i<7;i++)
		{
			num=num*10+rand()%10;
		}
		mvwprintw(w,1,2,"%07d",num);
		refresh();
		wrefresh(w);
		usleep(10000);
	}
	}
	else //child
	{
		//输入
		int ch;
		while(1)
		{
			ch = getch();
			//if(ch == KEY_ENTER)
			{
				kill(getppid(),SIGUSR1);	//向父进程发送信号
			}
		}
	}

	endwin();
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <curses.h>
#include <math.h>
#include <time.h>

//全局变量的两个窗体
WINDOW *wtime,*wnumb;
pthread_t thnumb,thtime;
pthread_mutex_t m;
//线程1：随机数
void* runnumb(void* d)
{
	
	int num;
	while(1)
	{
//	循环产生7位随机数
	num=rand()%10000000;
//	显示
	pthread_mutex_lock(&m);
	mvwprintw(wnumb,1,2,"%07d",num);
//	刷新
	refresh();
	wrefresh(wnumb);
	pthread_mutex_unlock(&m);
	usleep(1);
	}
	return 0;
}
//线程2：时间
void* runtime(void* d)
{
	time_t tt;
	struct tm *t;
	while(1)
	{
//	循环取时间
		tt = time(0);
		t=localtime(&tt);
//	显示
		pthread_mutex_lock(&m);
		mvwprintw(wtime,1,1,"%02d:%02d:%02d",
			t->tm_hour,t->tm_min,t->tm_sec);
//	刷新
		refresh();
		wrefresh(wtime);
		pthread_mutex_unlock(&m);
		usleep(1);
	}
}

main()
{
	//初始化curses
	initscr();
	curs_set(0);	//隐藏光标
	noecho();	//不要回显
	keypad(stdscr,TRUE);//屏蔽功能键
	wnumb=derwin(stdscr,3,11,(LINES-3)/2,(COLS-11)/2);
	wtime = derwin(stdscr,3,10,0,COLS-10);
	box(wnumb,0,0);
	box(wtime,0,0);
	refresh();
	wrefresh(wnumb);
	wrefresh(wtime);
	pthread_mutex_init(&m,0);
	//创建线程1
	pthread_create(&thnumb,0,runnumb,0);
	//创建线程2
	pthread_create(&thtime,0,runtime,0);
	//等待按键
	//结束
	getch();
	pthread_mutex_destroy(&m);
	delwin(wnumb);
	delwin(wtime);
	endwin();
}

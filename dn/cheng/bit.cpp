#include <stdio.h>
struct CHAR2
{
	unsigned char ch;
	unsigned char font;
	unsigned int  size;
};
int main()
{	
	struct CHAR2 ch2;
	printf("%d\n",sizeof(ch2));
	//printf("%d\n",strlen(ch2));
}

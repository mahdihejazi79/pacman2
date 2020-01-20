#include <stdio.h>
#include<stdlib.h>
#include<windows.h>

void gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorCoord;
	cursorCoord.X=x;
	cursorCoord.Y=y;
	SetConsoleCursorPosition(consoleHandle, cursorCoord);
}

int printmap(char map[5][10],int *s,int *t)
{
	gotoxy(30,11);
	
	int i,j,score=0;
	for(i=0;i<12;i++)
	printf("%c",254);
	printf("\n");
	
	for(i=0;i<5;i++)
	{
		gotoxy(30,12+i);
		
		printf("%c",254);
		
		for(j=0;j<10;j++)
		{
			if(map[i][j]=='0')
			{
				printf("%c",1);
				*s=i;
				*t=j;
			}
			if(map[i][j]=='1')
			printf(" ");
			if(map[i][j]=='*')
			{
				printf(".");
				score++;
			}

			if(map[i][j]=='#')
			printf("%c",254);
		}
	
		printf("%c",254);
		printf("\n");
	}
	
	gotoxy(30,17);

	for(i=0;i<12;i++)
	printf("%c",254);
	printf("\n");
	
	return score;
}
int main()
{
	char map[5][10],c;
	int i=0,j=0,s,t,score;
	
	FILE *p;
	p=fopen("Testcase02.txt","r");
	
	while(feof(p)==0)
	fgets(map[i++],100,p);
	
	fclose(p);
	
	gotoxy(0,8);
	printf("enter -1 to finish or enter up,down,right,left\n");
	
	score=printmap(map,&s,&t);
	
	while(score!=0)
	{
		c=getch();
		if(c==-32)
		{
			c=getch();
			if(c==72)
			{
				if(map[s-1][t]=='#' || s==0)
				printf("You can’t move to up! There is an obstacle\n");
				else
				{
					map[s][t]='1';
					map[s-1][t]='0';
				}
			}
			if(c==80)
			{
				if(map[s+1][t]=='#' || s==4)
				printf("You can’t move to down! There is an obstacle\n");
				else
				{
					map[s][t]='1';
					map[s+1][t]='0';
				}
			}
			if(c==77)
			{
				if(map[s][t+1]=='#' || t==9)
				printf("You can’t move to right! There is an obstacle\n");
				else
				{
					map[s][t]='1';
					map[s][t+1]='0';
				}
			}
			if(c==75)
			{
				if(map[s][t-1]=='#' || t==0)
				printf("You can’t move to left! There is an obstacle\n");
				else
				{
					map[s][t]='1';
					map[s][t-1]='0';
				}
			}
			
			score=printmap(map,&s,&t);
		}
		else if(c=='-' && (c=getch())=='1')
		{
			printf("The game is over!                                     ");
			return 0;
		}	
	}
	printf("Pacman finished eating!                                      ");	
}

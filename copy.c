#include <stdio.h>
int taken[9]={0,0,0,0,0,0,0,0,0};
int choice[9]={1,2,3,4,5,6,7,8,9};
char plot[9]={'_','_','_','_','_','_','_','_','_'};
int entry;
int compe;
int i=0,cp=1;
int main()
{
	srand(time(0));
	printf("please Enter N to Start\n");
	while(entry !='N')
    		scanf("%c",&entry);
	printf("Start Player\n");
	while(win())
	{
	label:  scanf("%d",&entry);
		printf("\n");	
		//compe = rand()%9;
		if(taken[entry-1] ==0 && entry < 10)
		{
			taken[entry-1]=1;
			choice[entry-1]=0;
			plot[entry-1]='@';		
		}
		else
		{
			printf("please enter another number\n"); 
			goto label;
		}
		if(taken[0] != 0 && taken[1] != 0 && taken[2] != 0 && taken[3] != 0 && taken[4] != 0 && taken[5] != 0 && taken[6] != 0 && taken[7] != 0 && taken[8] != 0)
		{
			win();
			break;
		}
		if(cp <5)
		{
		rando();
		cp++;
		}
		for(i=1;i<10;i++)
		{
		printf("%c \t",plot[i-1]);
		if(i%3 ==0)
		printf("\n");
		}
		printf("\n");		
//-------------------This is for debugging delete after debugging ----------------------------//
/*printf("choice\t");
for(i=0;i<9;i++)
printf("%d \t",choice[i]);
printf("\n");
printf("Taken\t");
for(i=0;i<9;i++)
printf("%d \t",taken[i]);
printf("\n");
*///--------------------------------------------------------------------------------------------//
	}
	printf("Thanks For Playing\n");
	printf("Press F to Play again and Q to quit\n");
    return 0;
}
int win(void)
{
int win1 = taken[1]+taken[2]+taken[0];
int win2 = taken[4]+taken[5]+taken[3];
int win3 = taken[7]+taken[8]+taken[6];
int win4 = taken[0]+taken[3]+taken[6];
int win5 = taken[1]+taken[4]+taken[7];
int win6 = taken[2]+taken[5]+taken[8];
int win7 = taken[0]+taken[4]+taken[8];
int win8 = taken[6]+taken[4]+taken[2];
if(win1 == 3 || win2 == 3 || win3 == 3 || win4 == 3 || win5 == 3 || win6 == 3 || win7 == 3 || win8 == 3)
	{
	printf("player won\n");
	return 0;
	}
if(win1 == 15 || win2 == 15 || win3 == 15 || win4 == 15 || win5 == 15 || win6 == 15 || win7 == 15 || win8 == 15)
	{
	printf("Computer won\n");
	return 0;
	}
return 1;
}
void rando(void)
{
	int comp = rand()%9;
	printf("i am thinking\n");
	if(choice[comp]==0)
		rando();
	compe = comp;
	if(taken[compe] == 0)
	{
		choice[compe]=0;
		taken[compe]=5;
		plot[compe]='#';
	}
}

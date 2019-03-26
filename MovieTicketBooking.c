#include<stdio.h>
#include<windows.h>
#include<conio.h>
struct movie
{
	int a[15][12];
	struct book
	{
	int n,x[6],ch;
	char v;
	}z[20];
}m[5];
int cancel();
int buy();
void printstatus(int ch);
int main()
{
	int i,ch;
	do
	{
	system("cls");
	printf("Enter your choice \n1.Seat Availability\n2.Book a Ticket\n3.Cancel Ticket\n4.Exit\n\t :");
	scanf("%d",&i);
	switch(i)
	{
		case 1:
			printf("Enter the movie code\nMovie\t\tCode\n1.Ghazi\t\t\'1\'\n2.singam-3\t\'2\'\n3.Gunturodu\t\'3\'\n4.Jolly llb-2\t\'4\'\n");
			scanf("%d",&ch);
			printstatus(ch-1);
			break;
		case 2:
			if(buy()!=1)
			printf("\n\t\t\t\tBooking Successfull\n");
			else
			printf("\n\t\t\t\tBooking Unsuccessfull\n");
			printf("\t\t\t\tPress ENTER to continue");
			getch();
			break;
		case 3:
			system("cls");
			if(cancel()==1)
				printf("\n\t\t\t\tCancellation Sucessfull\n");
			else
				printf("\n\t\t\t\tCancellation Unsucessfull\n");
			printf("\t\t\t\tPress ENTER to continue");
			getch();
			break;
		default :
			break;
	}
}while(i<4);
return 0;
}
int buy()
{
	int t,n,q,i,j,ch;
	static int k=0;
	char r;
	printf("Enter the code of the movie\nMovie\t\tCode\n1.Ghazi\t\t\'1\'\n2.Singham-3\t\'2\'\n3.Gunturodu\t\'3\'\n4.Jolly llb-2\t\'4\'\n");
	scanf("%d",&ch);
	ch--;
	system("cls");
	if(ch>=0&&ch<4)
	{
		printstatus(ch);
		printf("\nEnter the Number of Tickets(Max:6): ");
		scanf("%d",&t);
		if(t>0&&t<7)
			{
			printf("Enter the Row In letter(CAPITAL): ");
			scanf(" %c ",&r);
			if(r>='A'&&r<='O')
				{
					n=t;
					i=0;
					j=0;
					while(t--)
					{
					scanf("%d",&q);
					if((m[ch].a[r-65][q-1]!=2)&&q<=12)
						{
						m[ch].z[k].x[j]=q;
						j++;
						m[ch].a[r-65][q-1]=2;
						i++;
						}
					else
						{
						printf("\n\t\t\t\tWrong Seat Selected\n");
						return 1;
						}
					}
					m[ch].z[k].v=r;
					m[ch].z[k].n=n;
					k++;
				}
			else
				{
				printf("\n\t\t\t\tWrong Row Selected\n");
				return 1;
				}
				printf("\n");
				printf("\t\t\t\t%d is the ID for seats",k);
				printf("\n\t\t\t\tTotal Amount=%d",i*100);
				return 0;
				}
		else
			{
			printf("\t\t\t\tWrong No of tickects seleted");
			return 1;
			}
		}
	else
		{
		printf("\t\t\t\tWorng Movie Seleted");
		return 1;
		}
}
int cancel()
{
	int t,q,i,j,ch;
	char r;
	system("cls");
	printf("Enter the code of the movie\nMovie\t\tCode\n1.Ghazi\t\t\'1\'\n2.Singham-3\t\'2\'\n3.Gunturodu\t\'3\'\n4.Jolly llb-2\t\'4\'\n");
	scanf("%d",&ch);
	ch--;
	printf("\nEnter the ID    :");
	scanf("%d",&i);
	if(m[ch].z[i-1].n!=0)
	{
	if(i>0&&i<20)
	{
	t=m[ch].z[i-1].n;
	r=m[ch].z[i-1].v;
	j=0;
	while(t--)
	{
		q=m[ch].z[i-1].x[j];
		j++;
		m[ch].a[r-65][q-1]=0;
	}
	m[ch].z[i-1].n=0;
	return 1;
}
else
{
	printf("check the id\n");
return 0;
}
}
return 0;
}
void printstatus(int ch)
{
	int i,j;
	for(i=0;i<15;i++)
	{
		for(j=0;j<12;j++)
		{
			if((m[ch].a[i][j])==2)
				printf("   \t ");
			else
				printf(" %c%d\t ",i+65,j+1);
	}
		printf("\n");
	}
	printf("\nPress ENTER to continue");
	getch();
}

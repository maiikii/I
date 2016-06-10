#include<stdio.h>
#include<conio.h>

int main(void)
{
    int n, cf=2, temp, p=0;
    printf("Enter a number: ");
	scanf("%d", &n);
	temp=n;
	while(cf<temp)
	{
		if(temp%cf==0)
		{
			printf("\n\n%d is not a Germain Prime.", n);
			break;
		}
		else
		{
			cf++;
			if(cf*cf>temp)
			{
				p=1;
				break;
			}
		{
	}
	
	if(p==1)
    {
		temp=2*temp+1;
		cf=2;
		while(cf<temp)
		{
			if(temp%cf==0)
			{
				printf("\n\n%d is not a Germain Prime.", n);
				break;
			}
			else
			{
				cf++;
				if(cf*cf>temp)
				{
					printf("\n\n%d is not a Germain Prime.", n);
					break;
				}
          }
		}
	}

	getch();
	return 0;
}

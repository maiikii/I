#include<stdio.h>
#include<conio.h>

int main(void)
{
    int n, cf=2, temp, p=0;
    printf("Enter a number: ");
	scanf("%d", &n);

    while(cf<n){
	if(n%cf==0){
		printf("Not Germain Prime.");
		break;}
	else{
		cf++;
		if(cf*cf>n){
			p=1;
			break;}
		}
    }
    
    if(p==1)
    {
            temp=2*n+1;
            while(cf<temp)
            {
                       if(temp%cf==0)
                       {
                           printf("Not Germain Prime.");
		                   break;
                     }
            else{
		         cf++;
		         if(cf*cf>temp)
                 {
                     printf("Germain Prime.");
                     break;
                 }
           }
           }
    }
    getch();
    return 0;
}

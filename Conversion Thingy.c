#include <stdio.h>
#include <string.h>

int convert(int x, int y);
void convert2(int x, int y);

int main() {
	int dec;
	int base;
	
	printf("Input Decimal: ");
	scanf("%d", &dec);
	printf("Base: ");
	scanf("%d", &base);
	printf("\nEquivalent is: ");
	printf("\n");
	
	if(base<10){	
		printf("\n%d", convert(dec, base));
		printf("\n");
	}else {
		convert2(dec, base);
	}
  
  return 0;
}

//if y<10

int convert(int x, int y) {
	int q;
	int mod;
	int conv = 0;
	int temp = 1;
	
	while(x>0) {
		
		mod=x%y;
		q=x/y;
		conv=conv+(temp*mod);
		temp*=10;
		
		if(q<y) {
			conv=(q*temp)+conv;
			x=0;
			
		} else {
			x=q;
		}
  }
  return (conv);
}

//y>=10

void convert2(int x, int y){
	
	char arr[100];
	int i=0;
		
		while(x >= y) {
    arr[i]=x%y;
    
			x/=y;	
			i++;
		}		
		
		if(x >= 10) {
        printf("%c", x+55);
		} else {
		  	printf("\n%d", x);
      }
		
		for(i-=1; i>=0; i--) {
			
		if(arr[i] >= 10) {
        printf("%c", arr[i] = arr[i] + 55);
		} else {
		  	printf("%d", arr[i]);
      }
    }
        printf("\n");
  }

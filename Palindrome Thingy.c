#include <stdio.h>

int pal(int x);

int main () {

  printf("\n%d", pal(120121)); 	//0
	printf("\n%d", pal(10201));		//1
	printf("\n%d", pal(11));		//1
	printf("\n%d", pal(1230321));	//1
	printf("\n%d", pal(123));		//0
	
	return 0;
    }
    
    int pal(int x){
		
      int i=x;
      int start;
      int last;
	    int temp=1;
	    int j;
	    int l=x;
      
    if(x<10) {
        return 1;
      }
	  
   else if(x>=10) {
		
		   last = x % 10;
		
		while(l > 0){
			l/=10;
			j*=10;
		}
		  
    while (i >= 10) {
		  i /= 10;
      temp *= 10;
        }
		
		start=i;
		
      }
      if(start==last){
        x=x-((i*temp)+(x%10));
        pal(x/10);
      }
      else {
        return 0;  
          }
		}

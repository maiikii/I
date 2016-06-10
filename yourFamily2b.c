#include<stdio.h>

int main(void)
{
	float eu, php, exr;
	printf("Enter amount in euros: ");
	scanf("%f", &eu);
	printf("\nEnter exchange rate(euro to pesos): ");
	scanf("%f", &exr);
	php=eu*exr;
	printf("\n%.2f eu is equivalent to %.2f php.", eu, php);
	return 0;
}

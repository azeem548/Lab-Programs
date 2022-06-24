#include<stdio.h>
int main(){
	int a=10, b=20, c=30, max;
	max = (a>b&&a>c)?a:(b>c&&b>a)?b:c;
	printf("max: %d",max);
	}

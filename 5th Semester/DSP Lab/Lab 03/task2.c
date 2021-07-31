#include <stdio.h>
#include <fract.h>


int main()
{
	float a=7.3,b=12.4,sum1,diff1,mult1,div1;
	fract16 c=7.3,d=12.4,sum2,diff2,mult2,div2;
	int i;
	
	for(i=0;i<20000;i++)
	{
		sum1=a+b;
		diff1=a-b;
		div1=a/b;
		mult1=a*b;
		
		sum2=c+d;
		diff2=c-d;
		mult2=c*d;
		div2=c/d;
	} 
	return 0;
}

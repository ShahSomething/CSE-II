#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
	FILE *fp;
	fp = fopen("mydata","wb");
	int i;
	int rnumbers[5];
	for(i=0;i<5;i++)
	{
		srand(time(0)+i);
		rnumbers[i] = rand();
	} 
	fwrite(rnumbers,sizeof(int),5,fp);
	fclose(fp);
	fp = fopen("mydata","rb");
	int buffer[5];
	fread(buffer,sizeof(int),5,fp);
	fclose(fp);
	for(i=0;i<5;i++)
	{
		printf("%d  ",buffer[i]);
	} 
	return 0;

}

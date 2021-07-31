#include <stdio.h>


int main()
{
    int Buffer[5];
	FILE *fp;
	fp = fopen("MatArray","rb");
	fread(Buffer,sizeof(int),5,fp);
	fclose(fp);
	return 0;

}
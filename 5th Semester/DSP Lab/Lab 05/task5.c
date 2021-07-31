#include <stdio.h>


int main()
{
    short Array[5] = {1,2,3,4,5};
	FILE *fp;
	fp = fopen("array.txt","wb");
	fwrite(Array,sizeof(short),5,fp);
	fclose(fp);
	return 0;

}

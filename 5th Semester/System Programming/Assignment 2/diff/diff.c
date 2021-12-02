#include<stdio.h>
#include<string.h>

struct lines{
    char stack_lines1[100];
    char stack_lines2[100];
};


int main(int argc,char *argv[])
{
    struct lines st[20];
    FILE *file1,*file2;
    char line1[100],line2[100];
    int line_count1=0,flag2[10],flag1[10],line_count2=0;
    int i=0,j=0,k=0,n=0,m=0,o=0;

    file1 = fopen(argv[1],"r");
    file2 = fopen(argv[2],"r");

    while(1)
    {
        line_count1++;
        line_count2++;
        if(fscanf(file1,"%[^\n]\n",line1)!=EOF && fscanf(file2,"%[^\n]\n",line2)!=EOF)
        {
            if(strcmp(line1,line2) == 0)
            continue;
            else{
                if(line1 != NULL){
                    strcpy(st[i].stack_lines1 , line1);
                    flag1[m]=line_count1;
                    m++;
                }
                if(line2 != NULL){
                    strcpy(st[i].stack_lines2 , line2);
                    flag2[o]=line_count2;
                    o++;
                }
            }
        }
        else if(fscanf(file1,"%[^\n]\n",line1)!=EOF){
            strcpy(st[i].stack_lines1 , line1);
            flag1[m]=line_count1;
            m++;
        }
        else if(fscanf(file2,"%[^\n]\n",line2)!=EOF){
            strcpy(st[i].stack_lines2 , line2);
            flag2[o]=line_count2;
            o++;
        }
        else
            break;
        i++;
        n++;
    }
    for(i=0;i<m;i++)
    {
        printf("%d,",flag1[i]);
    }
    printf("c");
    for(i=0;i<o;i++)
    {
        printf("%d,",flag2[i]);
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("%s\n",st[i].stack_lines1);
    }
    printf("---\n");
    for(i=0;i<n;i++)
    {
        printf("%s\n",st[i].stack_lines2);
    }
    fclose(file1);
    fclose(file2);
    return 0;
}
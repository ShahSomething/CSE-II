/*
	Name: Shah Raza
	Assignment no: 2
	Question #2
*/

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

/*
	Since we are not allowed to use printf, we need some other means to print to 
	the console. And for that I am using write() system call. The problem is that 
	write() system call can only be used to print strings. So if we want to print an 
	integer then we need to first convert it to string.
*/
char *ConvertToString(int num, int base)
{
    static char Representation[]= "0123456789ABCDEF";
    static char buffer[50];
    char *ptr;
    ptr = &buffer[49];
    *ptr = '\0';
    do
    {
        *--ptr = Representation[num%base];
        num /= base;
    }while(num != 0);
    return(ptr);
}

//nprintf will work the same as printf without buffering
void nprintf(char *format,...)
{
    char *chp;
    char *string;
    int num;
    char ch;
    va_list arguments;
    va_start(arguments,format);

    chp = format;

    while(*chp!='\0')
    {
        if(*chp=='%')
        {
            chp++;
            switch(*chp)
            {
                case 'd':
                    num = va_arg(arguments,int);
                    if(num<0)
                    {
                        num=-num;
                        ch = '-';
                        write(STDOUT_FILENO,&ch,1);
                        //fflush will clear stdout's buffer
                        fflush(stdout);
                    }
                    string = ConvertToString(num,10);
                    write(STDOUT_FILENO,string,strlen(string));
                    fflush(stdout);
                    break;
                case 's':
                    string = va_arg(arguments,char *);
                    write(STDOUT_FILENO,string,strlen(string));
                    fflush(stdout);
                    break;
                case 'c':
                    ch = va_arg(arguments,int);
                    write(STDOUT_FILENO,&ch,1);
                    fflush(stdout);
                    break;
            }
        }
        else
        {
        write(STDOUT_FILENO,chp,1);
        fflush(stdout);
        }
        chp++;
    }
    va_end(arguments);
}

int main()
{
    char *s = "SHAH RAZA";
    char ch = 'S';
    int num = 7;
    nprintf("String: %s\nCharacter: %c\nNumber: %d\n",s,ch,num);
}

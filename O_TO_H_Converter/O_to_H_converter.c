#include<stdio.h>
int main(int argc,char **argv)
{
if(argc!=2)
{
printf("./a.out <opcode_filename>\n");
return 0
}

FILE *fp = fopen(argv[1],"w");

if(fp==0)
{
printf("File Not Found\n");
return 0;
}

char s[10];
fscanf("%s")



return 0;
}

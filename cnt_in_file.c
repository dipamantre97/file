#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,char**argv)
{
	FILE *fp;
	char ch;
	char *buf=NULL;
	int i=0,cnt=0,size=0,line=0,charr=0;
	if(argc<2)
	{
		printf("error:require argument");
		return 0;
	}
	fp=fopen(argv[1],"r");
	if(fp==NULL)
	{
		printf("file not exit");
		return 0;
	}
	fseek(fp,0,2);
	size=ftell(fp);
	buf=calloc(1,size+1);
	fread(buf,size,1,fp);
	fclose(fp);
	puts(buf);
	for(i=0;buf[i];i++)
	{
		if(buf[i]==32&&buf[i+1]!=32)||(buf[i+1]==10&&buf[i]!=10))
		{
			cnt++;
		}
		if(buf[i]=='\n')
		{
			line++;
		}
		charr++;
	}
	printf("no of words=%d\n",cnt);
	printf("no of line=%d\n",line);
	printf("no of char=%d",charr);
}







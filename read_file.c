#include<stdio.h>
#include<stdlib.h>
struct record
{
	char nmae[20];
	int roll;
	int marks;
}student;
int main()
{
	FILE *fp;
	fp=fopen("stu","rb");
	{
		printf("error in opening file\n");
		exit(1);
	}
	printf("\nNAME\tROLLNO\tMARKS\n");
	while(fread(&student,sizeof(student),1,fp)==1)
	{
		printf("%s\t",student.name);
		printf("%d\t",student.roll);
		printf("%d\n",student.marks);
	}
	fclose(fp);
	return 0;
}


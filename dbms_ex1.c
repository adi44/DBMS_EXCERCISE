#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
	int rollno;
	char name[100];
	float cgpa;
	char branch[4];
}student;
char *randstring() {

    static char charset[] = "abcdefghijklmnopqrstuvwxy";        
    char *randomString = NULL;

 {
        randomString = malloc(sizeof(char) * (10 +1));

        if (randomString) {            
            for (int n = 0;n < 10;n++) {            
                int key = rand() % (int)(sizeof(charset) -1);
                randomString[n] = charset[key];
            }

            randomString[11] = '\0';
        }
    }

    return randomString;
}


int add_record()
{
	FILE *fp;
	int n;
	fp=fopen("student_record.dat","a+");
	printf("enter the number of students you want to enter");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		student.rollno=i;
		strcpy(student.name,randstring());
		student.cgpa=10;
		strcpy(student.branch,"cse");
		fwrite (&student, sizeof(struct student), 1, fp);
	}
	fclose(fp);
	return 0;
}
int search_record()
{	struct student search[100];
	FILE *fp;
	int roll,i=0;
	fp=fopen("student_record.dat","r");
	printf("Enter the Roll Number you want to search");
	scanf("%d",&roll);
	//fread(student, sizeof(student),1,fp);
	while(fread (&student, sizeof(struct student), 1, fp))
	{	
		if(student.rollno==roll)
		{
			printf("Roll No: %d\nName: %s\nCGPA: %f\nBranch: %s",student.rollno,student.name,student.cgpa,student.branch);
		}
		
		
	}
	
}
int main()
{
	add_record();
	search_record();
	return 0;
}

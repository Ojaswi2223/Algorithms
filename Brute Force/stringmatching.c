#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int opcount=0;

int stringmatch(char t[],char p[])
{
	int i,j,n,m;
	n=strlen(t);
	m=strlen(p);
	for(i=0;i<n;i++)
    {
        j=0;
        while((opcount++)&& (j<m) && (t[i+j]==p[j]))b
        {
        	
            j++;
            if(j==m)
                return i+1;  //pattern found
        }
    }
    return -1;  //pattern not found
}

int main()
{
	char t[100];
	char p[100];
	printf("Enter the main string :\n");
	scanf("%s",t);
	printf("Enter the string pattern to be searched :\n");
	scanf("%s",p);
	int match=stringmatch(t,p);
	printf("Basic operation count = %d\n",opcount);
	if(match==-1)
		printf("String not found\n");
	else
		printf("String found\n");
	return 0;
}

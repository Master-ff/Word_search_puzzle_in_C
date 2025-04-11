#include <stdio.h>
#include <string.h>



char word[30][30];
char puzzle[40][40];
int p,h;



void openFile() //opens the text file and reads the chunk of letters and words into 2D arrays
{
	FILE *f;
	f=fopen("maths.txt","r");
	if(f==NULL)
	{
		printf("Couldn't open file\n ");
	}
		fscanf(f,"%d %d",&p ,&h);
		char l[40], l2[40];
		int i, rows=0;
		while(fgets(l, sizeof(l), f)!=NULL && rows<p)
		{
			for(i=0;i<(strlen(l)-1);i++)
			{
				puzzle[rows][i]=l[i];
			}
			rows++;
		}

		rows=0;
		while(fgets(l2,sizeof(l2),f)!=NULL)
		{
			for (i=0;i<(strlen(l2)-1);i++)
			{
				word[rows][i]=l2[i];
			}
			rows++;
		
		}
	fclose(f);
}


void readData()  //prints the chunk of letters
{
	int i=0;
	for(i=0;i<p;i++)
	{
		printf("%s\n",puzzle[i]);
	}
		printf("\n\n");
}



void readWords() // reads the word that were given
{
	int i=0;
	for(i=0;i<h;i++)
	{
		printf("%10s",word[i]);
		if((i+1)%4==0)
			printf("\n");
	}
	printf("\n..................................................................\n");

}

int search (int a, int n, int b, char test[]) // searches in downward direction
{
	char test2[n];
	int i=0;
	for(i=0;i<n;i++)
	{
		test2[i]=puzzle[a][b];
		a++;
	}
	test2[n]='\0';
	if (strcmp(test2,test)==0)
	{
		printf("%10s",test2);
		return 1;
	}
	else return -1;
}

int search1 (int a, int n, int b, char test[]) // searches in right direction
{
	char test2[n];
	int i=0;
	for(i=0;i<n;i++)
	{
		test2[i]=puzzle[a][b];
		b++;
	}
	test2[n]='\0';
	if (strcmp(test2,test)==0)
	{
		printf("%10s",test2);
		return 2;
	}
	else return -1;
}
							

int search2 (int a, int n, int b, char test[])  // searches in diagonal direction(down,right)
{
	char test2[n];
	int i=0;
	for(i=0;i<n;i++)
	{
		test2[i]=puzzle[a][b];
		a++;
		b++;
	}
	test2[n]='\0';
	if (strcmp(test2,test)==0)
	{
		printf("%10s",test2);
		return 3;
	}
	else return -1;
}


int search3 (int a, int n, int b, char test[])  //searches in upward direction
{
	char test2[n];
	int i=0;
	for(i=0;i<n;i++)
	{
		test2[i]=puzzle[a][b];
		b--;
	}
	test2[n]='\0';
	if (strcmp(test2,test)==0)
	{
		printf("%10s",test2);
		return 4;
	}
	else return -1;
}




int search4 (int a, int n, int b, char test[]) // searches in leftward
{
	char test2[n];
	int i=0;
	for(i=0;i<n;i++)
	{
		test2[i]=puzzle[a][b];
		a--;
	}
	test2[n]='\0';
	if (strcmp(test2,test)==0)
	{
		printf("%10s",test2);
		return 5;
	}
	else return -1;
}


int search5 (int a, int n, int b, char test[])  //searches antidiagonal(left, down)
{
	char test2[n];
	int i=0;
	for(i=0;i<n;i++)
	{
		test2[i]=puzzle[a][b];
		b++;
		a--;
	}
	test2[n]='\0';
	if (strcmp(test2,test)==0)
	{
		printf("%10s",test2);
		return 6;
	}
	else return -1;
}


int search6 (int a, int n, int b, char test[])  // searches reverse diagonal ( left, up)
{
	char test2[n];
	int i=0;
	for(i=0;i<n;i++)
	{
		test2[i]=puzzle[a][b];
		a--;
		b--;
	}
	test2[n]='\0';
	if (strcmp(test2,test)==0)
	{
		printf("%10s",test2);
		return 7;
	}
	else return -1;
}


int search7 (int a, int n, int b, char test[])  //searches right , up
{
	char test2[n];
	int i=0;
	for(i=0;i<n;i++)
	{
		test2[i]=puzzle[a][b];
		a++;
		b--;
	}
	test2[n]='\0';
	if (strcmp(test2,test)==0)
	{
		printf("%10s",test2);
		return 8;
	}
	else return -1;

}

int check(int a,int b)
{
	if(puzzle[a][b]!=0)
	return 1;
	else 
	return -1;
}

void game()
{
	int i=0, j=0;
	int lt, x=0;
	char choose[5];
	printf("\nFor solution enter 'Show'\n");
	scanf("%s",choose);
//	system("COLOR 0A");
	printf("\n");
	if (strcmp(choose,"show")==0 || strcmp(choose, "SHOW")==0 || strcmp(choose, "Show")==0)
	{
		printf("Word\t\tRow, column \t Direction \t\n");
		printf("---------------------------------------------------\n");
		for(x=0;x<h;x++)
		{
			for (i=0;i<40;i++)
			{
				for (j=0;j<40;j++)
				{
					if(puzzle[i][j]==word[x][0])
					{
						lt=strlen(word[x]);
						if(check(i+lt-1,j)==1 && search(i,lt,j,word[x])==1)
						{	printf("\t%d,%d \t\t down\n",i,j+1);	}

						else if(check(i,j+lt-1)==1 && search1(i,lt,j,word[x])==2)
						{	printf("\t%d,%d \t\t right\n",i,j+1);	}

						else if(check(i+lt-1,j+lt-1)==1 && search2(i,lt,j,word[x])==3)
						{	printf("\t%d,%d \t\t down,right\n",i,j+1);	}

						else if(check(i,j-lt+1)==1 && search3(i,lt,j,word[x])==4)
						{	printf("\t%d,%d \t\t left\n",i,j+1);	}

						else if(check(i-lt+1,j)==1 && search4(i,lt,j,word[x])==5)
						{	printf("\t%d,%d \t\t up\n",i,j+1);	}

						else if(check(i-lt+1,j+lt-1)==1 && search5(i,lt,j,word[x])==6)
						{	printf("\t%d,%d \t\t up,right\n",i,j+1);	}

						else if(check(i-lt+1,j-lt+1)==1 && search6(i,lt,j,word[x])==7)
						{	printf("\t%d,%d \t\t down\n",i,j+1);	}

						else if(check(i+lt-1,j-lt+1)==1 && search7(i,lt,j,word[x])==8)
						{	printf("\t%d,%d \t\t down\n",i,j+1);	}
					}
				}
			}
		}
	}
	else 
	{
		printf("Invalid Input\n");
		game();
	}
}





void coverPage()
{
	printf(" ===============HELLO=======================");
	printf("\n Press any key \n");
	getchar();
//	system("cls");
}



int main()
{
//	system("COLOR 4F");
	coverPage();
	openFile();
	readData();
	printf("Try First \n\n These r the words:\n\n");
	readWords();
	game();
	return 0;
}

# include <stdio.h>
# include <stdlib.h>

int getMem(char***, int);
int getMem_Free(char***, int);

int main()
{
    int i = 0;
    char** p2 = NULL;
    int num = 5;
    
    getMem(&p2, num);
    
    for ( i = 0; i < num; i++ )
        printf("%s\n", p2[i]);
}

//3级指针改变2级指针
int getMem(char*** p, int num)
{
    int i = 0;
    char** tmp = NULL;
    
    if ( NULL == p )
        return -1;
    
    tmp = (char**)malloc(sizeof(char*) * num);
    if ( NULL == tmp )
        return 0;
        
    for ( i = 0; i < num; i++ )
    {
        tmp[i] = (char*)malloc(sizeof(char) * 100);
        sprintf(tmp[i], "%d%d%d", i+1, i+1, i+1);
    }
    
    *p = tmp;
    
    return 0;
}

int getMem_Free(char*** p, int num)
{
	int i;
	char** tmp = NULL;
	if ( NULL == p )
		return 0;
	
	tmp = *p;
	for ( i = 0; i < num; i++ )
	{
		free(tmp[i]);
		
	}
	
	free(tmp);
	*p = NULL;	//把实参赋值成NULL
	
	return 0;
}

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int rows=0;
    
    while(true)
    {
        rows=get_int("Enter row number\n");
        if(rows>0&&rows<9)break;
    }
        
    for(int i=0;i<rows;i++)
    {
        int symbolPosition=rows-i-1;
        
        for(int j=0;j<rows;j++)
        {
            
            if(j<symbolPosition)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }  
   
    return 0;
}

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
    
    int columns=(rows*2)+2;
    int symbolPositionE1=rows-1;
    int symbolPositionS2=rows+2;
        
    for(int i=0;i<rows;i++)
    {
        int symbolPositionS1=rows-i-1;
        int symbolPositionE2=columns-symbolPositionS1-1;
        
        for(int j=0;j<columns;j++)
        {
            
            if(j<symbolPositionS1)
            {
                printf(" ");
            }
            else if(j>symbolPositionE1&&j<symbolPositionS2)
            {
                printf(" ");
            }
            else if(j>symbolPositionE2)
            {
                printf("");                
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
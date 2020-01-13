#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{   
    float cash=0;
    
    while(true)
    {
        cash=get_float("Enter row number\n");
        if(cash >0)break;
    }
    
    // cons values 25, 10, 5, 1
   
    int coinValues[4] ={25,10,5,1};
    
    int coins = round(cash * 100);
    
    int coinsCount=0;
    
    for(int i=0;i<4;i++)
    {
        coinsCount+= coins/coinValues[i];
    
        coins=coins%coinValues[i];
    }
    
    printf("%i coins\n",coinsCount);
    
    return 0;
}
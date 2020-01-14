#include <stdio.h>
#include <cs50.h>

int main(void)
{   
    long cardNum=0;
    
    int numCount=0;
    long ost=0;
    long decDiv=1;
    
    while(true)
    {
        cardNum=get_long("Enter card number\n");
        if(cardNum >0)break;
    }
     
    do
    {
        ost=cardNum/decDiv;
        decDiv*=10;
        numCount++;
    }
    while(ost!=0);
    
    numCount--;
    decDiv/=100;  
    
    long cardType=cardNum/(decDiv/10);
    
    long numArray[numCount];
    int counter=0;
    ost=cardNum;
    do
    {
        numArray[counter]=ost/decDiv;
        ost=ost%decDiv;
        decDiv/=10;
        counter++;
    }
    while(decDiv!=0);
   
    
    counter=0;
    int flag=0;
    long summ1=0;
    long summ2=0;
    
    for(int i=numCount-1; i>=0; i--)
    {
        if(flag==0)
        {
            flag=1;
            summ2+=numArray[i];
        }
        else
        {        
            long tmpValue=numArray[i]*2;
            
            if(tmpValue<10)
            {
                summ1+=tmpValue;
            }
            else
            {
                summ1+=tmpValue/10;
                summ1+=tmpValue%10;
                numCount++;
            }
            counter++;
            flag=0;
        }
    }
    
    long summ=summ1+summ2;
    
    string cardName="";
        
    if(summ%10!=0||numCount<13)
    {
        cardName="INVALID";
        //printf("INVALID\n");
    }
    else
    {
        switch ( cardType )
        {            
            case 34:
            case 37:
                cardName="AMEX";
                //printf("AMEX\n");
                break;
            case 51:
            case 52:
            case 53:
            case 54:
            case 55:
                cardName="MASTERCARD";
                //printf("MASTERCARD\n");
                break;
            default:
                if(cardType/10==4)
                {
                    cardName="VISA";
                    //printf("VISA\n");
                }
                else
                {
                    cardName="INVALID";
                    //printf("INVALID\n");
                }
                break;
        }
    }
    
    printf("%s\n",cardName);
    
    return 0;
}

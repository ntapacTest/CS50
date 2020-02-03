#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

char GetEncChar(char c,int key);
int GetCharNum(int charKey, int min,int max, int key);
int GetShiftValue(char c);

int main(int argc, char *argv[])
{
    char *key=0;
    char keyValue=0;
    if(argc==2)
    {
        key= argv[1];
    }
    else
    {
        printf("Usage: ./vigenere keyword");
        return 1;
    }

    int keyLength=strlen(key);
    int keyNum=0;

    for(int i=0;i<keyLength;i++)
    {
        int c=key[i];

        if((c<65 || c>=91) &&(c<97 || c>=123))
        {
            printf("Usage: ./vigenere keyword");
            return 1;
        }
    }

    char *text=get_string("Enter the text: ");

    int n=strlen(text);


    for( int i=0;i<n;i++)
    {

        if(keyNum<keyLength)
        {
            keyValue=key[keyNum];
        }
        else
        {
            keyNum=0;
            keyValue=key[keyNum];
        }

        keyValue=GetShiftValue(keyValue);

        text[i]=GetEncChar(text[i],keyValue);

        if((text[i]>=65 && text[i]<91) ||(text[i]>=97 && text[i]<123))
        {
            keyNum++;
        }

    }


    printf("ciphertext: %s\n",text);

}

int GetShiftValue(char c)
{
    if(c>=65 && c<91)
    {
        return c-65;
    }
    if(c>=97 && c<123)
    {
        return c- 97;
    }
    return c;
}


char GetEncChar(char c, int key)
{
    if(c>=65 && c<91)
    {
        return GetCharNum(c,65,91,key);
    }
    if(c>=97 && c<123)
    {
        return GetCharNum(c,97,123,key);
    }

    return c;

}

int GetCharNum(int charKey, int min,int max, int key)
{
    key=key-(key/26)*26;

    if((charKey+key)>=max)
    {
        charKey=key-(max-charKey)+min;
    }
    else
    {
        charKey+=key;
    }

    return charKey;
}
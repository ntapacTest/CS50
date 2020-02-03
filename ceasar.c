#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

char GetEncChar(char c,int key);
int GetCharNum(int charKey, int min,int max, int key);

int main(int argc, char *argv[])
{
    int key=0;
    if(argc==2)
    {
        key= atoi(argv[1]);
    }
    else
    {
        return 1;
    }

    char *text=get_string("Enter the text: ");


    int n=strlen(text);

    for( int i=0;i<n;i++)
    {
        text[i]=GetEncChar(text[i],key);
        //printf("%s",text[i])
        //text[i]=(text[i]+key)%26;
    }


    printf("ciphertext: %s\n",text);

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
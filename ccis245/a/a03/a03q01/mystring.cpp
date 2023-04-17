
//Author: Carl Dalebout
//File : mystring.cpp

#include <iostream>
#include "mystring.h"

int str_len(char x[])
{
    int len = 0;
    while (x[len] != '\0')
    {
        ++len;
    }

    return len;
}

void str_cat(char x[], char y[])
{
    int xlen = str_len(x);
    int ylen = str_len(y);;

    for(int i = 0; i <= ylen; ++i)
    {
        x[xlen + i] = y[i];
    }

    return;
}

bool str_cmp(char s[],char t[])
{
   int slen = str_len(s);
    
    for(int i = 0; i<slen; ++i)
    {
        if(s[i] == t[i])
            continue;
        else
            return 1;
    }
    return 0;
}

void str_cpy(char x[], char y[])
{
    int ylen = str_len(y);
    
    for(int i = 0; i < ylen; ++i)
    {
        x[i] = y[i];
    }
    return;
}

int str_chr(char x[], char c)
{
    int xlen = str_len(x);

    for(int i =0; i<xlen; ++i)
    {
        if(x[i]==c)
            return i;
    }
    return -1;
}


int str_str(char x[], char y[])
{
    int  xlen = str_len(x);
    int  ylen = str_len(y);
    bool same = true;

    for(int i = 0; i<xlen; ++i)
    {
        same = true;
        for(int j = 0; j<ylen; ++j)
        {
            if(x[i+j]!=y[j])
            {
                same = false;
            }
            else{}
        }
        if(same)
            return i;
    }
    return -1;
}

void str_lower(char x[], char y[])
{
    int ylen = str_len(y);
    
    for(int i = 0; i<ylen+1; ++i)
    {
        if(i>ylen)
            x[i]= '\0';
        x[i] = tolower(y[i]);
    }
    
    return;
}

bool str_tok(char x[], char y[], char delimiters[])
{
   int  ylen = str_len(y);
   int  dlen = str_len(delimiters);
   bool found = false;
   char temp[1024];
   
   if(ylen==0)
       return 0;
   
    for(int i = 0; i < ylen; ++i)
    {
        for(int j=0; j<dlen; ++j)
        {
            if(y[i+j]== delimiters[j])
            {
                found = 1;
                for(int k = 0; k < i; ++k)
                {
                    x[k] = y[k];
                }
                x[i] = '\0';
                for(int k =0;  k < ylen - i; ++k)
                {
                    y[k] = y[i+k];                    
                }
                y[ylen-i] = '\0';
                return 1;
            }
        }
    }

    if(!found)
    {
        for(int i = 0; i <ylen; ++i)
        {
            x[i] = y[i];
        }
        y[0]='\0';
        return 1;
    }
    return false;
}

void str_capitalize(char x[],int i)
{
    x[i] = toupper(x[i]);
}

void str_lstrip(char x[])
{
    int xlen = str_len(x);
    std::cout << "the length of x is " << xlen << std::endl;
    int spacing = 0;
    
    for(int i =0; i< xlen; ++i)
    {
        if(!isalpha(x[i]))
        {
            spacing++;
        }
        else
            break;
    }
    for(int i = 0; i< xlen-spacing; ++i)
    {
        x[i] = x[i + spacing];
    }
    x[xlen-spacing] = '\0';
}

void str_rstrip(char x[])
{
    int xlen = str_len(x);
    
    int spacing = 0;
    
    for(int i =xlen; i>0; --i)
    {
        if(!isalpha(x[i]))
        {
            spacing++;
        }
        else
            break;
    }
    x[xlen-spacing + 1] = '\0';
}

void str_strip(char x[])
{
    str_rstrip(x);
    str_lstrip(x);
}

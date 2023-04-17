#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "mystring.h"

const int MAX_BUF = 1024;

const int sizehappy = 10;

const int sizesad = 7;

void greetings();

void getname(char []);

void question1(char []);

void getmood(int &,int &);

void reply(int, int);

void Response(char [],int&, int&);

void reply2(char[],int,int);

int main ()
{
    srand (time(NULL));

    char name[MAX_BUF];
    int sad   =-1;
    int happy =-1;

    greetings();
    getname(name);
    question1(name);
    getmood(happy,sad);
    std::cout<< sad << ' ' << happy << '\n';
    reply(happy,sad);
    Response(name,happy,sad);
    reply2(name,happy,sad);
    return 0;
}

void greetings()
{
    
    switch(rand() % 5)
    {
        case 0:
            std::cout << "Hello there I am chat bot what is your name?\n";
            break;
        case 1:
            std::cout << "Hi there i am chat bot what is your name?\n";
            break;
        case 2:
            std::cout << "Greeting I am chat bot, what is your name?\n";
            break;
        case 3:
            std::cout << "You found me I am chat bot what is your name?\n";
            break;
        case 4:
            std::cout << "Hi, whats your name?\n";
            break;
    }
}


void getname(char name[])
{
    char d[2] = {' ','\0'};
    char s[MAX_BUF];
    std::cin.getline(s, MAX_BUF);

    str_rstrip(s);

    int slen = str_len(s);
    while (1)
    {
        if(str_tok(name,s,d))
        {
          
        }
        else
            break;
    }
    //std::cout<< name << '\n';
    return;
}

void question1(char name[])
{
     switch(rand() % 4)
    {
        case 0:
            std::cout<< "Nice to meet you ";
            break;
        case 1:
            std::cout<< "Hi ";
            break;
        case 2:
            std::cout<< "You have a nice name ";
            break;
        case 3:
            std::cout<< "Pleasure to meet you ";
            break;
    }
     std::cout << name << ' ';

     switch (rand() % 4)
     {
         case 0:
             std::cout<< "hows your day going?\n";
             break;
         case 1:
             std::cout<< "how are you?\n";
             break;
         case 2:
             std::cout<< "are you doing good?\n";
             break;
         case 3:
             std::cout<< "are things going good for you?\n";
             break;
     }
}

void getmood(int& h, int& s)
{
    char response[MAX_BUF]; 
    char happy[][MAX_BUF] = {"glade", "happy", "awsome", "great", "fantastic", "very happy", "good", "very good", "yes", "not to bad", "they are"};
    char sad [][MAX_BUF] = {"sad", "very sad", "depressed","no", "not good", "bad", "terrible"};

    
    std::cin.getline(response, MAX_BUF);

    str_lower(response,response);
    
    for(int i = 0; i<sizehappy; i++)
    {
        if(str_str(response,happy[i])>=0)
            h = i;
    }
    for(int i =0; i<sizesad; ++i)
    {
        if(str_str(response,sad[i])>=0)
            s = i;
    }
    if(h == 9) s =-1;
    if(s>=0)
    {}
    else if(h>=0)
        std::cout << "found happy: " << happy[h] << '\n';
    else
        std::cout << "did not find happy or sad\n";
    
}

void reply(int h, int s)
{
    char happy[][MAX_BUF] = {"Thats great, what happened today that made you happy?\n", "I'm glade to hear, what happened today?\n", "I'm happy to hear, what makes your day so positive?\n" };
    char sad  [][MAX_BUF] = {"Im sorry to hear. What is making you sad?\n", "Thats unfortuanet, what put a damper on your day?\n", "That stinks, what happened?\n"};

    if(s==2)
    {
        std::cout<<"Chat bot is not a certified therapist you might want to talk to a professional\n";
    }
    else if(s>=0)
    {
        std::cout<< sad[rand() % 3];
    }
    else if(h>=0)
    {
        std::cout << happy[rand() % 3];
    }
    else
    {
        std::cout<< "Well at least your day isnt bad. Well tell me what made your day just okay.\n";
    }
    
}

void Response(char name[],int &h, int &s)
{
    char happy[][MAX_BUF] = {"got a"};
    char sad  [][MAX_BUF] = {"died","broke","left", "lost", "cant find", "not feeling well", "sick", "tired", "sleepy"};
    char response[MAX_BUF];
    std::cin.getline(response, MAX_BUF);
    str_lower(response,response);

    
    h=-1;
    for(int i = 0; i<1; i++)
    {
        if(str_str(response,happy[i])>=0)
            h = i;
    }
    s= -1;
    for(int i =0; i<8; ++i)
    {
        if(str_str(response,sad[i])>=0)
            s = i;
    }
    
    std::cout<< s << ' ' << h << '\n';

    if (h==0 || (s>2))
    {
        char d[2] = {' ','\0'};
        while (1)
        {
            if(str_tok(name,response,d))
            {
                
            }
            else
                break;
        }   
    }
    else if (s<=2)
    {
        char d[] = {"my"};   // i lost my cat died
        int i = str_str(response, d) + 3;
        int response_len = str_len(response);
        int j = 0;
        while(response[j+i] != '\0')
        {
            name[j] = response[i+j];
            ++j;
        }
        name[j+i-str_len(sad[s])+2] = '\0';
    }
    else if (s>=3)
    {
        name = sad[s];
    }
    std::cout << name << '\n';
    return;
}

void reply2(char name[], int h, int s)
{
     char happy[][MAX_BUF] = {"Thats great, tell me about your ", "Thats such good news, tell me about your ", "I'm happy to hear, tell me about your "};
    char sad  [][MAX_BUF] = {"Im sorry to hear. Tell me about your ", "Thats unfortuanet, tell me about your ", "That stinks, do you want to talk about your "};

    if(s>=0)
    {
        std::cout<< sad[rand() % 3] << name << '\n';
    }
    else if(h>=0)
    {
        std::cout << happy[rand() % 3] << name << '\n';
    }
    else
    {
        std::cout << "I'm sorry I dont know how to repond to that\n";
    }
    
}

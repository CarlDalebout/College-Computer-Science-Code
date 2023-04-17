#include<iostream>
#include<iomanip>
#include<cmath>
void spirle(int n);
void hills(int n);
int lastMan(int n);

int main()
{
    int n =0;
    std::cin >> n;
    hills(n);
    //std::cout<<"the last man standing is #"<<lastMan(n);
    std::cout<<'\n';
   
return 0;    
}

void spirle(int n)
{
    //top half
    for(int i =0; i< (n*2+1); i++)
    {
        if(i%2==0)
        {
            for(int j=0; j<i/2; j++)
            {
                std::cout<<"|  ";
            }

            std::cout<<'+';
            
            for(int j =0; j<((n*6+2)-6*(i/2)); j++)
            {
                std::cout<<'-';
            }

            std::cout<<'+';

            for(int j=0; j<i/2; j++)
            {
                std::cout<<"  |";
            }
            std::cout<<'\n';
        }
        else
        {     
            for(int j=0; j<(i-1)/2; j++)
            {
                std::cout<<"|  ";
            }
            std::cout<<'|';
            for(int j=0; j<((n*6+2)-6*((i-1)/2)); j++)
            {
                std::cout<< ' ';
            }
            std::cout<<'|';
            for(int j =0; j<(i-1)/2; j++)
            {
                std::cout<<"  |";
            }
            std::cout<<'\n';
        }
    }
    //bottom half
    for(int i=0;i<(n*2); i++ )
    {
        if(i%2==0)
        {    
            for(int j=0; j<(n-i/2); j++)
            {
                std::cout<<"|  ";
            }
            std::cout<<'|';
            for(int j=0; j<((i/2*6)+5); j++)
            {
                std::cout<<' ';
            }
            std::cout<<'|';
            for(int j=0; j<(n-i/2-1); j++)
            {
                std::cout<<"  |";
            }
            std::cout<<'\n';
        }
        else
        {
            for(int j=0; j<(n-(i-1)/2); j++)
            {
                std::cout<<"|  ";
            }
            std::cout<<'+';
            for(int j=0; j<(((i-1)/2*6)+5); j++)
            {
                std::cout<<'-';
            }
            std::cout<<'+';
            for(int j=0; j<(n-(i-1)/2-1); j++)
            {
                std::cout<<"  |";
            }
            std::cout<<'\n';
        }
    }
}

void hills(int n)
{
    //each hill
    for(int i =0; i < (n-1); i++)
    {
        //first star placment
        for(int j=0; j<((n - i) * (n - i) -(n - i)); j++)
        {
            std::cout<<' ';
        }
        //Each line
        std::cout<<'*';
        for(int j = 0; j < i; j++ )
        {
            for(int k =0; k<(((n-i)*2)-2); k++) 
            {
                std::cout<<' ';
            }
            for(int k=0; k<((j+2) * 2 -1); k++)
            {
                std::cout<<'*';
            }

        }
        std::cout<<'\n';
    }
    //bottom line
    std::cout<<'*';
    for(int i =1; i<n; i++)
    {
        for(int j =0; j < i*2+1; j++)
        {
            std::cout<<'*';
        }
    }
    std::cout<<'\n';
}

int lastMan(int n)
{
    bool men[1000];
    for(int i =0; i<1000; i++){men[i]=1;}
    int dead=0;
    int steps=1
        ;

    while(dead<n-1)
    {
        for(int i =0; i<n; i++)
        {
            if(steps == 1 && men[i])
            {
                men[i]=false;
                steps=0;
                dead++;
            }
            if(men[i])
            {
                steps++;
            }
        }
    }
    dead=0;
    for(int i=0; i<n; i++){
        if(men[i])
        {
            dead=i;
        }
    }
    return dead;
}


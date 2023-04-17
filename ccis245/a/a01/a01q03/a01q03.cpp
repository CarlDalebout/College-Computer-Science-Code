#include<iostream>
int lastMan(int n);

int main()
{
    int n =0;
    std::cin >> n;
    std::cout<<lastMan(n);
    std::cout<<'\n';
   
return 0;    
}

int lastMan(int n)
{
    bool men[1000];
    for(int i =0; i<1000; i++){men[i]=1;}
    int dead=0;
    int steps=1;

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


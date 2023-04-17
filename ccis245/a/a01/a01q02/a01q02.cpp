#include<iostream>
void hills(int n);

int main()
{
    int n =0;
    std::cin >> n;
    hills(n);
    
   
return 0;    
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

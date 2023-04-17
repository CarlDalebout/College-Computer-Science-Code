#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void forkthem(int n)
{
    if(n>0)
    {
        fork();
        forkthem(n-1);
    }
}

int main(int argc, char ** argv)
{
    forkthem(5);
    std::cout << '1';
}

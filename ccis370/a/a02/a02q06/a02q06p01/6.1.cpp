#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string>

int main()
{
    int p1[2]; 
    pipe(p1); // create the pipe p[0] = read p[1] = write;
    int kids[2];
    kids[0] = fork();

    if(kids[0] == 0)
    {
        // write to the pipe
        int n = getpid();
        write(p1[1], &n, sizeof(n));
        // close the write end of the pipe
        close(p1[1]);

        sleep(1);
        read(p1[0], &n, sizeof(n));
        printf("<Alice>\tReceived from Bob: Hi, I am Bob, my pid is %d.\n\n", n);
        close(p1[0]);
    }
    else
    {
        std::cout << "<Parent>\tAlice is born and assigned a pid of " << kids[0] << '\n';   
        kids[1] = fork();
        if(kids[1] > 0)
        {
            std::cout << "<Parent>\tBob is born and assigned a pid of " << kids[1] << "\n\n";
            wait(NULL);
            std::cout << "<Parent>\tAlice is done\n<Parent>\tBob is done" << std::endl;
            
        }
        else
        {
            // read from the pipe
            int n;
            read(p1[0], &n, sizeof(n));
            //read(pfd1[0],&n ,sizeof(n));
            printf("<BoB>\tReceived from Alice: Hi, I am Alice, my pid is %d.\n\n", n);
            close(p1[0]); // close the read end of the pipe


            n = getpid();
            write(p1[1], &n, sizeof(n));
            // close the write end of the pipe
            close(p1[1]);
        }        
    }
    return 0;
}
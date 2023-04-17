#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string>

int main()
{
    int p1[2]; 
    int p2[2];
    pipe(p1); // create the pipe p[0] = read p[1] = write;
    pipe(p2);
    int kids[2];
    kids[0] = fork();

    if(kids[0] == 0)
    {
        close(p1[0]);
        // write to the pipe
        int n = getpid();
        write(p1[1], &n, sizeof(n));
        // close the write end of the pipe
        close(p1[1]);

        close(p2[1]);
        read(p2[0], &n, sizeof(n));
        printf("<Alice>\tReceived from Bob: Hi, I am Bob, my pid is %d.\n\n", n);
        close(p2[0]);
    }
    else
    {
        std::cout << "<Parent>\tAlice is born and assigned a pid of " << kids[0] << '\n';   
        kids[1] = fork();
        if(kids[1] == 0)
        {
            close(p1[1]);
            // read from the pipe
            int n;
            read(p1[0], &n, sizeof(n));
            //read(pfd1[0],&n ,sizeof(n));
            printf("<BoB>\tReceived from Alice: Hi, I am Alice, my pid is %d.\n\n", n);
            close(p1[0]); // close the read end of the pipe

            close(p2[0]);
            n = getpid();
            write(p2[1], &n, sizeof(n));
            // close the write end of the pipe
            close(p2[1]);

            wait(NULL);
        }
        else
        {
            std::cout << "<Parent>\tBob is born and assigned a pid of " << kids[1] << "\n\n";
            wait(NULL);
            std::cout << "<Parent>\tAlice is done" << std::endl;
            std::cout << "<Parent>\tBob is done" << std::endl;
        }
    }
    
    return 0;
}
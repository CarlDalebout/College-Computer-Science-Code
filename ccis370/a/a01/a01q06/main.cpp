#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <cstring>
#include <vector>

/*
// int create_child()
// {
//     int child_pid = fork();
//     if(child_pid == 0)
//     {
//         printf("Child 1 id= %d\n", getpid());
//         return 0;
//     }
//     else 
//     {
//         int status;
//         waitpid(child_pid, &status, 0);
//         printf("Parent id = &d\n", getpid());
//         return 0;
//     }
// }

// int eve_test()
// {
//      int arr[] = {1, 2, 3};

//     std::string ls = "ls";
//     std::string ls_flags = "-l";

//     char * args[3];
//     args[0] = (char*) ls.c_str();
//     args[1] = (char*) ls_flags.c_str();
//     args[0] = NULL;

//     int pid = fork();

//     if(pid == 0)
//     {
//         execvp(args[0], args);
//         std::cout << "did not run execvp\n";
//     }
//     else
//     {
//         wait(0);
//         std::cout << "My pid is " << getpid() << " Array = " << arr[0] << ' ' << arr[1] << ' ' << arr[2] <<std::endl;
//     }

//     return 0;
// }

// int str_len(char string[])
// {
//     int ret;
//     while(string[ret] != '\0')
//     {
//         ret++;
//     }
//     return ret;
// }
*/

int get_args(std::string input)
{
    int ret = 1;
    int i = 0;
    while (input[i] != '\0')
    {
        if(input[i] == ' ')
        {
            ret++;
        }
        i++;
    }
    return ret;
}

int parseCmdLine(std::string string, char* &p, int start)
{
    int i = 0;
    while(string[start + i] != ' ' && string[start + i] != '\0')
    {
        //std::cout << start + i << ' ' << string[start + i] << '\n';
        i++;
    }
    //std::cout << '\n';

    //to delete old inputs
    p = new char[i];

    //std::cout << "Creating new char array for p\n"
    for(int j = 0; j < i; ++j)
    {
        //std::cout << "Putting "<< string[start+j] << " into p[" << j << "]\n";
        p[j] = string[start+j];
    }
    if(string[start + i] != '\0')
        return start + i + 1;
    return -1;
}

bool readAndParseCmdLine(char* &command, char* arguments[], int &args)
{
    //std::cout << "entering function.\n";
    
    //Creating temporty char array to hold user input
    std::string userInput;
    
    getline(std::cin, userInput);
    //std::cout << "pulled {" << userInput << "} from user\n";

    for(int i = 0; i < 6; ++i)
    {
        arguments[i] = NULL;
    }

    args = get_args(userInput);
    //std::cout << "there are " << args << " arguments\n";  

    //Exit Check
    if(userInput[0] == 'q')
    {
        //std::cout << "return false\n";
        return false;
    }
    
    //get first argu from the user input along with where the space is located
    int i = parseCmdLine(userInput, command, 0);
    //std::cout << "Pulled command is [" << command << "] " << i <<'\n';
    //arguments[0] = command;

    //fills command with the user input command exp. "ls" out of ls -l
    i = 0;
    for(int j = 0; j < args; ++j)
    {
        i = parseCmdLine(userInput, arguments[j], i);
        //std::cout << i << '\n';
    }     
    
    
    //std::cout << "Child has finished parsing arguments" << '\n';
    //std::cout << "grabed arguments are \n";
    //std::cout << '\n';
    return true;    
}

int main()
{
    char* command = NULL;
    char* argument_list[] = {NULL, NULL, NULL, NULL, NULL, NULL};
    int numb = -1;

    while(readAndParseCmdLine(command, argument_list, numb))
    {
        //std::cout << "creating child\n";
        if (fork() == 0) 
        {
            //std::cout << "Child will execute pulled command [" << command << "]\n";
            for(int i = 0; i < numb; ++i)
            {
                //std::cout << "args " << i << ' ' << argument_list[i] << '\n'; 
            }
            //Newly spawned child Process. This will be taken over by "ls -l"
            int status_code = execvp(command, argument_list);
            
            //std::cout <<TERMINATED ABNORMALLY!!!\n";

            if (status_code == -1) 
            {
                printf("Terminated Incorrectly\n");
                return 1;
            }
        }
        else {
            // Old Parent process. The C program will come here
            //printf("The parent function will print This line\n");
        }
    }

    delete[] command;
    for(int i = 0; i < numb; ++i)
        delete[] argument_list[i];
    delete[] argument_list;
    return 0;
}
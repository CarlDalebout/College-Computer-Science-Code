#include <iostream>
#include <string>
#include <vector>
#include "Tok.h"
#include "Ram.h"
/*
"RAM (int)" crate simulation with size of given int
"Start (process name) (int)" creates a process with given name and allocate a size of given int within the RAM. if there is not enough space available DEFRAG
"DEFRAG" pushes all the process up if there is enough space for a new process if not possible state that the size is to big and do not defrag.
"(process name) LOC (int)" spits out the physical address which is the bass fo the process pluse the given int
"STOP (process name)" makes the process as done and starts the garbage collection aka making the space as free
"DUMP" spits out the base/bound of all active processes
"STOP" return 0 aka end the code.
*/



int main()
{
    std::string input;
    RAM ram;
    std::string dir;
    
    while(true)
    {
        // std::cout << "getting next input" << std::endl;
        std::getline(std::cin, input);
        Tok tokens(input);

        // std::cout << tokens.size() << '\n';
        // dir = "";
        // std::cout << '<';
        // for(int i = 0; i < tokens.size(); ++i)
        // {
        //     std::cout << dir << tokens[i]; dir = ", ";
        // }
        // std::cout << ">\n";

        if(tokens.size() == 2 && tokens[0] == "RAM")
        {
            std::cout << "creating ram with size " << tokens.Int(tokens[1]) << '\n';
            ram.create(tokens.Int(tokens[1]));
            tokens.clear();
        }
        else if(tokens.size() == 3 && tokens[0] == "START")
        {
            if(tokens.Int(tokens[2]) < 1)
            {
                std::cout << "can not create process NEGATIVE ALLOCATION ERROR\n";
            }
            else
            {
                std::cout << "creating process " << tokens[1] << " with size " << tokens[2] << '\n';
                ram.process(tokens[1], tokens.Int(tokens[2]));
            }
            tokens.clear();
        }
        else if(tokens.size() == 3 && tokens[1] == "LOC")
        {
            std::cout << ram.loc(tokens[0], tokens.Int(tokens[2])) << '\n';
            tokens.clear();
        }
        else if(tokens.size() == 2 && tokens[0] == "STOP")
        {
            ram.stop(tokens[1]);
            tokens.clear();
        }
        else if(tokens.size() == 1 && tokens[0] == "DUMP")
        {
            ram.dump();
            tokens.clear();
        }
        else if(tokens.size() == 1 && tokens[0] == "DEFRAG")
        {
            ram.defrag();
            tokens.clear();
        }
        else if(tokens.size() == 1 && tokens[0] == "STOP")
        {
            break;
        }
        else
        {
            std::cout << "unknown command please type the correct one\n";
            tokens.clear();
        }
    }

    return 0;
}

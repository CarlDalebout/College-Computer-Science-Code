#include <iostream>
#include <string>
#include "Tok.h"

void Tok::tok(std::string input)
{   
    std::string token;
    for(int i = 0; i < input.size(); ++i)
    {
        if(input[i] == delimiters_[0])
        {
            tokens_.push_back(token);
            token.clear();
        }
        else
        {
            token.push_back(input[i]);
        }   
    }
    tokens_.push_back(token);
}

int Tok::Int (std::string input) const
{  
    int number = 0;
    for(int i = 0; i < input.size(); ++i)
    {
        number = number * 10;
        // std:: cout << number << '\n';
        number += (int)input[i] - 48;
    } 
    return number;
}
#ifndef TOK_H
#define TOK_H

#include <iostream>
#include <string>
#include <vector>

class Tok
{
public:
    Tok()
    {}
    Tok(std::string input)
    {
        tok(input);
    }

    int size() { return tokens_.size();}

    void clear() { tokens_.clear(); }

    int Int (std::string input) const;

    std::string operator [] (int i) { return tokens_[i];}

    void tok(std::string input);



// private:
    std::vector<std::string> tokens_;
    std::vector<char> delimiters_ {' '};
}; 

// std::ostream operator << (std::ostream & cout, std::string token)
// {

//     return cout;
// }

#endif
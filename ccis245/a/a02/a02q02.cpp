#include <iostream>
#include "Fraction.h"

int main(int argc, char * argv[])
{
    std::cout << argc << std::endl;
    int an = 0, ad = 0; //Fraction a
    int bn = 0, bd = 0; //Fraction b
    int cn = 0, cd = 0; //Fraction c
    int dn = 0, dd = 0; //Fraction d
    int en = 0, ed = 0; //Fraction e
    int fn = 0, fd = 0; //Fraction f
    int tn = 0, td = 0; //Temp Fraciton
    std::cout<<"test\n";
    
    std::cout << "x^3 + (" << an << '/' << ad << ")x^2 + (" << bn << '/' << bd
              << ")x + (" << cn << '/' << cd << ") = ";
    std::cout << std::endl;
    return 0;
    for(int xn = -50; xn<51; ++xn)
    {
        for(int xd = 1; xd<51; ++xd)
        {
            for(int yn = -50; yn<51; ++yn)
            {
                for(int yd = 1; yd<51; ++yd)
                {
                    for(int zn = -50; zn<51; ++zn)
                    {
                        for(int zd = 1; zd<51; ++ zd)
                        {
                            //creates dn/dd
                            Fraction_add(xn,xd,yn,yd,dn,dd);
                            Fraction_addeq(dn,dd,zn,zd);
                            dn *= -1;
                            dd *= -1;

                            //creates en/ed
                            Fraction_mult(xn,xd,yn,yd,en,ed);
                            Fraction_mult(xn,xd,zn,zd,tn,td);
                            Fraction_addeq(en,ed,tn,td);
                            Fraction_mult(yn,yd,zn,zd,tn,td);
                            Fraction_addeq(en,ed,tn,td);

                            //creates fn/fd
                            Fraction_mult(xn,xn,yn,yd,fn,fd);
                            Fraction_multeq(fn,fd,zn,zd);
                            fn *= -1;
                            fd *= -1;
                             
                            if (dn == an && dd == ad)
                                if(en == bn && ed == bd)
                                    if(fn == cn && fd == cd)
                                        std::cout << "(x - ("
                                                  << dn << '/' << dd << "))(x - ("
                                                  << en << '/' << ed << "))(x - ("
                                                  << fn << '/' << fd << "))";
                        }
                    }
                }
            }
        }
    }
    
    
    return 0;
}

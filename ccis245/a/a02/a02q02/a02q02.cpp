#include<iostream>
#include "Fraction.h"

int main()
{
    int an = 0, ad = 0; //Fraction a
    int bn = 0, bd = 0; //Fraction b
    int cn = 0, cd = 0; //Fraction c
    int dn = 0, dd = 0; //Fraction d
    int en = 0, ed = 0; //Fraction e
    int fn = 0, fd = 0; //Fraction f
    int tn = 0, td = 0; //Temp Fraciton
    std::cin >> an >> ad >> bn >> bd >> cn >> cd;

    std::cout << "x^3 + (" << an << '/' << ad << ")x^2 + (" << bn << '/' << bd
              << ")x + (" << cn << '/' << cd << ") = ";

    
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
                            Fraction_add(dn,dd,zn,zd,dn,dd);
                            dn *= -1;
                            

                            //creates en/ed
                            Fraction_mult(xn,xd,yn,yd,en,ed);
                            Fraction_mult(xn,xd,zn,zd,tn,td);
                            Fraction_addeq(en,ed,tn,td);
                            Fraction_mult(yn,yd,zn,zd,tn,td);
                            Fraction_addeq(en,ed,tn,td);

                            //creates fn/fd
                            Fraction_mult(xn,xd,yn,yd,fn,fd);
                            Fraction_mult(fn,fd,zn,zd,fn,fd);
                            fn *=-1;
                            
                            // Fraction_print(dn,dd);
                            // std::cout<<std::endl;

                            // Fraction_print(en,ed);
                            // std::cout<<std::endl;

                            // std::cout<< " Fraction c is " << fn << '/' << fd << '\n';
                            // Fraction_print(fn,fd);
                            // std::cout<<std::endl;

                            // std::cout << Fraction_eq(an,ad,dn,dd) << ' '
                            //           << Fraction_eq(bn,bd,en,ed) << ' '
                            //           << Fraction_eq(cn,cd,fn,fd) << '\n';

                            // std::cin >> tn;
                            if (Fraction_eq(an,ad,dn,dd) && Fraction_eq(bn,bd,en,ed) && Fraction_eq(cn,cd,fn,fd))
                            {
                                std::cout << "(x - (";
                                Fraction_print(xn,xd);
                                std::cout << "))(x - (";
                                Fraction_print(yn,yd);
                                std::cout << "))(x - (";
                                Fraction_print(zn,zd);
                                std::cout << "))";
                                std::cout<<std::endl;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    
    std::cout << "not found\n";
    return 0;
}

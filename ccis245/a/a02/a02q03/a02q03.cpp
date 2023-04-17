#include <iostream>
#include "Fraction.h"

int main()
{
    
    int *n = NULL;
    n = getn();
    int *d = NULL;
    d = getd();

    int dn, dd, en, ed, fn, fd;
    int an, ad, bn, bd, cn, cd;
    int tn, td;

    std::cin >> an >> ad >> bn >> bd >> cn >> cd;

    std::cout << "x^3 + (" << an << '/' << ad
              << ")x^2 + ("<< bn << '/' << bd
              << ")x + ("  << cn << '/' << cd << ") = ";

    for(int i = 0; i<9032; ++i)
    {
        std::cin >> tn;
        for(int j =i; j<9032; ++j)
        {
            
            for(int k=j; k<9032; ++k)
            {
               //creates dn/dd
                Fraction_add(n[i],d[i],n[j],d[j],dn,dd);
                Fraction_add(dn,dd,n[k],n[k],dn,dd);
                dn *= -1;
                
                
                //creates en/ed
                Fraction_mult(n[i],d[i], n[j],d[j], en,ed);
                Fraction_mult(n[i],d[i], n[k],d[k], tn,td);
                Fraction_addeq(en,ed, tn,td);
                Fraction_mult(n[j],d[j], n[k],d[k], tn,td);
                Fraction_addeq(en,ed, tn,td);
                
                //creates fn/fd
                Fraction_mult(n[i],d[i], n[j],d[j],fn,fd);
                Fraction_mult(fn,fd,n[k],d[k],fn,fd);
                fn *=-1;

                Fraction_print(n[i],d[i]);
                std::cout<<std::endl;

                Fraction_print(n[j],d[j]);
                std::cout<<std::endl;

                Fraction_print(n[k],d[k]);
                std::cout<<std::endl;

                std::cout << Fraction_eq(an,ad,dn,dd) << ' '
                          << Fraction_eq(bn,bd,en,ed) << ' '
                          << Fraction_eq(cn,cd,fn,fd) << '\n';

                
                
                if (Fraction_eq(an,ad,dn,dd) && Fraction_eq(bn,bd,en,ed) && Fraction_eq(cn,cd,fn,fd))
                {
                    std::cout << "(x - (";
                    Fraction_print(n[i],d[i]);
                    std::cout << "))(x - (";
                    Fraction_print(n[j],d[j]);
                    std::cout << "))(x - (";
                    Fraction_print(n[k],d[k]);
                    std::cout << "))";
                    std::cout<<std::endl;
                    return 0;
                }
            }
        }
    }
    std::cout << "not found\n"; 
    return 0;
}



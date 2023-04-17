#ifndef MATH_H
#define MATH_H

class Fib
{
public:
    static int size() {return size_;}

    static void resize(const int);
    static int lookup(const int);
    static int &  set(const int);

    int  operator()(const int);

    static Fib fib5;
    
//private:
    static int *t_;
    static int size_;
    static int numb_objects_;

    Fib()
    {
        if(Fib::numb_objects_ == 0 && Fib::t_ == NULL)
        {
            Fib::t_ = new int [2];
            Fib::size_ = 2;
            t_[0] = t_[1] = 1;
        }
        Fib::numb_objects_++;
    }
    Fib(int n)
    {
        if(Fib::numb_objects_ == 0 && Fib::t_ == NULL)
        {
            Fib::t_ = new int [n];
            Fib::size_ = n+1;
            t_[0] = t_[1] = 1;
            for(int i = 2; i < Fib::size_; ++i)
            {
                t_[i] = -1;
            }
        }
        else
        {
            resize(n);
        }
        Fib::numb_objects_++;
        
    }
   ~Fib()
    {
        if(Fib::numb_objects_ > 0)
            Fib::numb_objects_--;
        else
            delete[] t_;
    }
};

std::ostream & operator<<(std::ostream &, const Fib &);

#endif

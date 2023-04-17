#ifndef FIB4_H
#define FIB4_H

class Fib4
{
public:
    Fib4()
    {
        if(Fib4::numb_objects_ == 0 && Fib4::t_ == NULL)
        {
            Fib4::t_ = new int [2];
            Fib4::size_ = 2;
            t_[0] = t_[1] = 1;
        }
        Fib4::numb_objects_++;
    }
    Fib4(int n)
    {
        if(Fib4::numb_objects_ == 0 && Fib4::t_ == NULL)
        {
            Fib4::t_ = new int [n];
            Fib4::size_ = n+1;
            t_[0] = t_[1] = 1;
            for(int i = 2; i < Fib4::size_; ++i)
            {
                t_[i] = -1;
            }
        }
        else
        {
            resize(n);
        }
        Fib4::numb_objects_++;
        
    }
   ~Fib4()
    {
        if(Fib4::numb_objects_ > 0)
            Fib4::numb_objects_--;
        else
            delete[] t_;
    }
    static int size() {return size_;}

    static void resize(const int);
    static int lookup(const int);
    static int &  set(const int);

    int  operator()(const int);
    
//private:
    static int *t_;
    static int size_;
    static int numb_objects_;
};

std::ostream & operator<<(std::ostream &, const Fib4 &);

#endif

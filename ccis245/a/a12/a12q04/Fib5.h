#ifndef FIB5_H
#define FIB5_H

class Fib5
{
public:
    static int size() {return size_;}

    static void resize(const int);
    static int lookup(const int);
    static int &  set(const int);

    int  operator()(const int);
    
//private:
    static int *t_;
    static int size_;
    static int numb_objects_;

    Fib5()
    {
        if(Fib5::numb_objects_ == 0 && Fib5::t_ == NULL)
        {
            Fib5::t_ = new int [2];
            Fib5::size_ = 2;
            t_[0] = t_[1] = 1;
        }
        Fib5::numb_objects_++;
    }
    Fib5(int n)
    {
        if(Fib5::numb_objects_ == 0 && Fib5::t_ == NULL)
        {
            Fib5::t_ = new int [n];
            Fib5::size_ = n+1;
            t_[0] = t_[1] = 1;
            for(int i = 2; i < Fib5::size_; ++i)
            {
                t_[i] = -1;
            }
        }
        else
        {
            resize(n);
        }
        Fib5::numb_objects_++;
        
    }
   ~Fib5()
    {
        if(Fib5::numb_objects_ > 0)
            Fib5::numb_objects_--;
        else
            delete[] t_;
    }
};

std::ostream & operator<<(std::ostream &, const Fib5 &);

#endif

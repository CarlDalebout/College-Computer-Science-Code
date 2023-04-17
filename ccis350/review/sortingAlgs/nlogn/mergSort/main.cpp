#include <iostream>

void merge(int x[], int* s0, int* s1, int* end, int t[])
{
    for(int i = 0; i < s1-s0; ++i)
    {
        t[i] = *(s0+i);
    }

}

class thread_obj
{
	public:
	void operator()(int x[], int *start, int *end, int t[])
    {

        if(start+1 >= end)
        {}
        else
        {
            int mid = (end - start)/2;
            std::thread t1(thread_obj(), x, start, mid, t);
            std::thread t2(thread_obj(), x, mid  , end, t);

            t1.join();
            t2.join();
            merge(x, start, mid, end, t);
        }
    }
};

void mergSort(itn x[], int* start, int* end)
{
    int * t = new[(end-start)/2];
    std::thread t1(thread_obj(), x, start, end, t);
    t1.join();
    delete[] t;
}

int main()
{


}
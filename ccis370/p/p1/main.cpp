#include <iostream>
#include <iomanip>
#include <thread>
#include <mutex>
#include "stdlib.h"
#include "time.h" 
#include "unistd.h"

std::mutex mtx;

class car
{
public:
    car(int atime = 0, int ptime = 0)
    :space_(0), atime_(atime), wtime_(0), ptime_(ptime)
    {}
    int space_, atime_, wtime_, ptime_;
};

class parking_sim
{
public:
    parking_sim(int c=2, int s=1, int a=5, int p=20)
    :pcars_(new car [c]), cars_(c)
        ,pspaces_(new bool [s]), spaces_(s), spaces_available_(s)
        , arrival_(a), parking_(p)
        , totaltime_(0)
    {
        for(int i = 0; i < c; ++i)
        {
            pcars_[i].atime_ = rand() % arrival_+1;
            pcars_[i].ptime_ = rand() % parking_+1;
        }
    }

    void print_spaces()
    {
        for(int i = 0; i < spaces_; ++i)
        {
            std::cout << "S" << i+1 << ":\n";
            for(int j = 0; j < cars_; ++j)
            {
                if(pcars_[j].space_ == i)
                {
                    std::cout << "\t\tc" << j+1 << "\t" << pcars_[j].ptime_ << '\n';
                }
            }
        }
    }   

    void print_cars()
    {
        for(int i = 0; i < cars_; ++i)
        {
            std::cout << 'c' << std::setw(3) << std::setfill('0') << i+1 
                      << ":\t\ts" << std::setw(3) << std::setfill('0') << pcars_[i].space_+1
                      << "\t" << pcars_[i].atime_
                      << "\t\t" << pcars_[i].wtime_
                      << "\t\t" << pcars_[i].ptime_ << '\n';
        }
    }

    int findspot()
    {
        for(int i = 0; i < spaces_; ++i)
        {
            if(pspaces_[i] == 0)
            {
                return i;
            }
        }

        return -1;
    }

// private:
    car * pcars_;
    int   cars_;
    bool* pspaces_;
    int   spaces_;
    int   spaces_available_;
    int   arrival_;
    int   parking_;
    int   totaltime_;
};

void park(int i, parking_sim * lot)
{   
    sleep(lot->pcars_[i].atime_);
    mtx.lock();
    std::cout << ">>>> C" << std::setw(2) << std::setfill('0') << i+1 << " ARRIVED after " << lot->pcars_[i].atime_ << " seconds..."
              << " Available Spaces: ";
    lot->spaces_available_ == 0 ? std::cout << "FULL\n\n" : std::cout << lot->spaces_available_ << "\n\n";
    mtx.unlock();

    while(lot->spaces_available_ == 0)
    {
        lot->pcars_[i].wtime_ += 1;
        sleep(1);
    }

    mtx.lock();
    int spot = lot->findspot();
    lot->pcars_[i].space_ = spot;
        std::cout << ">>>> C" << std::setw(2) << std::setfill('0') << i+1 
                  << " Parked in s" << (lot->pcars_[i].space_+1)  
                  << " after waiting " << lot->pcars_[i].wtime_ << " seconds\n\n"; 
    lot->pspaces_[spot] = true;
    lot->spaces_available_ -= 1;
    mtx.unlock();

    sleep(lot->pcars_[i].ptime_);

    mtx.lock();
    std::cout << "<<<< C" << std::setw(2) << std::setfill('0') << i+1
              << " left s" << spot 
              << " after parking " << lot->pcars_[i].ptime_ << " seconds\n\n";
    lot->pspaces_[spot] = false;
    lot->spaces_available_ += 1;

    int temp = lot->pcars_[i].atime_ + lot->pcars_[i].wtime_ + lot->pcars_[i].ptime_;
    if(temp > lot->totaltime_)
        lot->totaltime_ = temp;

    mtx.unlock();          


}

int main()
{
    srand(time(NULL));

    //to change values edit the object under (Cars, Spaces, Arrival Time, Parking Time)
    parking_sim lot(15, 14, 5, 15);

    std::cout << "% Parking\nUsing values:\t" << lot.cars_ << " Cars,"
              << "\t\tRand Arrival Time " << lot.arrival_ << " Seconds" 
              << "\n\t\t" << lot.spaces_ << " Space,"
              << "\tRand Parking Time " << lot.parking_ << " Seconds\n"
              << "... PARKING LOT OPEN ...\n"
              << "... Expecting (" << lot.cars_ << ") Cars with Random Arrival Time (" << lot.arrival_ << " seconds)\n"
              << "... Parking Spaces (" << lot.spaces_ << ") with Random parking Time (" << lot.parking_ << " seconds)\n\n";  

    std::thread * test = new std::thread [lot.cars_];

    clock_t time = clock();
    for(int i = 0; i < lot.cars_; ++i)
    {
        test[i] = std::thread(park, i, &lot);  
    }
    
    for(int i = 0; i < lot.cars_; ++i)
    {
        test[i].join();
    }
    time = clock() - time;
    std::cout << "\n... PARKING LOT CLOSED ... Number of Paarked Cars " << lot.cars_ 
              << "\n\n=================== FINAL STATE ===========================\n"
              << "Total Time from Open to Close: " << lot.totaltime_ << " seconds\n\n"
              << "Parking Spaces:\n"
              << "---------------\n"
              << "\t\tCar\tParkingTime\n";
    lot.print_spaces();

    std::cout << "\n\nCars:\n"
              << "-----\n"
              << "\t\tSpace\tArrivalTime\tWaitingTime\tParkignTime\n";   
    lot.print_cars();       

     return 0;
}
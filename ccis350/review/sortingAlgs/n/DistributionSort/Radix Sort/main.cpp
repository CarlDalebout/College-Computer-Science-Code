#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <string>

void radixSort(int* s, int *e)
{

}

int main()
{

    return 0;
}

//LSD (least Segnificant Data)
/*
    53    80    01
    27    81    02
    02    01    24
    81    02    27
    52 -> 52 -> 52   
    80    53    53
    24    24    55
    01    55    80
    55    27    81
*/

/*
    58 -> 0 ->          -> 21 -> 0 
    21 -> 1 -> 21       -> 92 -> 1 
    53 -> 2 -> 92       -> 53 -> 2 21 23 29 
    29 -> 3 -> 53 23 93 -> 23 -> 3 38
    38 -> 4 ->          -> 93 -> 4 
    23 -> 5 ->          -> 58 -> 5 53 58
    92 -> 6 ->          -> 38 -> 6 
    93 -> 7 ->          -> 29 -> 7 
       -> 8 -> 58 38    ->    -> 8 
       -> 9 -> 29       ->    -> 9 92 93

    Data Structure: Double-linked list
    Tinsert(1) = O(1)
    Tdelete(1) = O(1)
*/

//MSD (Most Segnificant Data)
/*
    bad -> ace -> ace -> ap
    ace -> ap  -> ap  -> ace
    ap  -> bad -> bad -> bad
    bed -> bed -> bed -> bed
*/
/*************************************************************************
	> File Name: task26.cpp
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Tue 16 Sep 2014 07:59:03 AM PDT
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

void bubble (vector<int> vec) ;
int main (int argc, char *argv[])
{
    vector<int> arr(10) ;
    srand (time (NULL)) ;

    for (int cnt = 0 ; cnt < 10 ; cnt ++)
        arr[cnt] = rand() %100 + 1 ;


    cout << "Before bubble sort: " << endl ;
    for (vector<int>::size_type ix = 0 ;
         ix != arr.size() ;
         ix ++)
        cout << arr[ix] << " " ;
    cout << endl ;


    cout << "After bubble sort: " << endl ;
    bubble (arr) ;
    for (vector<int>::size_type ix = 0 ;
         ix != arr.size() ;
         ix ++)
        cout << arr[ix] << " " ;
    cout << endl ;

    return 0 ;
}

void bubble (vector<int> vec) 
{
    vector<int>::size_type up = 0 ;
    vector<int>::size_type down = vec.size() - 1 ;

    while (up < down)
    {
        for (vector<int>::size_type ix = up;
                ix + 1 <= down;
                ix ++)
        {
            if (vec[ix] > vec[ix + 1])
            {
                int tmp = vec[ix] ;
                vec[ix] = vec[ix + 1] ;
                vec[ix + 1] = tmp ;
            }
        }
        down -- ;

        if (up >= down)
            break ;
        for (vector<int>::size_type idx = down;
             idx - 1 >= up;
             idx --)
        {
            if (vec[idx] < vec[idx - 1])
            {
                int tmp = vec[idx] ;
                vec[idx] = vec[idx - 1] ;
                vec[idx - 1] = tmp ;
            }
        }
        up ++ ;
    }
}

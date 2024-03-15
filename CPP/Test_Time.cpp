#include <iostream>
#include <ctime>

using namespace std;

void get_nowtime_utctime()
{
    time_t now = time(0);

    // now convert to char
    char *dt = ctime(&now); 
    cout << "now time is : " << dt << endl;

    // now time convert to tm struct
    tm *gmtm = gmtime(&now);
    dt = asctime(gmtm);

    cout << "UTC now time is : " << dt << endl; 

}

void use_tmstruct_time()
{
    time_t now = time(0);
    cout << "1970 - now have : " << now << " seconds" << endl;

    tm *ltm = localtime(&now);

    // print tm struct all construct 
    cout << "year : " << 1900 + ltm->tm_year << endl;
    cout << "month : " << 1 + ltm->tm_mon << endl;
    cout << "day : " << ltm->tm_mday << endl;
    cout << "hour : " << ltm->tm_hour << endl;
    cout << "minute : " << ltm->tm_min << endl;
    cout << "second : " << ltm->tm_sec << endl;       

}

int main()
{
    get_nowtime_utctime();
    use_tmstruct_time();
    cin.get();
    return 0;
}
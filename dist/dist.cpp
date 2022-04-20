#include <iostream>
#include <math.h>

using namespace std;
double GetDistance(double lng1, double lat1, double lng2, double lat2)
{
    double dx = lng1 - lng2;
    double dy = lat1 - lat2;
    double sx = (double)cos(lat1*0.01745329252f);

    return(double)sqrt(dx*dx*sx*sx+dy*dy)*111195.0f;
}

int main(){
   cout<< GetDistance(151.264359,-33.796730,151.273712,-33.795101) << endl;
}
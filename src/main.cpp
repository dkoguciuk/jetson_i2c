#include <iostream>
#include "kamod_mems2.h"

int main (int argc, char **argv)
{
    KamodMEMS2 imu("/dev/i2c-1");
    imu.init();

    while (1)
    {
        std::cout << (int)imu.getx() << std::endl;
        usleep(10000);
    }

    return 0;
}

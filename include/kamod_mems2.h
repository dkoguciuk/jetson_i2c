/*
 * Author:    Daniel Koguciuk <daniel.koguciuk@gmail.com>
 *
 *
 * Modificated on 17 december 2015, 05:30
 */

#ifndef KAMODMEMS2_H
#define	KAMODMEMS2_H

#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include <linux/i2c-dev.h>

#define LIS35_I2CADDR   0x1D        //(3A<<1)

#define LIS35_REG_CR1               0x20
#define LIS35_REG_CR1_XEN           0x1
#define LIS35_REG_CR1_YEN           0x2
#define LIS35_REG_CR1_ZEN           0x4
#define LIS35_REG_CR1_DR_400HZ      0x80
#define LIS35_REG_CR1_ACTIVE        0x40
#define LIS35_REG_CR1_FULL_SCALE    0x20

#define LIS35_REG_OUTX 	0x29
#define LIS35_REG_OUTY	0x2B
#define LIS35_REG_OUTZ	0x2D

class KamodMEMS2
{
public:
    KamodMEMS2(const std::string &filename);
    ~KamodMEMS2();
    void init(bool z = true, bool y = true, bool x = true);
    unsigned char  getx();
    unsigned char  gety();
    unsigned char  getz();
private:
    int i2c_descriptor;

};

#endif //KAMODMEMS2_H

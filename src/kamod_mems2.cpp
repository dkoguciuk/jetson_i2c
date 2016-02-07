#include "kamod_mems2.h"

KamodMEMS2::KamodMEMS2(const std::string &filename)
{
    if ((i2c_descriptor = open(filename.c_str(), O_RDWR)) < 0)
        throw std::runtime_error("Failed to open the i2c bus!");

    if (ioctl(i2c_descriptor, I2C_SLAVE, LIS35_I2CADDR) < 0)
        throw std::runtime_error("Failed to acquire bus access and/or talk to slave!");
}

KamodMEMS2::~KamodMEMS2()
{
    if (i2c_descriptor >= 0)
        close(i2c_descriptor);
}

void KamodMEMS2::init(bool z, bool y, bool x)
{
    unsigned char buff[2] = {LIS35_REG_CR1, LIS35_REG_CR1_ACTIVE | ((z) ? LIS35_REG_CR1_ZEN : 0x00) | ((y) ? LIS35_REG_CR1_YEN : 0x00) | ((x) ? LIS35_REG_CR1_XEN : 0x00) };
    if (write(i2c_descriptor, buff, 2) != 2)
        throw std::runtime_error("Failed to write to the i2c bus!");
}

unsigned char  KamodMEMS2::getx()
{
    unsigned char buff_write[1] = {LIS35_REG_OUTX};
    if (write(i2c_descriptor, buff_write, 1) != 1)
        throw std::runtime_error("Failed to write to the i2c bus!");

    unsigned char buff_read[1];
    if (read(i2c_descriptor, buff_read, 1) != 1)
        throw std::runtime_error("Failed to read from the i2c bus!");

    return buff_read[0];
}

unsigned char  KamodMEMS2::gety()
{
    unsigned char buff_write[1] = {LIS35_REG_OUTY};
    if (write(i2c_descriptor, buff_write, 1) != 1)
        throw std::runtime_error("Failed to write to the i2c bus!");

    unsigned char buff_read[1];
    if (read(i2c_descriptor, buff_read, 1) != 1)
        throw std::runtime_error("Failed to read from the i2c bus!");

    return buff_read[0];
}

unsigned char  KamodMEMS2::getz()
{
    unsigned char buff_write[1] = {LIS35_REG_OUTZ};
    if (write(i2c_descriptor, buff_write, 1) != 1)
        throw std::runtime_error("Failed to write to the i2c bus!");

    unsigned char buff_read[1];
    if (read(i2c_descriptor, buff_read, 1) != 1)
        throw std::runtime_error("Failed to read from the i2c bus!");

    return buff_read[0];
}

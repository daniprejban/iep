#ifndef SPI_H
#define SPI_H

#include "serial.h"
#include "stdint.h"
#include <bcm2835.h>

class Spi : Serial
{
    public:
        Spi(uint8_t bit_order, uint8_t data_mode, uint16_t clock_divider, uint8_t chip_select, uint8_t polarity) ;
        unsigned char transfer (unsigned char data);

};

#endif // SPI_H

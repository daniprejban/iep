#include "spi.h"


 Spi :: Spi(uint8_t bit_order, uint8_t data_mode, uint16_t clock_divider, uint8_t chip_select, uint8_t polarity )
{
     bcm2835_spi_setBitOrder(bit_order);      // The default
     bcm2835_spi_setDataMode(data_mode);                   // The default
     bcm2835_spi_setClockDivider(clock_divider); // The default
     bcm2835_spi_chipSelect(chip_select);                      // The default
     bcm2835_spi_setChipSelectPolarity(polarity, LOW);      // the default

}

 unsigned char Spi:: transfer (unsigned char data)
 {

    return bcm2835_spi_transfer(data);
 }

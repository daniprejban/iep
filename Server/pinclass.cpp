#include "pinclass.h"

Pinclass::Pinclass(uint8_t pin_nr, uint8_t pin_state, uint8_t pin_dir)
{
    this->pin_nr = pin_nr;
    this->pin_state = pin_state;
    if(this->pin_state==0)bcm2835_gpio_set_pud(pin_nr,BCM2835_GPIO_FSEL_OUTP);
    else{
        bcm2835_gpio_set_pud(pin_nr,BCM2835_GPIO_PUD_UP);//pull up
        bcm2835_gpio_fsel(pin_nr,BCM2835_GPIO_FSEL_INPT);
    }
    this->pin_dir=pin_dir;
}
void Pinclass :: changeDirection()
{
    if(pin_state == 0)//pin is
    {
        bcm2835_gpio_set_pud(pin_nr,BCM2835_GPIO_PUD_UP);//pull up
        bcm2835_gpio_fsel(pin_nr,BCM2835_GPIO_FSEL_INPT);
    }
    else
        bcm2835_gpio_fsel(pin_nr,BCM2835_GPIO_FSEL_OUTP);
}

void Pinclass :: Set(int value)
{
    if(pin_dir== 0 )//pin is output
    {
        bcm2835_gpio_write(pin_nr,value);
    }
    else
    {
        //do nothing
    }
}

uint8_t Pinclass :: Get()
{
    uint8_t  val;
    if(pin_dir==0){ //pin is output
        val = bcm2835_gpio_lev(pin_nr);
        return val;
    }
    else{

        return 0xFF;//invalid value

    }

}

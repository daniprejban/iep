#ifndef PINCLASS_H
#define PINCLASS_H

#include "bcm2835.h"

 class Pinclass
{
    protected:
        uint8_t pin_nr;
        uint8_t pin_state;
        uint8_t pin_dir;




    public:
        Pinclass(uint8_t pin_nr, uint8_t pin_state,uint8_t pin_dir);
        void changeDirection();
        void Set(int);
        uint8_t Get();
};


#endif // PINCLASS_H

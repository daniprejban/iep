#ifndef PWM_H
#define PWM_H
#include "bcm2835.h"

#define PWM_CHANNEL 0
class Pwm
{


    protected:
        int freq;
        int duty_cycle;


    public:
        Pwm(int freq,int duty_cycle);

        void Set_duty_cycle(int duty_c);
        void Set_freq(int freq);
        int Get_freq();
        int Get_duty_cycle();

};

#endif // PWM_H

#include "pwm.h"

Pwm::Pwm( int freq ,int duty_cycle)
{

   this->freq=freq;
   this->duty_cycle =duty_cycle;
   bcm2835_pwm_set_clock(BCM2835_PWM_CLOCK_DIVIDER_16);
   bcm2835_pwm_set_mode(PWM_CHANNEL, 1, 1);

}
void Pwm::Set_duty_cycle(int duty_c)
{
    int data =0;
    data = (this->freq *duty_c)/100;

    bcm2835_pwm_set_data(PWM_CHANNEL, data);
}

int Pwm::Get_duty_cycle()
{
    return this->duty_cycle;
}

int Pwm::Get_freq()
{
    return this->freq;
}

void Pwm::Set_freq(int freq)
{
    this->freq=freq;
    bcm2835_pwm_set_range(PWM_CHANNEL,  this->freq);
}

class Pin
{
	protected:
		int pin_nr;
		uint8 pin_state;
		uint8 pin_dir;
		
	Pin:: Pin (int pin_nr, uint8 pin_state)
	{
		this->pin_nr = pin_nr;
		this->pin_state = pin_state;
		if(this->pin_state==0)bcm2835_gpio_set_pud(pin_nr,BCM2835_GPIO_FSEL_OUTP);
		else{
			bcm2835_gpio_set_pud(pin_nr,BCM2825_GPIO_PUD_UP);//pull up
			bcm2835_gpio_set_pud(pin_nr,BCM2835_GPIO_FSEL_INPT);
		}
	}
	
	public:
	void changeDirection();
	void Set(int);
	uint8 Get();
}

void Pin :: changeDirection()
{
	if(pin_state == 0)//pin is 
	{
		bcm2835_gpio_set_pud(pin_nr,BCM2825_GPIO_PUD_UP);//pull up
		bcm2835_gpio_set_pud(pin_nr,BCM2835_GPIO_FSEL_INPT);
	}
	else
		bcm2835_gpio_set_pud(pin_nr,BCM2835_GPIO_FSEL_OUTP);
}

void Pin :: Set(int value)
{
	if(pin_state== 0 )//pin is output 
	{
		
		bcm2835_gpio_write(pin_nr,value);
	}
	else
	{
		//do nothing
	}
}

uint8 Pin :: Get()
{
	uint8  val;
	if(pin_state==0){ //pin is output
        val = bcm2835_gpio_lev(pin_nr);
		return val;
		
	}
	else{
		
		
		
	}
	
}
class Pin
{
	protected: 
		int pin_nr; 
		uint8 pin_state;
		uint8 pin_dir;
	
	Pin: Pin(int pin_nr, uint8 pin_state, uint8 pin_dir)
	{
		this->pin_nr = pin_nr;
		this->pin_state = pin_state;
		this->pin_dir = pin_dir;
	}
	
	public:
	void changeDirection();
	void Set(int);
	uint8 Get();
}

void Pin :: changeDirection()
{
	if(pin_dir ==  0)
		pin_dir =1;
	else
		pin_dir = 0;
}

void Pin :: Set(int value)
{
	if(pin_dir == 1) //pin is output
		pin_state = value;
	else //pin is input
	{
		//do nothing
	}
}

uint8 Pin :: Get()
{
		return pin_state;	
}
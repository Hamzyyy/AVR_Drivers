
#include "Lib/types.h"
#include "Lib/bitwise.h"
#include "DIO_priv.h"
#include "DIO_int.h"




void DIO_VidSetPinVal(u8 u8PortID_Cpy, u8 u8PinID_Cpy, u8 u8PinVal_Cpy)
{
	// check  that the PORT ID and PIN ID are in valid range

	if(u8PortID_Cpy <= DIO_PORTD && u8PinID_Cpy <= DIO_PIN7)
	{
		if (u8PinVal_Cpy == DIO_HIGH)
		{//2
		switch (u8PortID_Cpy)
		{//1
		case DIO_PORTA: SET_BIT(PORTA_REG,u8PinID_Cpy);
		break;
		case DIO_PORTB: SET_BIT(PORTB_REG,u8PinID_Cpy);
		break;
		case DIO_PORTC: SET_BIT(PORTC_REG,u8PinID_Cpy);
		break;
		case DIO_PORTD: SET_BIT(PORTD_REG,u8PinID_Cpy);
		break;
	    }//1
		}//2

		/* else if in order to be precised so if he pressed 3 does not enter the else */
		else if (u8PinVal_Cpy == DIO_LOW)
		{//3
			switch (u8PortID_Cpy)
			{//4
			case DIO_PORTA: CLR_BIT(PORTA_REG,u8PinID_Cpy);
			break;
			case DIO_PORTB: CLR_BIT(PORTB_REG,u8PinID_Cpy);
			break;
			case DIO_PORTC: CLR_BIT(PORTC_REG,u8PinID_Cpy);
			break;
			case DIO_PORTD: CLR_BIT(PORTD_REG,u8PinID_Cpy);
			break;
		    }//4
	        }//3
else
{
	/* report an error not high nor low*/
}
}
else
{
	/* report an error out of range for port*/
}
} //1


void DIO_VidSetPinDir(u8 u8PortID_Cpy, u8 u8PinID_Cpy, u8 u8PinDir_Cpy)
{
// check on that the PORT ID and PIN ID in valid range

if(u8PortID_Cpy <= DIO_PORTD && u8PinID_Cpy <= DIO_PIN7)
{
	if (u8PinDir_Cpy == DIO_OUTPUT)
	{
	switch (u8PortID_Cpy)
	{
	case DIO_PORTA: SET_BIT(DDRA_REG,u8PinID_Cpy);
	break;
	case DIO_PORTB: SET_BIT(DDRB_REG,u8PinID_Cpy);
	break;
	case DIO_PORTC: SET_BIT(DDRC_REG,u8PinID_Cpy);
	break;
	case DIO_PORTD: SET_BIT(DDRD_REG,u8PinID_Cpy);
	break;
    }
	}
	else if (u8PinDir_Cpy == DIO_INPUT)
	{
		switch (u8PortID_Cpy)
		{
		case DIO_PORTA: CLR_BIT(DDRA_REG,u8PinID_Cpy);
		break;
		case DIO_PORTB: CLR_BIT(DDRB_REG,u8PinID_Cpy);
		break;
		case DIO_PORTC: CLR_BIT(DDRC_REG,u8PinID_Cpy);
		break;
		case DIO_PORTD: CLR_BIT(DDRD_REG,u8PinID_Cpy);
		break;
	    }
}
else
{
	    /* report an error not output nor input*/
}
}
	else
	{
		/* report an error out of range for port*/
	}
	}


u8 DIO_u8GetPinVal (u8 u8PortID_Cpy, u8 u8PinID_Cpy)
{
	u8 result_loc;

	if(u8PortID_Cpy <= DIO_PORTD && u8PinID_Cpy <= DIO_PIN7)
	{
		switch (u8PortID_Cpy)
		{
		case DIO_PORTA: result_loc = GET_BIT(PINA_REG,u8PinID_Cpy);
		break;
		case DIO_PORTB: result_loc = GET_BIT(PINB_REG,u8PinID_Cpy);
		break;
		case DIO_PORTC: result_loc = GET_BIT(PINC_REG,u8PinID_Cpy);
		break;
		case DIO_PORTD: result_loc = GET_BIT(PIND_REG,u8PinID_Cpy);
		break;
	    }
	}
	else
	{
		/** in case of error **/
		result_loc = 0xff;
	}
	return result_loc;
}

void DIO_voidTogglePinVal(u8 u8PortID_Cpy,u8 u8PinID_Cpy)
{
	if((u8PortID_Cpy <= 3) && (u8PinID_Cpy <= 7))
	{
				switch(u8PortID_Cpy)
				{
				case DIO_PORTA : PORTA_REG = TOG_BIT(PORTA_REG,u8PinID_Cpy);
				break;
				case DIO_PORTB : PORTB_REG = TOG_BIT(PORTB_REG,u8PinID_Cpy);
				break;
				case DIO_PORTC : PORTC_REG = TOG_BIT(PORTC_REG,u8PinID_Cpy);
				break;
				case DIO_PORTD : PORTD_REG = TOG_BIT(PORTD_REG,u8PinID_Cpy);
				break;
				default:
					break;
				}
}
}


void DIO_VidSetPortVal (u8 u8PortID_Cpy, u8 u8PortVal_Cpy)
{
	if (u8PortID_Cpy <= DIO_PORTD)
	{
		switch (u8PortID_Cpy)
		{
		case DIO_PORTA: PORTA_REG = u8PortVal_Cpy;
		break;
		case DIO_PORTB: PORTB_REG = u8PortVal_Cpy;
		break;
		case DIO_PORTC: PORTC_REG = u8PortVal_Cpy;
		break;
		case DIO_PORTD: PORTD_REG = u8PortVal_Cpy;
		break;
		}
	}

	else
	{
		// report error out of range
	}
}

void DIO_VidSetPortDir (u8 u8PortID_Cpy, u8 u8PortDir_Cpy)
{
	if (u8PortID_Cpy <= DIO_PORTD)
	{
		switch (u8PortID_Cpy)
		{
		case DIO_PORTA: DDRA_REG = u8PortDir_Cpy;
		break;
		case DIO_PORTB: DDRB_REG = u8PortDir_Cpy;
		break;
		case DIO_PORTC: DDRC_REG = u8PortDir_Cpy;
		break;
		case DIO_PORTD: DDRD_REG = u8PortDir_Cpy;
		break;
		}
	}
	else
	{
		// report error out of range
	}
}


	u8 DIO_u8GetPortVal(u8 u8PortID_Cpy)
	{
	u8 res_loc = 0;

		if(u8PortID_Cpy <= DIO_PORTD)
		{
			switch(u8PortID_Cpy)
			{
			case DIO_PORTA : res_loc = PINA_REG;
			break;
			case DIO_PORTB : res_loc = PINB_REG;
			break;
			case DIO_PORTC : res_loc = PINC_REG;
			break;
			case DIO_PORTD : res_loc = PIND_REG;
			break;
			}
		}
		else
		{
			/*report out of rang error*/
		}
	return res_loc;
}


#include "Lib/types.h"
#include "Lib/bitwise.h"
#include "SvnSeg_int.h"
#include "SvnSeg_priv.h"




u8 u8Svn_Seg( u8 u8_modeCPY, u8 u8_numberCPY)
{
	u8 result_loc;
	u8 svn_seg_loc[10]={0b00111111,0b00000110,0b001011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};

	if (u8_modeCPY <= 1 && u8_numberCPY <= 9)
	{
		switch (u8_modeCPY)
		{
		case SvnSeg_CommonCathode : result_loc = svn_seg_loc[u8_numberCPY];
		break;

		case SvnSeg_CommonAnode : result_loc = ~svn_seg_loc[u8_numberCPY];
		break;

		}

	}
	else
	{
		/* out of range*/
	}

	return result_loc;
}



/*
 * int.h
 *
 *  Created on: Apr 27, 2019
 *      Author: Hamzy
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_

/*********************** HArdware connection ************/
/*
 -----------                   ----------
 | ATmega32  |                 |   LCD    |
 |           |                 |          |
 |        PD7|---------------->|D7        |
 |        PD6|---------------->|D6        |
 |        PD5|---------------->|D5        |
 |        PD4|---------------->|D4        |
 |        PD3|---------------->|D3        |
 |        PD2|---------------->|D2        |
 |        PD1|---------------->|D1        |
 |        PD0|---------------->|D0        |
 |           |                 |          |
 |        PC2|---------------->|E         |
 |        PC1|---------------->|RW        |
 |        PC0|---------------->|RS        |
 -----------                   ----------
*/

/***********************************/
/********PUBLIC MACROS*************/
/*********************************/

/* Instruction set for Function set */

/*
 * RS R/W DB7  DB6  DB5  DB4  DB3  DB2  DB1  DB0
 * 0   0   0    0    1    1    N    F    X    X
 *
 *N = 0 ONE LINE
 *D = 1 TWO LINE
 *F = 0 5*7 CHARACTER
 *C = 1 5*8 CHARACTER
 *
 * */

#define LCD_FUNSET_4BIT				0X28
#define LCD_FUNSET_8BIT				0X38



/* Instruction set for display ON/OFF control */

/*
 * RS R/W DB7  DB6  DB5  DB4  DB3  DB2  DB1  DB0
 * 0   0   0    0    0    0    1    D    C    B
 *
 *D = 0 DISPLAY OFF
 *D = 1 DISPLAY ON
 *C = 0 CURSOR OFF
 *C = 1 CURSOR ON
 *B = 0 BLINK OFF
 *B = 1 BLINK ON
 *
 * */

                                                   //  Display       Cursor          Blinking

#define LCD_DISPOFF_CUROFF_BLKOFF		0X08      //	off		      off	     	   off
#define LCD_DISPON_CUROFF_BLKOFF		0X0C      //	on		      off	     	   off
#define LCD_DISPON_CURON_BLKOFF		    0X0E      //	on		      on	     	   off
#define LCD_DISPON_CURON_BLKON		    0X0F      //	on		      on	     	   on


/* Instruction set for display clear */

#define LCD_CLR_DIS    0x01  /* to clear the display */
#define LCD_HOME       0x02  /* return shifted characters and  DDRAM to address 00H on AC */



/*  Entry Mode:  Instruction to set the move direction of the cursor and display
 *
 * RS R/W DB7  DB6  DB5  DB4  DB3  DB2  DB1  DB0
 * 0   0   0    0    0    0    0    1   I/D  SH
 *  I/D=0	cursor decrease
 *  I/D=1	cursor increase
 *  SH =0	disable display shift
 *  SH =1	enable display shift with cursor direction
 *  **/

#define LCD_EntryMode_CURDEC_SHDIS				0X04 //cursor decrease & disable display shift
#define LCD_EntryMode_CURDEC_SHEN			    0X05 //cursor decrease & enable display shift
#define LCD_EntryMode_CURIN_SHDIS				0X06 //cursor increase & disable display shift
#define LCD_EntryMode_CURIN_SHEN				0X07 //cursor increase & enable display shift



/* Cursor or display shift:
 * Shifts the cursor position or display to the right or left without writing or reading display data
 *
 * RS R/W DB7  DB6  DB5  DB4  DB3  DB2  DB1  DB0
 * 0   0   0    0    0    1   S/C  R/L   -    -
 */

#define LCD_SHCUR_LFT				0b00010000 //SHIFT cursor left decrease AC
#define LCD_SHCUR_RT				0b00010100 //SHIFT cursor right increase AC
#define LCD_SHDIS_LFT				0b00011000 //SHIFT DISPLAY left with cursor
#define LCD_SHDIS_RT				0b00011100 //SHIFT DISPLAY right with cursor




/* Set CGRAM ADDRESS TO "0"
 * RS R/W DB7  DB6  DB5  DB4  DB3  DB2  DB1  DB0
 * 0   0   0    1           ADRESS
 */
#define LCD_SET_CGRAM	 0X40



 /* Set DDRAM ADDRESS TO "0"
 * RS R/W DB7  DB6  DB5  DB4  DB3  DB2  DB1  DB0
 * 0   0   1              ADRESS
 */
#define LCD_SET_CURSOR	           0X80

/* General Definitions */

#define LCD_LOW		               	0
#define LCD_HIGH		           	1
#define LCD_4BIT_MODE		       	4
#define LCD_8BIT_MODE	          	8




/***********************************/
/********PUBLIC FUNCTION***********/
/*********************************/

void LCD_vid_Initial(void);          /* Initialization setting of the LCD */
void LCD_vidSend_CMD(u8 u8CMD);      /* Send a command to the LCD  */
void LCD_vidSend_char(u8 u8char);    /* Send a character to the LCD  */
void LCD_vidGoto(u8 u8x, u8 u8y);    /* to go to a place on the LCD (row & column) */
void LCD_vidShift_L(void);            /* to shift to the left */
void LCD_vidShift_R(void);            /* to shift to the right */
void LCD_vidSend_word(u8 *str);         /* to print a string on the LCD */
void LCD_vidPrint_int(u16 u16int_cpy);  /* To print an Integer on the  LCD*/



#endif /* LCD_INT_H_ */

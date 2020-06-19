
#ifndef LCD_CFG_H_
#define LCD_CFG_H_

 #define LCD_MODE 8 /* Only 8bit mode works*/

 #if LCD_MODE==4                     //not completed yet
#define LCD_DATA_PORT               DIO_PORTD
#define LCD_CTL_PORT               	DIO_PORTC
#define LCD_RS		               	DIO_PIN1
#define LCD_RW		               	DIO_PIN2
#define LCD_E		               	DIO_PIN0

#elif LCD_MODE == 8

#define LCD_DATA_PORT               DIO_PORTB	/* data port */
#define LCD_CTL_PORT               	DIO_PORTD	/* control port */
#define LCD_RS		               	DIO_PIN0	/* register select command or data register */
#define LCD_RW		               	DIO_PIN1	/* read or write select */
#define LCD_EN		               	DIO_PIN2 	/* enable to get enable pulse */

#else
#endif
#endif /* LCD_CFG_H_ */

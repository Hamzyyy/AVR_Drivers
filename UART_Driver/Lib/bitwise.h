#ifndef BITWISE_H
#define BITWISE_H

//TO SET A BIT IN A BYTE TO 1
#define SET_BIT(byte, bit) (byte |= (1 << bit))

//TO CLEAR A BIT IN A BYTE TO 0
#define CLR_BIT(byte, bit) (byte &= ~(1 << bit))

//TO TOGGLE THE VALUE OF A BIT IN A BYTE
#define TOG_BIT(byte, bit) (byte ^= (1 << bit))

//TO GET THE VALUE OF A BIT IN A BYTE
#define GET_BIT(byte, bit) ((byte >> bit) & 1)

#endif

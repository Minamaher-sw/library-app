/*
 * Std_type_var.h
 *
 *  Created on: ١٣‏/٠٩‏/٢٠٢٢
 *      Author: DELL
 */

#ifndef STD_TYPE_VAR_H_
#define STD_TYPE_VAR_H_

//ch->char  un->unsigned  8-> is size of bits
typedef unsigned char       chun8;//chun8 is u8
//sh->short un->unsigned  16-> is size of bits
typedef unsigned short      shun16;//shun16 is u16
//lo->long  un->unsigned  32-> is size of bits
typedef unsigned long       loun32;//loun32 u32
//lo->long  un->unsigned  64-> is size of bits
typedef  unsigned long long loloun64;//loloun is u64
//ch->char  si->signed    8-> is size of bits
typedef  signed char        chsi8;
//sh->short si->signed    16-> is size of bits
typedef  signed short       shsi16;
//lo->long  si->signed  32-> is size of bits
typedef  signed long        losi32;
//lo->long  un->unsigned  64-> is size of bits
typedef  signed long long   lolosi64;
//NULL POINTER used for set call function
#define NULLPTR  ((void*)0)

#define KEY_PORT PORTC

#endif /* STD_TYPE_VAR_H_ */

/*
 * BIT_MATH.h
 *
 * Created: 12/7/2021 4:49:13 PM
 *  Author: hp
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

/*For a single bit in the register*/
#define SET_BIT(reg,bit)   (reg |= (1<<bit))
#define CLR_BIT(reg,bit)   (reg &= ~(1<<bit))
#define TOG_BIT(reg,bit)   (reg ^= (1<<bit))
#define GET_BIT(REG,BIT)   ((REG >> BIT)&1)

/*For custom number of bits in the register*/
#define SETBits(reg,bMsk)	reg |= (bMsk)
#define CLRBits(reg,bMsk)	reg &= (~(bMsk))
#define TGLBits(reg,bMsk)	reg ^= (bMsk)

/*For all bits in the register*/
#define SETALLBits(reg)		reg = (0xFF)
#define CLRALLBits(reg)		reg = (0x00)
#define TGLALLBits(reg)		reg ^= (0xFF)




#endif /* BIT_MATH_H_ */
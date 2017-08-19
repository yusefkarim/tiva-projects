#ifndef SWITCHES_H
#define SWITCHES_H

#define WalkButton      (GPIO_PORTE_DATA_R&0x01)
#define BlockButton     (GPIO_PORTE_DATA_R&0x02)
#define AttackButton    (GPIO_PORTE_DATA_R&0x04)

//------------Switches_Init------------//
//Setup port E, PE2-0
void Switches_Init(void);

#endif

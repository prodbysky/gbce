#ifndef REGISTERS_H
#define REGISTERS_H
#include <stdint.h>
typedef struct
{
    uint8_t a;
    uint8_t b;
    uint8_t c;
    uint8_t d;
    uint8_t e;
    uint8_t f;
    uint8_t h;
    uint8_t l;
    uint16_t pc;
    uint16_t sp;
} GB_Registers;

#define GB_REGISTERS_F_ZERO 0b10000000
#define GB_REGISTERS_F_SUB 0b01000000
#define GB_REGISTERS_F_HALF_CARRY 0b00100000
#define GB_REGISTERS_F_CARRY 0b00010000

#define DEFINE_GB_REGISTERS_GET(r1, r2)                                      \
    uint16_t GB_Registers_get_##r1##r2(const GB_Registers* registers)        \
    {                                                                        \
        return (((uint16_t)registers->r1) << 8) | ((uint16_t)registers->r2); \
    }

#define DEFINE_GB_REGISTERS_SET(r1, r2)                                      \
    void GB_Registers_set_##r1##r2(GB_Registers* registers, uint16_t r1##r2) \
    {                                                                        \
        registers->r1 = (r1##r2 >> 8) & 0xff;                                \
        registers->r2 = r1##r2 & 0xff;                                       \
    }

#endif

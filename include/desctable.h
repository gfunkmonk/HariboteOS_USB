#pragma once

#define ADDR_IDT 0x0026f800
#define LIMIT_IDT 0x000007ff
#define ADDR_GDT 0x00270000
#define LIMIT_GDT 0x0000ffff
#define ADDR_BOTPAK 0x00280000
#define LIMIT_BOTPAK 0x0007ffff
#define AR_DATA32_RW 0x4092
#define AR_CODE32_ER 0x409a
#define AR_TSS32 0x0089
#define AR_INTGATE32 0x008e

#define AR_LDT 0x0082

struct SEGMENT_DESCRIPTOR {
    short limit_low, base_low;
    char base_mid, access_right;
    char limit_high, base_high;
};

struct GATE_DESCRIPTOR {
    short offset_low, selector;
    char dw_count, access_right;
    short offset_high;
};

void init_gdtidt(void);
void set_segmdesc(struct SEGMENT_DESCRIPTOR* sd, unsigned int limit, int base, int ar);
void set_gatedesc(struct GATE_DESCRIPTOR* gd, int offset, int selector, int ar);

// 
int ar_cal(unsigned char type, unsigned char p, unsigned char dpl, unsigned char d);
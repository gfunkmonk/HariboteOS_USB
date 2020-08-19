#ifndef _SHEET_H_
#define _SHEET_H_

#include "memory.h"

#define SHEET_USE TRUE
#define SHEET_VACANT FALSE
#define MAX_SHEETS 256

struct SHEET {
    unsigned char* buf;
    int bxsize, bysize, vx0, vy0, col_inv, height, flags;
    struct SHTCTL* ctl;
};

struct SHTCTL {
    unsigned char *vram, *map;
    int xsize, ysize, top;
    struct SHEET* sheets[MAX_SHEETS];
    struct SHEET sheets0[MAX_SHEETS];
};

struct SHTCTL* shtctl_init(struct MEMMAN* memman, unsigned char* vram, int xsize, int ysize);
struct SHEET* sheet_alloc(struct SHTCTL* ctl);
void sheet_setbuf(struct SHEET* sht, unsigned char* buf, int xsize, int ysize, int col_inv);
void sheet_refreshsub(struct SHTCTL* ctl, int vx0, int vy0, int vx1, int vy1, int h0, int h1);
void sheet_updown(struct SHEET* sht, int height);
void sheet_refresh(struct SHEET* sht, int bx0, int by0, int bx1, int by1);
void sheet_slide(struct SHEET* sht, int vx0, int vy0);
void sheet_free(struct SHEET* sht);
void sheet_refreshmap(struct SHTCTL* ctl, int vx0, int vy0, int vx1, int vy1, int h0);

#endif
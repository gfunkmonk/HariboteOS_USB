#include "mylibgcc.h"

#include "asmfunc.h"
#include "general.h"
#include "timer.h"
#include "fifo.h"
#include "console.h"

#define BUF_SIZ (256)
#define STR_LIM (1024)

// positive if s1 > s2, negative if s1 < s2, zero if equal
int strncmp(const char* s1, const char* s2, size_t n) {
    for (int i = 0; i < n; ++i) {
        if ((s1[i] && !s2[i]) || s1[i] > s2[i]) return 1;
        if ((!s1[i] && s2[i]) || s1[i] < s2[i]) return -1;
    }
    return 0;
}

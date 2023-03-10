#include "library.h"
#include "amod.h"
#include <iostream>

static int x, y;

void hello() {
    std::cout << "Hello, World!" << std::endl;
}

AstoniaMod_EXPORT void amod_gamestart(void) {
    note("A Mod by ModderMcModFace loaded.");
    std::cout << "Hello, World from c++!" << std::endl;
    x = (dotx(DOT_MBR) + dotx(DOT_MTL)) / 2;
    y = (doty(DOT_MBR) + doty(DOT_MTL)) / 2;
}

AstoniaMod_EXPORT void amod_frame(void) {
    static int dx = 1, dy = 1, step = 0;
    x += dx;
    if (x > dotx(DOT_MBR) - 2) dx = -1;
    if (x < dotx(DOT_MTL) + 2) dx = 1;
    y += dy;
    if (y > doty(DOT_MBR) - 2) dy = -1;
    if (y < doty(DOT_MTL) + 2) dy = 1;
    //dd_pixel(x,y,IRGB(31,15,7));
    dd_copysprite(1024 + step, x, y, 15, DD_CENTER);
    step++;
    if (step > 9) step = 0;
    dd_drawtext_fmt(10, 100, IRGB(31, 31, 31), DD_SHADE | DD_NOCACHE, "x=%d, y=%d", x, y);
}
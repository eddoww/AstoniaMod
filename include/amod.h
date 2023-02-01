/*
 * Part of Astonia Client (c) Daniel Brockhaus. Please read license.txt.
 */
#ifndef ASTONIAMOD_AMOD_H
#define ASTONIAMOD_AMOD_H

#define DllImport   __declspec( dllimport )
#ifdef __cplusplus
extern "C" {
#endif

DllImport void amod_init(void);
DllImport void amod_exit(void);
DllImport void amod_gamestart(void);
DllImport void amod_frame(void);
DllImport void amod_tick(void);
DllImport int amod_display_skill_line(int v, int base, int curr, int cn, char *buf);
DllImport void amod_mouse_move(int x, int y);
DllImport int amod_mouse_click(int x, int y, int what);// return true if mouse click should NOT be processed by the client

// --------- Client exported functions -----------

// basics
DllImport int note(const char *format, ...) __attribute__((format(printf, 1, 2)));
DllImport int warn(const char *format, ...) __attribute__((format(printf, 1, 2)));
DllImport int fail(const char *format, ...) __attribute__((format(printf, 1, 2)));
DllImport void paranoia(const char *format, ...) __attribute__((format(printf, 1, 2)));
DllImport void addline(const char *format, ...) __attribute__((format(printf, 1, 2)));
// game, drawing
DllImport void dd_push_clip(void);
DllImport void dd_pop_clip(void);
DllImport void dd_more_clip(int sx, int sy, int ex, int ey);
DllImport void dd_copysprite(int sprite, int scrx, int scry, int light, int align);
DllImport void dd_rect(int sx, int sy, int ex, int ey, unsigned short int color);
DllImport void dd_line(int fx, int fy, int tx, int ty, unsigned short col);
DllImport int dd_textlength(int flags, const char *text);
DllImport int dd_drawtext(int sx, int sy, unsigned short int color, int flags, const char *text);
DllImport int dd_drawtext_break(int x, int y, int breakx, unsigned short color, int flags, const char *ptr);
DllImport void dd_pixel(int x, int y, unsigned short col);
DllImport int dd_drawtext_fmt(int sx, int sy, unsigned short int color, int flags, const char *format, ...);
DllImport int
dd_drawtext_break_fmt(int sx, int sy, int breakx, unsigned short int color, int flags, const char *format, ...);
// gui, dots and buttons
DllImport int dotx(int didx);
DllImport int doty(int didx);
DllImport int butx(int bidx);
DllImport int buty(int bidx);
// gui helperls
DllImport int get_near_ground(int x, int y);
DllImport int get_near_item(int x, int y, int flag, int looksize);
DllImport int get_near_char(int x, int y, int looksize);

// ---------- Client exported data structures -------------
#define V_MAX            200
struct player;
struct skltab;
DllImport extern int skltab_cnt;
DllImport extern struct skltab *skltab;
DllImport extern int item_flags[];
DllImport extern int weatab[];
DllImport int act;
DllImport int actx;
DllImport int acty;

DllImport unsigned int cflags;        // current item flags
DllImport unsigned int csprite;       // and sprite

DllImport int originx;
DllImport int originy;

DllImport int value[2][V_MAX];
DllImport int hp;
DllImport int mana;
DllImport int rage;
DllImport int endurance;
DllImport int lifeshield;
DllImport int experience;
DllImport int experience_used;
DllImport int mil_exp;
DllImport int gold;
DllImport int con_type;
DllImport char con_name[80];
DllImport int con_cnt;
DllImport int cprice;
DllImport int lookinv[12];
DllImport int looksprite, lookc1, lookc2, lookc3;
DllImport char look_name[80];
DllImport char look_desc[1024];
DllImport char pent_str[7][80];


// ---------------- override-able functions, also exported from client ----------------
DllImport int _is_cut_sprite(int sprite);
DllImport int _is_mov_sprite(int sprite, int itemhint);
DllImport int _is_door_sprite(int sprite);
DllImport int _is_yadd_sprite(int sprite);
DllImport int _get_chr_height(int csprite);
DllImport int
_trans_charno(int csprite, int *pscale, int *pcr, int *pcg, int *pcb, int *plight, int *psat, int *pc1, int *pc2,
              int *pc3, int *pshine, int attick);
DllImport int _get_player_sprite(int nr, int zdir, int action, int step, int duration, int attick);
struct map;
DllImport void _trans_csprite(int mn, struct map *cmap, int attick);
DllImport int _get_lay_sprite(int sprite, int lay);
DllImport int _get_offset_sprite(int sprite, int *px, int *py);
DllImport int _additional_sprite(int sprite, int attick);
DllImport int _opt_sprite(int sprite);
DllImport int _get_skltab_sep(int i);
DllImport int _get_skltab_index(int n);
DllImport int _get_skltab_show(int i);

// ------------ declarations for functions the mod might provide -------------------
int is_cut_sprite(int sprite);
int is_mov_sprite(int sprite, int itemhint);
int is_door_sprite(int sprite);
int is_yadd_sprite(int sprite);
int get_chr_height(int csprite);
int trans_charno(int csprite, int *pscale, int *pcr, int *pcg, int *pcb, int *plight, int *psat, int *pc1, int *pc2,
                 int *pc3, int *pshine, int attick);
int get_player_sprite(int nr, int zdir, int action, int step, int duration, int attick);
void trans_csprite(int mn, struct map *cmap, int attick);
int get_lay_sprite(int sprite, int lay);
int get_offset_sprite(int sprite, int *px, int *py);
int additional_sprite(int sprite, int attick);
int opt_sprite(int sprite);
int get_skltab_sep(int i);
int get_skltab_index(int n);
int get_skltab_show(int i);

// ---------- ignore ----------------
#ifndef min
#define min(a, b) (((a) < (b)) ? (a) : (b))
#endif

#ifndef max
#define max(a, b) (((a) > (b)) ? (a) : (b))
#endif

#ifndef ARRAYSIZE
#define ARRAYSIZE(a) (sizeof(a)/sizeof((a)[0]))
#endif

#define MAXCHARS    2048

#define DD_OFFSET        0       // this has to be zero, so bzero on the structures default this
#define DD_CENTER        1       // also used in dd_drawtext
#define DD_NORMAL        2

#define DD_LEFT         0
#define DD_CENTER       1
#define DD_RIGHT        2
#define DD_SHADE        4
#define DD_LARGE        0
#define DD_SMALL        8
#define DD_FRAME        16
#define DD_BIG            32
#define DD_NOCACHE      64

#define IGET_R(c) ((((unsigned short int)(c))>>10)&0x1F)
#define IGET_G(c) ((((unsigned short int)(c))>>5)&0x1F)
#define IGET_B(c) ((((unsigned short int)(c))>>0)&0x1F)
#define IRGB(r, g, b) (((r)<<10)|((g)<<5)|((b)<<0))

#define DOT_TL          0       // top left?
#define DOT_BR          1       // bottom right?
#define DOT_WEA         2       // worn equipment
#define DOT_INV         3       // inventory
#define DOT_CON         4       // container
#define DOT_SCL         5       // scroll bar left, uses only X
#define DOT_SCR         6       // scroll bar right, uses only X
#define DOT_SCU         7       // scroll bars up arrows at this Y
#define DOT_SCD         8       // scroll bars down arrors at thy Y
#define DOT_TXT         9       // chat window
#define DOT_MTL         10      // map top left
#define DOT_MBR         11      // map bottom right
#define DOT_SKL         12      // skill list
#define DOT_GLD         13      // gold
#define DOT_JNK         14      // trashcan
#define DOT_MOD         15      // speed mode
#define DOT_MCT         16      // map center
#define DOT_TOP         17      // top left corner of equipment bar
#define DOT_BOT         18      // top left corner of bottom window holding skills, chat, etc.
#define DOT_TX2         19      // chat window bottom right
#define DOT_SK2         20      // skill list window bottom right
#define DOT_IN1         21      // inventory top left
#define DOT_IN2         22      // inventory bottom right
#define DOT_HLP         23      // help top left
#define DOT_HL2         24      // help bottom right
#define DOT_TEL         25      // teleporter top left
#define DOT_COL         26      // color picker top left
#define DOT_LOK         27      // look at character window (show_look), top left
#define MAX_DOT         28

#define V_HP        0
#define V_ENDURANCE    1
#define V_MANA        2

#define V_WIS            3
#undef  V_INT           // everyone likes windoof
#define V_INT            4
#define V_AGI            5
#define V_STR        6

#define V_ARMOR        7
#define V_WEAPON    8
#define V_LIGHT        9
#define V_SPEED        10

#define V_PULSE        11
#define V_DAGGER        12
#define V_HAND            13
#define V_STAFF            14
#define V_SWORD            15
#define V_TWOHAND        16

#define V_ARMORSKILL    17
#define V_ATTACK        18
#define V_PARRY            19
#define V_WARCRY        20
#define V_TACTICS        21
#define V_SURROUND        22
#define V_BODYCONTROL    23
#define V_SPEEDSKILL    24

#define V_BARTER        25
#define V_PERCEPT        26
#define V_STEALTH        27

#define V_BLESS        28
#define V_HEAL        29
#define V_FREEZE    30
#define V_MAGICSHIELD    31
#define V_FLASH        32

#define V_FIREBALL    33
//#define V_BALL		34

#define V_REGENERATE    35
#define V_MEDITATE    36
#define V_IMMUNITY    37

#define V_DEMON        38
#define V_RAGE        40
#define V_COLD        41
#define V_PROFESSION    42

#define SDL_MOUM_LUP        1
#define SDL_MOUM_LDOWN      2
#define SDL_MOUM_RUP        3
#define SDL_MOUM_RDOWN      4
#define SDL_MOUM_MUP        5
#define SDL_MOUM_MDOWN      6
#define SDL_MOUM_WHEEL      7

struct complex_sprite {
    unsigned int sprite;
    unsigned short c1, c2, c3, shine;
    unsigned char cr, cg, cb;
    unsigned char light, sat;
    unsigned char scale;
};

struct map {
    // from map & item
    unsigned short int gsprite;     // background sprite
    unsigned short int gsprite2;    // background sprite
    unsigned short int fsprite;     // foreground sprite
    unsigned short int fsprite2;    // foreground sprite

    unsigned int isprite;       // item sprite
    unsigned short ic1, ic2, ic3;

    unsigned int flags;             // see CMF_

    // character
    unsigned int csprite;       // character base sprite
    unsigned int cn;        // character number (for commands)
    unsigned char cflags;       // character flags
    unsigned char action;       // character action, duration and step
    unsigned char duration;
    unsigned char step;
    unsigned char dir;      // direction the character is facing
    unsigned char health;       // character health (in percent)
    unsigned char mana;
    unsigned char shield;
    // 15 bytes

    // effects
    unsigned int ef[4];

    unsigned char sink;     // sink characters on this field
    int value;                      // testing purposes only
    int mmf;                        // more flags
    char rlight;                    // real client light - 0=invisible 1=dark, 14=normal (15=bright can't happen)
    struct complex_sprite rc;

    struct complex_sprite ri;

    struct complex_sprite rf;
    struct complex_sprite rf2;
    struct complex_sprite rg;
    struct complex_sprite rg2;

    char xadd;                      // add this to the x position of the field used for c sprite
    char yadd;                      // add this to the y position of the field used for c sprite
};

struct skill {
    char name[80];
    int base1, base2, base3;
    int cost;       // 0=not raisable, 1=skill, 2=attribute, 3=power
    int start;      // start value, pts up to this value are free
};

struct skltab {
    int v;                          // negative v-values indicate a special display (empty lines, negative exp, etc...)
    int button;         // show button
    char name[80];
    int base;
    int curr;
    int raisecost;
    int barsize;                    // positive is blue, negative is red
};

typedef struct skltab SKLTAB;

struct player {
    char name[80];
    int csprite;
    short level;
    unsigned short c1, c2, c3;
    unsigned char clan;
    unsigned char pk_status;
};

#ifdef __cplusplus
}
#endif
#endif //ASTONIAMOD_AMOD_H
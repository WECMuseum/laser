#ifndef _DRIVERS_H_
#define _DRIVERS_H_


/*
 * patch (z80() and loop (6502) have been currently
 * disabled as no romsets use them at this point
 */

typedef struct {
    byte START;
    byte INSERT_COIN;
    byte BUTTON_1;
    byte BUTTON_2;
    byte BUTTON_3;
    byte BUTTON_4;
    byte PLAYER_1;
    byte PLAYER_2;
    byte LEFT;
    byte RIGHT;
    byte UP;
    byte DOWN;
    byte EVAL00; /* extra values */
    byte EVAL01;
    byte EVAL02;
    byte EVAL03;
    byte EVAL04;
    byte EVAL05;
    byte EVAL06;
    byte EVAL07;
    byte EVAL08;
    byte EVAL09;
} tagGameSettings;

typedef struct {
    char *romName;
    int address;
    int romSize;
    byte romCount;
} tagRomList;

typedef struct {
    char *gameName;
    tagRomList *romList;
    int (*init)(tagRomList gameRom[]);
    void (*start)(void);
    void (*shutdown)(void);
    word (*interrupt)(void);
    byte (*doin)(byte Port);
    void (*doout)(byte Port, byte Value);
    byte (*rdmem)(word A);
    void (*wrmem)(word A, byte V);
    void (*NMI)(void);
    void (*save_state)(void);
    void (*load_state)(void);
    int s_width;
    int s_height;
    tagGameSettings gameSettings;
} tagGameList;

typedef struct {
        int (*init)(tagRomList gameRom[]);
        void (*start)(void);
        void (*shutdown)(void);
        byte (*doin)(byte Port);
        void (*doout)(byte Port, byte Value);
        byte (*rdmem)(word A);
        void (*wrmem)(word A, byte V);
        void (*patch)(reg *R); /* required only for z80 emu */
        byte (*loop)(M6502 *R); /* required only for the 6502 emu */
        word (*interrupt)(void);
        void (*NMI)(void);
        void (*save_state)(void);
        void (*load_state)(void);
        int s_width;
        int s_height;
        tagGameSettings gameSettings;
} laserDriver;

void check_roms(int argc, char *argv[]);

/* Space Invaders driver */
int init_invaders(tagRomList gameRom[]);
void start_invaders();
void shutdown_invaders();
byte doin_invaders(byte Port);
void doout_invaders(byte Port, byte Value);
byte rdmem_invaders(word A);
void wrmem_lupin3(word A, byte V);
void wrmem_invaders(word A, byte V);
void wrmem_invadpt2(word A, byte V);
void wrmem_polaris(word A, byte V); /* req for polaris */
void patch_invaders(reg *R);
word interrupt_invaders();
word interrupt_polaris(); /* req for polaris */
void NMI_invaders();
void save_state_invaders();
void load_state_invaders();

/* Pong Doubles driver */
int init_pongdbls(tagRomList gameRom[]);
void start_pongdbls();
void shutdown_pongdbls();
byte doin_pongdbls(byte Port);
void doout_pongdbls(byte Port, byte Value);
byte rdmem_pongdbls(word A);
void wrmem_pongdbls(word A, byte V);
void patch_pongdbls(reg *R);
word interrupt_pongdbls();
void NMI_pongdbls();

/* Pong driver */
int init_pong(tagRomList gameRom[]);
void start_pong();
void shutdown_pong();
byte doin_pong(byte Port);
void doout_pong(byte Port, byte Value);
byte rdmem_pong(word A);
void wrmem_pong(word A, byte V);
void patch_pong(reg *R);
word interrupt_pong();
void NMI_pong();

/* hockeytv driver */
int init_hockeytv(tagRomList gameRom[]);
void start_hockeytv();
void shutdown_hockeytv();
byte doin_hockeytv(byte Port);
void doout_hockeytv(byte Port, byte Value);
byte rdmem_hockeytv(word A);
void wrmem_hockeytv(word A, byte V);
void patch_hockeytv(reg *R);
word interrupt_hockeytv();
void NMI_hockeytv();

#endif

#pragma once

#define CMD_SYMBOL_F_MODE 'x'
#define CMD_SYMBOL_MODE_DRAW 0
#define CMD_SYMBOL_MODE_SYS 1
#define CMD_SYMBOL_MODE_GFX 2
#define CMD_SYMBOL_MODE_DATA 3
#define CMD_SYMBOL_F_UPLOAD 'l'

#define CMD_SYMBOL_C_CONTEXT 'G'
#define CMD_SYMBOL_C_SCALE 'S'
#define CMD_SYMBOL_C_XOR 'X'

#define CMD_SYMBOL_F_CLEAR 'c'
#define CMD_SYMBOL_F_DRAW 'u'

#define CMD_SYMBOL_F_RECT 'r'
#define CMD_SYMBOL_F_LINE 'l'
#define CMD_SYMBOL_F_STRING 's'
#define CMD_SYMBOL_F_BITMAP 'b'

extern void cmd_on_mode(int mode);
extern void cmd_gfx_on_context(int ctx);
extern void cmd_gfx_on_draw();

extern int parseCommand(const char* cmd_bytes, int len);
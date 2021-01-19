#define INT_MOUSE 0x33
#define SERV_ACTIVA_MOUSE 0x00
#define SERV_MUESTRA_MOUSE 0x01
#define SERV_GET_MOUSE_STATUS 0x03
#define SERV_SET_MOUSE_XY 0x04

#define LX_MOUSE 640
#define LY_MOUSE 200

int activa_mouse();
void muestra_mouse();
int get_x_mouse();
int get_y_mouse();
int pulsado_left();
int pulsado_right();
void pinta_mouse();
void carga_cursor (char *nombre_fichero);
void set_xy_mouse(int x,int y);
void borra_mouse();
int mouse_movido();
void libera_cursor();
void lee_fondo_mouse();
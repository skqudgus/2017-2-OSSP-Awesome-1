#include "helpers.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

const int PLAYER_WIDTH = 20;
const int PLAYER_HEIGHT = 5;

const int BALL_SIZE = 10;
const int MAX_BALLS = 25;

const int BALL_VELOCITY = 2;

const int LEVEL_UP_COUNT = 100;//level이 증가할때에 대비해서 추가

const int INITIAL_MODE = 10;
const int EXIT = -1;
const int SINGLE_MODE = 0;
const int MULTI_MODE = 1;
const int SERVER_MODE = 2;
const int CLIENT_MODE = 3;

extern SDL_Surface *background;
extern SDL_Surface *screen;
extern SDL_Surface* title_message;
extern SDL_Surface* message;
extern SDL_Surface* message2;
extern SDL_Surface* player;
extern SDL_Surface* player2;
extern SDL_Surface* ball;

extern SDL_Event event;
extern TTF_Font *font;
extern TTF_Font *font2;

extern SDL_Rect balls[MAX_BALLS];

extern SDL_Color textColor;

bool init();
bool load_files();
void clean_up();

void main_game(int selector, int mode);
void init_ball();
void game_over(int score);
void menu();
int select_mode();
int select_level();
int waiting(int count);
int socketing();

//socket variable
int client, server;
int portNum = 1500;
const int bufsize = 1024;
int buffer_int[bufsize / 4];
int clientCount = 1;
unsigned int time_now;
char* ip = "127.0.0.1";

struct sockaddr_in server_addr;
socklen_t size;

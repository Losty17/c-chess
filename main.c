#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 8
#define TEXT_BLACK "\x1b[30m"
#define TEXT_WHITE "\x1b[37m"
#define TEXT_CYAN "\x1b[36m"
#define TEXT_HIDDEN "\x1b[8m"
#define BG_CYAN "\x1b[46m"
#define BG_BLACK "\x1b[40m"
#define BG_WHITE "\x1b[47m"
#define BG_RED "\x1b[41m"
#define RESET "\x1b[0m"

#ifdef _WIN32
#include <conio.h>
#else
#include <stdio.h>
#define clrscr() printf("\e[1;1H\e[2J")
#endif

enum Color {
    BLANK = 0,
    BLACK,
    WHITE
};

enum Type {
    NONE = 0,
    PAWN,
    ROOK,
    BISHOP,
    KNIGHT,
    QUEEN,
    KING,
};

typedef struct {
    enum Type type;
    enum Color color;
} piece_t;

typedef struct {
    piece_t pieces[SIZE][SIZE];
} board_t;

board_t *init_board() {
    board_t *b = (board_t *)malloc(sizeof(board_t));

    piece_t pieces[SIZE][SIZE] = {
        {{ROOK, BLACK}, {KNIGHT, BLACK}, {BISHOP, BLACK}, {KING, BLACK}, {QUEEN, BLACK}, {BISHOP, BLACK}, {KNIGHT, BLACK}, {ROOK, BLACK}},
        {{PAWN, BLACK}, {PAWN, BLACK}, {PAWN, BLACK}, {PAWN, BLACK}, {PAWN, BLACK}, {PAWN, BLACK}, {PAWN, BLACK}, {PAWN, BLACK}},
        {{NONE, BLANK}, {NONE, BLANK}, {NONE, BLANK}, {NONE, BLANK}, {NONE, BLANK}, {NONE, BLANK}, {NONE, BLANK}, {NONE, BLANK}},
        {{NONE, BLANK}, {NONE, BLANK}, {NONE, BLANK}, {NONE, BLANK}, {NONE, BLANK}, {NONE, BLANK}, {NONE, BLANK}, {NONE, BLANK}},
        {{NONE, BLANK}, {NONE, BLANK}, {NONE, BLANK}, {NONE, BLANK}, {NONE, BLANK}, {NONE, BLANK}, {NONE, BLANK}, {NONE, BLANK}},
        {{NONE, BLANK}, {NONE, BLANK}, {NONE, BLANK}, {NONE, BLANK}, {NONE, BLANK}, {NONE, BLANK}, {NONE, BLANK}, {NONE, BLANK}},
        {{PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE}},
        {{ROOK, WHITE}, {KNIGHT, WHITE}, {BISHOP, WHITE}, {KING, WHITE}, {QUEEN, WHITE}, {BISHOP, WHITE}, {KNIGHT, WHITE}, {ROOK, WHITE}},
    };

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            b->pieces[i][j] = pieces[i][j];
        }
    }

    return b;
}

char *get_piece_type(piece_t p) {
    switch (p.type) {
        case PAWN: return "P";
        case ROOK: return "R";
        case BISHOP: return "B";
        case KNIGHT: return "N";
        case QUEEN: return "Q";
        case KING: return "K";
        default: return " ";
    }
}

void color_square(int x, int y)
{
    if (y % 2 == 0) 
        if (x % 2 == 0)
            printf(BG_WHITE);
        else
            printf(BG_CYAN);
    else
        if (x % 2 == 0)
            printf(BG_CYAN);
        else
            printf(BG_WHITE);
}

void color_piece(piece_t p)
{
    char *color = p.color == BLACK ? TEXT_BLACK : p.color == WHITE ? TEXT_WHITE : TEXT_HIDDEN;

    printf("%s", color);
}

void print_board(board_t *board) {
    clrscr();
    printf(TEXT_CYAN BG_RED "    a  b  c  d  e  f  g  h    \n");
    for (int y = 0; y < SIZE; y++)
    {
        printf(TEXT_CYAN BG_RED " %d %s", y + 1, RESET);
        for (int x = 0; x < SIZE; x++)
        {
            piece_t piece = board->pieces[y][x];
            char *type = get_piece_type(piece);
            
            color_square(x, y);
            color_piece(piece);

            printf(" %s %s", type, RESET);
        }
        printf(TEXT_CYAN BG_RED " %d %s\n", y + 1, RESET);
    }
    printf(TEXT_CYAN BG_RED "    a  b  c  d  e  f  g  h    \n" RESET);
}

void move_piece(piece_t piece, int x, int y)
{
    
}

int main() {
    board_t *board = init_board();
    print_board(board);
}

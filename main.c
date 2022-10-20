#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define SIZE 8

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
    int id;
    piece_t *pieces[8];
} row_t;

typedef struct {
    row_t *rows;
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

    b->rows = (row_t *)malloc(sizeof(row_t *) * SIZE);
    for (int i = 0; i < SIZE; i++) {
        b->rows[i].id = i + 1;
        for (int j = 0; j < SIZE; j++) {
            b->rows[i].pieces[j] = (piece_t *)malloc(sizeof(piece_t));
            b->rows[i].pieces[j]->type = pieces[i][j].type;
            b->rows[i].pieces[j]->color = pieces[i][j].color;
        }
    }

    return b;
}

char *get_piece_color(piece_t *p) {
    return p->color == BLACK ? "B" : p->color == WHITE ? "W" : " ";
}

char *get_piece_type(piece_t *p) {
    switch (p->type) {
        case PAWN: return "P";
        case ROOK: return "R";
        case BISHOP: return "B";
        case KNIGHT: return "N";
        case QUEEN: return "Q";
        case KING: return "K";
        default: return " ";
    }
}

void print_board(board_t *board) {
    row_t *rows = board->rows;
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", rows[i].id);
        for (int j = 0; j < SIZE; j++) {
            piece_t *piece = rows[i].pieces[j];
            printf("%s%s ", get_piece_color(piece), get_piece_type(piece));
        }
        printf("\n");
    }
}

int main() {
    board_t *board = init_board();
    print_board(board);
}
#include <iostream>
#include <string.h>
#include <stdbool.h>

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

using namespace std;

#define clrscr() cout << "\033[1;1H\033[2J"

namespace chess
{
    enum Color
    {
        TRANSPARENT = 0,
        BLACK = 1,
        WHITE = 2,
    };

    enum Type
    {
        EMPTY = 0,
        PAWN = 1,
        KNIGHT = 2,
        BISHOP = 3,
        ROOK = 4,
        QUEEN = 5,
        KING = 6,
    };

    class Piece
    {
    public:
        enum Color color;
        enum Type type;
        int row;
        int col;

        Piece(enum Color color, enum Type type, int row, int col)
        {
            this->color = color;
            this->type = type;
            this->row = row;
            this->col = col;
        }

        void print()
        {
            bool is_white;

            if (this->row % 2 == 0)
            {
                if (this->col % 2 == 0)
                {
                    cout << BG_WHITE;
                    is_white = false;
                }
                else
                {
                    cout << BG_BLACK;
                    is_white = true;
                }
            }
            else if (this->col % 2 == 0)
            {
                cout << BG_BLACK;
                is_white = true;
            }
            else
            {
                cout << BG_WHITE;
                is_white = false;
            }

            if (is_white)
                cout << TEXT_WHITE;
            else
                cout << TEXT_BLACK;

            cout << " " << this->get_tag() << " " << RESET;
        }

        char get_tag()
        {
            if (this->type == PAWN)
                return 'P';
            else if (this->type == KNIGHT)
                return 'N';
            else if (this->type == BISHOP)
                return 'B';
            else if (this->type == ROOK)
                return 'R';
            else if (this->type == QUEEN)
                return 'Q';
            else if (this->type == KING)
                return 'K';

            return ' ';
        }
    };

    class Row
    {
    public:
        int id;
        Piece *pieces[SIZE];

        Row(Piece *pieces[SIZE], int id)
        {
            this->id = id;

            for (int i = 0; i < SIZE; i++)
            {
                this->pieces[i] = pieces[i];
            }
        }

        void print()
        {
            cout << " " << this->id << " ";

            for (int i = 0; i < SIZE; i++)
            {
                this->pieces[i]->print();
            }

            cout << " " << this->id << " ";

            cout << endl;
        }
    };

    class Board
    {
    public:
        Row *rows[SIZE];

        Board()
        {
            Piece *row_1[SIZE] = {
                new Piece(BLACK, ROOK, 0, 0),
                new Piece(BLACK, KNIGHT, 0, 1),
                new Piece(BLACK, BISHOP, 0, 2),
                new Piece(BLACK, QUEEN, 0, 3),
                new Piece(BLACK, KING, 0, 4),
                new Piece(BLACK, BISHOP, 0, 5),
                new Piece(BLACK, KNIGHT, 0, 6),
                new Piece(BLACK, ROOK, 0, 7),
            };

            Piece *row_2[SIZE] = {
                new Piece(BLACK, PAWN, 1, 0),
                new Piece(BLACK, PAWN, 1, 1),
                new Piece(BLACK, PAWN, 1, 2),
                new Piece(BLACK, PAWN, 1, 3),
                new Piece(BLACK, PAWN, 1, 4),
                new Piece(BLACK, PAWN, 1, 5),
                new Piece(BLACK, PAWN, 1, 6),
                new Piece(BLACK, PAWN, 1, 7),
            };

            Piece *row_3[SIZE] = {
                new Piece(TRANSPARENT, EMPTY, 2, 0),
                new Piece(TRANSPARENT, EMPTY, 2, 1),
                new Piece(TRANSPARENT, EMPTY, 2, 2),
                new Piece(TRANSPARENT, EMPTY, 2, 3),
                new Piece(TRANSPARENT, EMPTY, 2, 4),
                new Piece(TRANSPARENT, EMPTY, 2, 5),
                new Piece(TRANSPARENT, EMPTY, 2, 6),
                new Piece(TRANSPARENT, EMPTY, 2, 7),
            };

            Piece *row_4[SIZE] = {
                new Piece(TRANSPARENT, EMPTY, 3, 0),
                new Piece(TRANSPARENT, EMPTY, 3, 1),
                new Piece(TRANSPARENT, EMPTY, 3, 2),
                new Piece(TRANSPARENT, EMPTY, 3, 3),
                new Piece(TRANSPARENT, EMPTY, 3, 4),
                new Piece(TRANSPARENT, EMPTY, 3, 5),
                new Piece(TRANSPARENT, EMPTY, 3, 6),
                new Piece(TRANSPARENT, EMPTY, 3, 7),
            };

            Piece *row_5[SIZE] = {
                new Piece(TRANSPARENT, EMPTY, 4, 0),
                new Piece(TRANSPARENT, EMPTY, 4, 1),
                new Piece(TRANSPARENT, EMPTY, 4, 2),
                new Piece(TRANSPARENT, EMPTY, 4, 3),
                new Piece(TRANSPARENT, EMPTY, 4, 4),
                new Piece(TRANSPARENT, EMPTY, 4, 5),
                new Piece(TRANSPARENT, EMPTY, 4, 6),
                new Piece(TRANSPARENT, EMPTY, 4, 7),
            };

            Piece *row_6[SIZE] = {
                new Piece(TRANSPARENT, EMPTY, 5, 0),
                new Piece(TRANSPARENT, EMPTY, 5, 1),
                new Piece(TRANSPARENT, EMPTY, 5, 2),
                new Piece(TRANSPARENT, EMPTY, 5, 3),
                new Piece(TRANSPARENT, EMPTY, 5, 4),
                new Piece(TRANSPARENT, EMPTY, 5, 5),
                new Piece(TRANSPARENT, EMPTY, 5, 6),
                new Piece(TRANSPARENT, EMPTY, 5, 7),
            };

            Piece *row_7[SIZE] = {
                new Piece(WHITE, PAWN, 6, 0),
                new Piece(WHITE, PAWN, 6, 1),
                new Piece(WHITE, PAWN, 6, 2),
                new Piece(WHITE, PAWN, 6, 3),
                new Piece(WHITE, PAWN, 6, 4),
                new Piece(WHITE, PAWN, 6, 5),
                new Piece(WHITE, PAWN, 6, 6),
                new Piece(WHITE, PAWN, 6, 7),
            };

            Piece *row_8[SIZE] = {
                new Piece(WHITE, ROOK, 7, 0),
                new Piece(WHITE, KNIGHT, 7, 1),
                new Piece(WHITE, BISHOP, 7, 2),
                new Piece(WHITE, QUEEN, 7, 3),
                new Piece(WHITE, KING, 7, 4),
                new Piece(WHITE, BISHOP, 7, 5),
                new Piece(WHITE, KNIGHT, 7, 6),
                new Piece(WHITE, ROOK, 7, 7),
            };

            this->rows[0] = new Row(row_1, 1);
            this->rows[1] = new Row(row_2, 2);
            this->rows[2] = new Row(row_3, 3);
            this->rows[3] = new Row(row_4, 4);
            this->rows[4] = new Row(row_5, 5);
            this->rows[5] = new Row(row_6, 6);
            this->rows[6] = new Row(row_7, 7);
            this->rows[7] = new Row(row_8, 8);
        }

        void print()
        {
            clrscr();
            this->print_columns();

            for (auto i = 0; i < SIZE; i++)
                this->rows[i]->print();

            this->print_columns();
            cout << endl;
        }

        Piece *get_piece(char column, int row)
        {
            int col = this->column_to_int(column);
            return this->rows[row - 1]->pieces[col];
        }

        void move(Piece *piece, char column, int row)
        {
            auto col = this->column_to_int(column);

            if (this->validate_move(piece, col, row))
            {
                this->rows[piece->row]->pieces[piece->col] = new Piece(TRANSPARENT, EMPTY, piece->row, piece->col);
                this->rows[row - 1]->pieces[col] = piece;
                piece->col = col;
                piece->row = row - 1;
            }
        }

        /**
         * @brief Validates the desired move
         *
         * @param piece The piece to be moved
         * @param column The target column
         * @param row The target row
         * @return true
         * @return false
         */
        bool validate_move(Piece *piece, char column, int row)
        {
            // auto col = this->column_to_int(column);

            switch (piece->type)
            {
            case PAWN:
            {
                if (piece->color == WHITE)
                {
                    if (piece->row == 6)
                    {
                        if (row - 1 == piece->row - 2 || row - 1 == piece->row - 1)
                            return true;
                    }
                    else if (row - 1 == piece->row - 1)
                        return true;
                }
                else
                {
                    if (piece->row == 1)
                    {
                        if (row == piece->row + 2 || row == piece->row + 1)
                            return true;
                    }
                    else if (row == piece->row + 1)
                    {
                        return true;
                    }
                }
                break;

            default:
                return false;
            }
            }

            return false;
        }

    private:
        void print_columns()
        {
            cout << "    a  b  c  d  e  f  g  h" << endl;
        }

        int column_to_int(char column)
        {
            return column - 'a';
        }
    };

}

using namespace chess;

int main()
{
    Board *board = new Board();

    do
    {
        board->print();

        char column;
        int row;

        cout << "Select a piece: ";
        cin >> column >> row;

        Piece *piece = board->get_piece(column, row);

        cout << "Move to: ";
        cin >> column >> row;

        board->move(piece, column, row);
    } while (true);
}
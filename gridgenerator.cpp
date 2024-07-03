#include "GridGenerator.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

GridGenerator::GridGenerator()
{
    std::srand(std::time(nullptr));
    m_board.resize(14, std::vector<char>(14, 'e'));

    placeSpecialTiles();
}

std::vector<std::vector<char>> GridGenerator::getBoard() const
{
    return m_board;
}

void GridGenerator::displayBoard() const
{
    for (const auto& row : m_board) {
        for (char tile : row) {
            std::cout << tile << ' ';
        }
        std::cout << '\n';
    }
}

void GridGenerator::placeSpecialTiles()
{
    for (int i = 0; i < 20; ++i) {
        placeRandomTile('U', m_start);
    }

    placeRandomTile('S', m_start);

    placeRandomTile('T', m_target);
}

void GridGenerator::placeRandomTile(char tileType, std::pair<int, int>& tilePos)
{
    int row, col;
    do {
        row = std::rand() % 14;
        col = std::rand() % 14;
    } while (m_board[row][col] != 'e');

    m_board[row][col] = tileType;
    tilePos = {row, col};
}

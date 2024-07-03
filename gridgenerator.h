#ifndef GRIDGENERATOR_H
#define GRIDGENERATOR_H

#include <vector>
#include <utility>

class GridGenerator {
public:
    GridGenerator();
    std::vector<std::vector<char>> getBoard() const;
    void displayBoard() const;
private:
    void placeSpecialTiles();
    void placeRandomTile(char tileType, std::pair<int, int>& tilePos);
private:
    std::vector<std::vector<char>> m_board;
    std::pair<int, int> m_start;
    std::pair<int, int> m_target;
};

#endif // GRIDGENERATOR_H

#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <vector>
#include <utility>

class PathFinder {
public:
    PathFinder(const std::vector<std::vector<char>>& board);
    bool findShortestPath();
    void displayPath() const;
private:
    bool isValid(int row, int col) const;
    void tracePath();
private:
    std::vector<std::vector<char>> m_board;
    std::pair<int, int> m_start;
    std::pair<int, int> m_target;
    std::vector<std::vector<std::pair<int, int>>> m_parent;
};

#endif // PATHFINDER_H

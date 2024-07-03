#include "PathFinder.h"

#include <iostream>

#include "queue.h"

PathFinder::PathFinder(const std::vector<std::vector<char>>& board) : m_board(board) {
    for (int row = 0; row < 14; ++row) {
        for (int col = 0; col < 14; ++col) {
            if (board[row][col] == 'S') {
                m_start = {row, col};
            } else if (board[row][col] == 'T') {
                m_target = {row, col};
            }
        }
    }
    m_parent.resize(14, std::vector<std::pair<int, int>>(14, {-1, -1}));
}

bool PathFinder::isValid(int row, int col) const {
    return (row >= 0 && row < 14 && col >= 0 && col < 14 && m_board[row][col] != 'U');
}

bool PathFinder::findShortestPath()
{
    Queue<std::pair<int, int>> q;
    q.enqueue(m_start);
    std::vector<std::vector<bool>> visited(14, std::vector<bool>(14, false));
    visited[m_start.first][m_start.second] = true;

    const std::vector<std::pair<int, int>> directions = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1} // yukarı, aşağı, sol, sağ
    };

    while (!q.isEmpty())
    {
        auto [currentRow, currentCol] = q.dequeue();

        if (currentRow == m_target.first && currentCol == m_target.second) {
            tracePath();
            return true;
        }

        for (const auto& [dRow, dCol] : directions) {
            int newRow = currentRow + dRow;
            int newCol = currentCol + dCol;

            if (isValid(newRow, newCol) && !visited[newRow][newCol]) {
                q.enqueue({newRow, newCol});
                visited[newRow][newCol] = true;
                m_parent[newRow][newCol] = {currentRow, currentCol};
            }
        }
    }
    return false;
}

void PathFinder::tracePath() {
    std::pair<int, int> current = m_target;
    while (current != m_start) {
        m_board[current.first][current.second] = 'W';
        current = m_parent[current.first][current.second];
    }
    m_board[m_start.first][m_start.second] = 'S';
    m_board[m_target.first][m_target.second] = 'T';
}

void PathFinder::displayPath() const {
    for (const auto& row : m_board) {
        for (char tile : row) {
            std::cout << tile << ' ';
        }
        std::cout << '\n';
    }
}

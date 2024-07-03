#include <iostream>

#include "queue.h"
#include "GridGenerator.h"
#include "PathFinder.h"

using namespace std;

int main()
{
    Queue<int>* queue = new Queue<int>;

    for (int i = 0; i < 25; i++)
    {
        queue->enqueue(i*15);
    }

    int size = queue->size();
    for (int i = 0; i < size ; i++)
    {
         cout << queue->dequeue() << endl;
    }

    GridGenerator gg;
    gg.displayBoard();

    std::vector<std::vector<char>> board = gg.getBoard();
    PathFinder pf(board);

    if (pf.findShortestPath()) {
        std::cout << "\nFound a path:\n";
        pf.displayPath();
    } else {
        std::cout << "\nNo path found.\n";
    }

    return 0;
}

//#include <iostream>
//#include"Maze.h"
//using namespace std;
//int main()
//{
//    cout << "---------------------------" << endl;
//    cout << "Following are the letters for movement : " << endl;
//    cout << "W                   For Up " << endl;
//    cout << "A                   For Left " << endl;
//    cout << "D                   For Right " << endl;
//    cout << "S                   For Down " << endl;
//    cout << "---------------------------" << endl;
//    cout << "---------------------------" << endl;
//    cout << "The number 1 shows the position : " << endl;
//    cout << "---------------------------" << endl;
//    char** maze = new char* [rows];
//    for (int i = 0; i < rows; i++) {
//        maze[i] = new char[cols];
//    }
//    Maze(maze);
//    printMaze(maze);
//    movement(maze);
//    for (int i = 0; i < rows; ++i)
//    {
//        delete[]maze[i];
//    }
//    delete[]maze;
//    maze=nullptr;
//}
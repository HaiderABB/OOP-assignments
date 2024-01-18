//#pragma once
//#include<iostream>
//#include <cstdlib>
//#include <ctime>
//using namespace std;
//const int rows = 10;
//const int cols = 10;
//void Maze(char** maze) {
//	srand(time(0));
//	for (int i = 0; i < rows; i++) {
//		for (int j = 0; j < cols; j++) {
//			int num = rand() % 4;
//			if (num == 0) {
//				maze[i][j] = '#';
//			}
//			else {
//				maze[i][j] = ' ';
//			}
//		}
//	}
//	maze[0][0] = 'S';
//	maze[rows - 1][cols - 1] = 'E';
//
//}
////Function for printing the maze
//void printMaze(char** maze)
//{
//	for (int i = 0; i < rows; i++) {
//		for (int j = 0; j < cols; j++) {
//			cout << maze[i][j] << " ";
//		}
//		cout << endl;
//	}
//}
////Function for Movement
//void movement(char** maze)
//{
//	int r = 0, c = 0;
//	bool check = true;
//	char move;
//	int moveCount = 0;
//	while (check)
//	{
//		cout << "Enter the character for movement : " << endl;
//		cin >> move;
//		if (move == 'W' && (r == 0 && c == 0))
//		{
//			while (move == 'A' || move == 'W')
//			{
//				cout << "Enter the correct movement : " << endl;
//				cin >> move;
//			}
//		}
//		else if (move == 'A' && (r == 0 && c == 0))
//		{
//			while (move == 'A' || move == 'W')
//			{
//				cout << "Enter the correct movement : " << endl;
//				cin >> move;
//			}
//		}
//		else {
//			if (move == 'W' && maze[r - 1][c] != '#')
//			{
//				maze[r][c] = ' ';
//				r = r - 1;
//				maze[r][c] = '*';
//				++moveCount;
//				printMaze(maze);
//			}
//			else if (move == 'A' && maze[r][c - 1] != '#')
//			{
//				maze[r][c] = ' ';
//				c = c - 1;
//				maze[r][c] = '*';
//				++moveCount;
//				printMaze(maze);
//			}
//			else if (move == 'S' && maze[r + 1][c] != '#')
//			{
//				maze[r][c] = ' ';
//				r = r + 1;
//				maze[r][c] = '*';
//				++moveCount;
//				printMaze(maze);
//			}
//			else if (move == 'D' && maze[r][c + 1] != '#')
//			{
//				maze[r][c] = ' ';
//				c = c + 1;
//				maze[r][c] = '*';
//				++moveCount;
//				printMaze(maze);
//			}
//			else {
//				cout << "Enter correct option : " << endl;
//			}
//			if (r == rows - 1 && c == cols - 1)
//			{
//				check = false;
//			}
//		}
//	}
//	cout << "You won the game in " << moveCount << " moves\n";
//}
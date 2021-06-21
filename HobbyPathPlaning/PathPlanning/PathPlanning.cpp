#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

/* Map to map the coordinates to the grid value*/
std::map<std::vector<int>, char> GridPts;

/*Flag to be set when the goal node is reached*/
bool ReachFlag { false };

/**
 * Function to parse the text file containing the grid
 *
 */
void ParseFile()
{
    std::ifstream in_file;
    std::string line;
    char c;
    int x { 0 };
    int y { 0 };
    std::vector<int> coords;
    in_file.open("E://MOOC//Udacity//Nanodegree//Codes//CPP//HobbyPathPlaning//PathPlanning//Grid.txt");
    if(!in_file) {
        std::cerr << "Problem opening file" << std::endl;
    }
    while(std::getline(in_file, line)) {
        std::istringstream sline(line);
        while(sline >> c) {
            coords.push_back(x);
            coords.push_back(y);
            GridPts[coords] = c;
            y++;
            coords.clear();
        }
        y = 0;
        x++;
    }
}

/**
 * Function to recursively search for the goal node
 *
 */

void PathFinder(int x, int y, int GridSize)
{
    std::vector<int> temp;
    temp.push_back(x);
    temp.push_back(y);
    if(GridPts[temp] == 'G') {
        GridPts[temp] = 'R';
        ReachFlag = true;
    }

    if((x < GridSize) && (y < GridSize) && !(ReachFlag) && (GridPts[temp] != '*')) {

        if((x > 0) || (y > 0)) {
            GridPts[temp] = '1';
        }

        PathFinder(x, y + 1, GridSize);

        PathFinder(x + 1, y, GridSize);
    }
}

/**
 * Function to print the result grid to the console.
 *
 */
void PrintPath(int GridSize)
{
    std::vector<int> temp;
    for(int i = 0; i < GridSize; i++) {
        for(int j = 0; j < GridSize; j++) {
            temp.push_back(i);
            temp.push_back(j);
            std::cout << GridPts[temp];
            std::cout << '\t';
            temp.clear();
        }
        std::cout << std::endl;
    }
}

int main()
{
    int start[2] { 0, 0 };
    int GridSize {};
    ParseFile();
    GridSize = sqrt(GridPts.size());
    PathFinder(start[0], start[1], GridSize);
    PrintPath(GridSize);
    return 0;
}

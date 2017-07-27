#include <stdlib.h>
#include "MySolver.h"
#include <exception>
using namespace std;

bool MySolver::SolveMaze(int xpos, int ypos)
{
    
    if (GetCell(xpos, ypos)== 'E')
        return true;
    MarkCell(true, xpos, ypos);
    
    //search up
    if (CanMoveTo(xpos, ypos-1)) {
        if (SolveMaze(xpos, ypos-1))
            return true;
    }
    //search right
    if (CanMoveTo(xpos+1, ypos)) {
        if (SolveMaze(xpos+1, ypos))
            return true;
    }
    //search down
    if (CanMoveTo(xpos, ypos+1)) {
        if (SolveMaze(xpos, ypos+1))
            return true;
    }
    //serach left
    if (CanMoveTo(xpos-1, ypos)) {
        if (SolveMaze(xpos-1, ypos))
            return true;
    }
    //wasn't found, will backtrack
    MarkCell(false, xpos, ypos);
    
    
    return 0;
}

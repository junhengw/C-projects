//////////////////////////////////////////////////////////////////////////////
// CSC A48 - Winter 2020 - Exercise 5.
//
// Please have a look at the Quercus description of the problem, *before* you
// attempt to implement anything here!
//
// Starter code: (c) 2020 William Song & Joe Armitage.
//////////////////////////////////////////////////////////////////////////////

#include <stdbool.h>            // Note this is needed to use the bool type
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TISSUE_SIZE (10)

// We are going to take advantage of the 'typedef' keyword - it can be used to make
// a nickname for any data type, not just compound data types as we have been doing
// in lecture. For this exercise, we're going to be dealing with 2D arrays that contain
// different symbols, we will create a convenient nickname for these 2D arrays.
// The typedef below creates an alias 'Tissue' for a char array of size [TISSUE_SIZE][TISSUE_SIZE].
// Thereafter, we can do this:
//
//   Tissue  one_tissue;
//
// and this is equivalent to:
//
//   char one_tissue[TISSUE_SIZE][TISSUE_SIZE];
//
typedef char Tissue[TISSUE_SIZE][TISSUE_SIZE];  // The syntax is kind of funky, but that's just a
                                                // quirk of C, nothing to worry yourself about :)

/**
 * Return true iff there exists a Leo coli within tissue_sample that can attack position x, y.
 *
 * Legal moves are limited to the pattern (where X is a legal move and L is the bacterium):
 *      X _ X _ X
 *      _ _ _ _ _
 *      X _ L _ X
 *      _ _ _ _ _
 *      X _ X _ X
 *
 * INPUT:
 *  tissue_sample:
 *      - an array of arrays of characters with dimensions TISSUE_SIZE * TISSUE_SIZE
 *      - gives positions of each bacterium and each infected cell
 *      - each cell can only contain one of the following types:
 *          - `I`: Infected Cell
 *          - `L`: A Leo coli bacterium
 *          - `W`: A Willmonella bacterium
 *          - `_`: An uninfected cell (bacteria will ignore these)
 *  x:  the row coordinate (starting at 0) of the cell (within tissue_sample) to be checked.
 *  y:  the column coordinate (starting at 0) of the cell (within tissue_sample) to be checked.
 *
 * RETURN:
 *  true, if there exists some Leo coli that can make a legal move to position x, y
 *  false, if no Leo coli can make a legal move to position x, y
 */

bool canLeoEat(Tissue tissue_sample, int x, int y)
{
    /** TODO: implement this function, satisfying the description above. */
    
    if(y+2 < TISSUE_SIZE && x+2 < TISSUE_SIZE){
        if((tissue_sample[(x+2)][y+2])=='L'){
            return true;
        }
    }
    
    if(y+2 < TISSUE_SIZE && x-2 >= 0){
        if((tissue_sample[(x-2)][y+2])=='L'){
            return true;
        }
    }
    
    if(x+2 < TISSUE_SIZE && y-2 >= 0){
        if((tissue_sample[(x+2)][y-2])=='L'){
            return true;
        }
    }
    
    if(x-2 >= 0 && y-2 >= 0){
        if((tissue_sample[(x-2)][y-2])=='L'){
            return true;
        }
    }
    
    
    if(x-2 >= 0){
        if(tissue_sample[(x-2)][y]=='L'){
            return true;
        }
    }
    
    if(x+2 <TISSUE_SIZE){
        if(tissue_sample[(x+2)][y]=='L'){
            return true;
        }
    }
    
    if(y-2 >= 0){
        if(tissue_sample[x][y-2]=='L'){
            return true;
        }
    }
    
    if(y+2 < TISSUE_SIZE){
        if((tissue_sample[(x)][y+2])=='L'){
            return true;
        }
    }
    
    return false;   // <- Evidently your function should not always return false!
}

/**
 * Return true iff there exists a Willmonella within tissue_sample that can attack position x, y.
 *
 * Legal moves are limited to the pattern (where X is a legal move and W is the bacterium):
 *      _ _ X X X _ _
 *      _ _ _ X _ _ _
 *      X _ _ X _ _ X
 *      X X X W X X X
 *      X _ _ X _ _ X
 *      _ _ _ X _ _ _
 *      _ _ X X X _ _
 *
 * INPUT:
 *  tissue_sample:
 *      - an array of arrays of characters with dimensions TISSUE_SIZE * TISSUE_SIZE
 *      - gives positions of each bacterium and each infected cell
 *      - each cell can only contain one of the following types:
 *          - `I`: Infected Cell
 *          - `L`: A Leo coli bacterium
 *          - `W`: A Willmonella bacterium
 *          - `_`: An uninfected cell (bacteria will ignore these)
 *  x:  the row coordinate (starting at 0) of the cell (within tissue_sample) to be checked.
 *  y:  the column coordinate (starting at 0) of the cell (within tissue_sample) to be checked.
 *
 * RETURN:
 *  true, if there exists some Willmonella that can make a legal move to position x, y
 *  false, if no Willmonella can make a legal move to position x, y
 */
bool canWillEat(Tissue tissue_sample, int x, int y)
{
    /** TODO: implement this function, satisfying the description above. */
if(x-2 >= 0){
    if(tissue_sample[(x-2)][y]=='W'){return true;}}
if(x+2 <TISSUE_SIZE){
    if(tissue_sample[x+2][y]=='W'){return true;}}
if(y-2 >= 0){
    if(tissue_sample[x][y-2]=='W'){return true;}}
if(y+2 < TISSUE_SIZE){
    if((tissue_sample[(x)][y+2])=='W'){return true;}}
if(x-1 >= 0){
    if(tissue_sample[(x-1)][y]=='W'){return true;}}
if(x+1 < TISSUE_SIZE){
    if(tissue_sample[x+1][y]=='W'){return true;}}
if(y-1 >= 0){
    if(tissue_sample[x][y-1]=='W'){return true;}}
if(y+1 < TISSUE_SIZE){
    if((tissue_sample[(x)][y+1])=='W'){return true;}}
if(x-3 >= 0){
    if(tissue_sample[(x-3)][y]=='W'){return true;}}
if(x+3 < TISSUE_SIZE){
    if(tissue_sample[x+3][y]=='W'){return true;}}
if(y-3 >= 0){
    if(tissue_sample[x][y-3]=='W'){return true;}}
if(y+3 < TISSUE_SIZE){
    if((tissue_sample[(x)][y+3])=='W'){return true;}}
if(x+3 < TISSUE_SIZE && y+1 < TISSUE_SIZE){
    if(tissue_sample[x+3][y+1]=='W'){return true;}}
if(x+3 < TISSUE_SIZE && y-1 >= 0){
    if(tissue_sample[x+3][y-1]=='W'){return true;}}
if(y+1 < TISSUE_SIZE && x-3 >= 0){
    if(tissue_sample[x-3][y+1]=='W'){return true;}}
if(y-1 >= 0 && x-3 >= 0){
    if(tissue_sample[x-3][y-1]=='W'){return true;}}
if(y+3 < TISSUE_SIZE && x+1 < TISSUE_SIZE){
    if(tissue_sample[x+1][y+3]=='W'){return true;}}
if(x+1 < TISSUE_SIZE && y-3 >= 0){
    if(tissue_sample[x+1][y-3]=='W'){return true;}}
if(y+3 < TISSUE_SIZE && x-1 >= 0){
    if(tissue_sample[x-1][y+3]=='W'){return true;}}
if(x-1 < TISSUE_SIZE && y-3 >= 0){
    if(tissue_sample[x-1][y-3]=='W'){return true;}}

    return false;   // <- This function will not always return false once implemented!
}

/**
 * Computes the percentage of infected cells in the given tissue sample which can be killed
 * in a single move by one of the Willmonella or Leo coli bacteria in the sample.
 *
 * INPUT:
 *  tissue_sample:
 *      - an array of arrays of characters with dimensions TISSUE_SIZE * TISSUE_SIZE
 *      - gives positions of each bacterium and each infected cell
 *      - each cell can only contain one of the following types:
 *          - `I`: Infected Cell
 *          - `L`: A Leo coli bacterium
 *          - `W`: A Willmonella bacterium
 *          - `_`: An uninfected cell (bacteria will ignore these)
 *
 * RETURN:
 *  The (rounded to nearest integer) percentage of bacteria on the board that are within
 *  the reach of one of the "good bacteria" (Will or Leo).
 */
int percentKilled(Tissue tissue_sample)
{
    int kill_percent=0;
    int infected=0;
    int num_W=0;
    int num_L=0;
    /**
     * TODO: Implement this function, satisfying the description above.
     *
     * CRUNCHY: Can you do this without using a loop in a loop?
     *              -> Think about how this 2D array is stored in memory...
     */
    
    for(int i=0;i<TISSUE_SIZE;i++){
        for(int j=0;j<TISSUE_SIZE;j++){
            if(tissue_sample[i][j]=='I'){infected++;}
            if(tissue_sample[i][j]=='I'){
                if(canWillEat(tissue_sample,i,j)==true)    { num_W++;}
                else if(canLeoEat(tissue_sample,i,j)==true){num_L++;}
                
            }
            
        }
        
    }

    kill_percent= round((((float)num_W+(float)num_L)/(float)infected)*100);
    return kill_percent;   // <-- This should return the percentage (integer in 0-100)
                //     of infected cells killed by the bacteria.
}

/**
 * Prints the tissue sample in a human readable format.
 *
 * INPUT:
 *  tissue_sample:
 *      - an array of arrays of characters with dimensions TISSUE_SIZE * TISSUE_SIZE
 *      - gives positions of each bacterium and each infected cell
 *      - each cell can only contain one of the following types:
 *          - `I`: Infected Cell
 *          - `L`: A Leo coli bacterium
 *          - `W`: A Willmonella bacterium
 *          - `_`: An uninfected cell (bacteria will ignore these)
 *
 * NOTE: The displayed indices do not match the implementation.
 * That is, they start at 1 (when we know array indices start at 0).
 * This is more obvious for the column indices, which are A - J.
 */
void printTissueSample(Tissue tissue_sample)
{
    printf("   A B C D E F G H I J\n");
    for (int x = 0; x < TISSUE_SIZE; x++)
    {
        printf("%2d ", x + 1);
        for (int y = 0; y < TISSUE_SIZE; y++) printf("%c ", tissue_sample[x][y]);
        printf("\n");
    }
}

// We NEED this compiler directive to test your code with our own main(). Don't break it.
#ifndef __TESTING  // this compiler directive
int main()
{
    // Please note that these are JUST EXAMPLES! You will be tested on a wide range of data.
    printf("====Deep's Sample====\n");
    Tissue deep_sample = {{'_', '_', '_', '_', '_', '_', '_', '_', '_', '_'},
                          {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_'},
                          {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_'},
                          {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_'},
                          {'_', '_', '_', '_', 'L', '_', 'I', '_', '_', '_'},
                          {'_', '_', '_', '_', 'I', '_', '_', '_', '_', '_'},
                          {'_', '_', '_', '_', 'I', '_', '_', '_', '_', '_'},
                          {'_', '_', '_', 'W', '_', '_', '_', '_', '_', '_'},
                          {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_'},
                          {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_'}};
    printTissueSample(deep_sample);
    printf("Calculated: Killed %03d%% of bacteria\n", percentKilled(deep_sample));
    printf("  Expected: Killed 067%% of bacteria\n");

    // Feel free to add your own examples/tests here
    printf("====Donnie's Sample====\n");

    // To illustrate the utility of the typedef above, let's see how we'd create a tissue sample
    // just as an array of chars. It will look like a different type to us, but the compiler
    // knows its the same because the typedef at the top says it's the same thing.
    // I.E. A char[TISSUE_SIZE][TISSUE_SIZE] is a Tissue, according to C
    char donnie_sample[TISSUE_SIZE][TISSUE_SIZE] = {
        {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_', 'I', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_', '_', '_', '_', '_', 'W'},
        {'_', '_', '_', 'I', '_', '_', '_', '_', '_', '_'},
        {'_', '_', '_', 'L', '_', '_', '_', '_', 'L', '_'},
        {'_', '_', '_', 'I', '_', '_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_'}};
    printTissueSample(donnie_sample);
    printf("Calculated: Killed %03d%% of bacteria\n", percentKilled(donnie_sample));
    printf("  Expected: Killed 064%% of bacteria\n");
}
#endif  // and this compiler directive

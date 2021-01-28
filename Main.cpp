#include<iostream>
#include <ctime>
#include "Backtracking.h"
#include "Backtracking2.h"
#include "ConstraintPropogation.h"
#include "BFS .h"
#include "Knuth .h"

using namespace std;

int main(){

cout << "-------------------------------------------------------"<<endl;
cout << "                       CSE2003                         "<<endl;
cout << "-------------------------------------------------------"<<endl;


cout << "Welcome to the Sudoku solver implementation Project"<<endl;

int choice  = -1;

   int grid[N][N] = { { 3, 1, 6, 5, 7, 8, 4, 9, 2 },
                       { 5, 2, 9, 1, 3, 4, 7, 6, 8 },
                       { 4, 8, 7, 6, 2, 9, 5, 3, 1 },
                       { 2, 6, 3, 0, 1, 5, 9, 8, 7 },
                       { 9, 7, 4, 8, 6, 0, 1, 2, 5 },
                       { 8, 5, 1, 7, 9, 2, 6, 4, 3 },
                       { 1, 3, 8, 0, 4, 7, 2, 0, 6 },
                       { 6, 9, 2, 3, 5, 1, 8, 7, 4 },
                       { 7, 4, 5, 0, 8, 6, 3, 1, 0 } };;



    clock_t start, end; 
    start = clock();
    end = clock();


    choice = -1;

    while(choice < 8 && choice != '*')
    {
        cout << "\n\n\n";
        cout<<"----------------------Menu-----------------------------"<<endl;
        cout<<"1. Backtracking.\n";
        cout<<"2. Backtracking (Recursion)\n";
        cout<<"3. Contraint Propagation.\n";
        cout<<"4. Brute Force Search,\n";
        cout<<"5. Knuth's.\n";
        cout<<"6. Exit.\n\n";

        cout<<"To change the puzzle to your desired input press '0' \n";
        cout<<"To run the automated tests on 5 sudoku puzzles press '7'"<<endl;        

        cin >> choice;

        switch (choice)
        {
        case 1:
            start = clock();
            Solve(grid);
            end = clock();
            cout << "\nThe time taken to execute the code backtracking without recursion is "<< (end - start)  << " ms" << endl;
            break;
        case 2:
            Solve2(grid);
            break;
        case 3:
            start = clock(); 
            ConstraintProagation(grid);
            end = clock(); 
            cout << "\nThe time taken to execute the code Constraint Propagation is "<< (end - start) << " ms" << endl;
            cout<< "\n\n";
            break;
        case 4:
            start = clock(); 
            DoBruteForce(grid);
            end = clock();
            cout << "The time taken to execute the code Brute Force Search is "<< (end - start) << " ms" << endl; 
            
            break;

        case 5:
            SolveKnuth(grid);
            break;

        case 0 :

            cout << "\n\nPLease input your sudoku puzzle of size 9x9.\n";

            for(int i = 0 ; i < 9 ; i++){
                for(int j = 0 ; j < 9 ; j++){
                    cin >> grid[i][j];
                }
            }

            cout<<"\n\n The Sudoku puzzle entered is:\n";
            for(int i = 0 ; i < 9 ; i++){
                for(int j = 0 ; j < 9 ; j++){
                    cout << grid[i][j] << " ";
                }
                cout << endl;
            }

            break;
        case 7:
            
            cout<<"/////////////////// Automated Tests ///////////////////\n\n";

            int Test[5][N][N] = {

                                    { {0, 0, 0, 0, 1, 5, 0, 7, 4},
                                    {0, 0, 0, 0, 3, 0, 8, 0, 0},
                                    {0, 8, 7, 0, 0, 0, 5, 0, 1},
                                    {0, 2, 3, 0, 0, 4, 0, 0, 0},
                                    {0, 1, 0, 0, 7, 0, 0, 2, 0},
                                    {0, 0, 0, 2, 0, 0, 7, 9, 0},
                                    {8, 0, 6, 0, 0, 0, 2, 4, 0},
                                    {0, 0, 1, 0, 2, 0, 0, 0, 0},
                                    {2, 3, 0, 6, 4, 0, 0, 0, 0} },

                                    { { 5, 3, 0, 0, 7, 0, 0, 0, 0},
                                    {6, 0, 0, 1, 9, 5, 0, 0, 0},
                                    {0, 9, 8, 0, 0, 0, 0, 6, 0},
                                    {8, 0, 0, 0, 6, 0, 0, 0, 3},
                                    {4, 0, 0, 8, 0, 3, 0, 0, 1},
                                    {7, 0, 0, 0, 2, 0, 0, 0, 6},
                                    {0, 6, 0, 0, 0, 0, 2, 8, 0},
                                    {0, 0, 0, 4, 1, 9, 0, 0, 5},
                                    {0, 0, 0, 0, 8, 0, 0, 7, 9} } ,

                                    { {8, 5, 0, 0, 0, 2, 4, 0, 0},
                                    {7, 2, 0, 0, 0, 0, 0, 0, 9},
                                    {0, 0, 4, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 1, 0, 7, 0, 0, 2},
                                    {3, 0, 5, 0, 0, 0, 9, 0, 0},
                                    {0, 4, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 8, 0, 0, 7, 0},
                                    {0, 1, 7, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 3, 6, 0, 4, 0} } ,

                                    { {1, 0, 0, 0, 0, 7, 0, 9, 0},
                                    {0, 3, 0, 0, 2, 0, 0, 0, 8},
                                    {0, 0, 9, 6, 0, 0, 5, 0, 0},
                                    {0, 0, 5, 3, 0, 0, 9, 0, 0},
                                    {0,1, 0, 0, 8, 0, 0, 0, 2},
                                    {6, 0, 0, 0, 0, 4, 0, 0, 0},
                                    {3, 0, 0, 0, 0, 0, 0, 1, 0},
                                    {0, 4, 0, 0, 0, 0, 0, 0, 7},
                                    {0, 0, 7, 0, 0, 0, 3, 0, 0} } ,

                                    { {0, 4, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 2, 0, 3, 0, 0, 1},
                                    {0, 0, 3, 4, 1, 0, 7, 0, 0},
                                    {0, 6, 0, 1, 2, 9, 3, 5, 0},
                                    {0, 0, 9, 7, 0, 8, 4, 0, 0},
                                    {0, 8, 5, 6, 3, 4, 0, 1, 0},
                                    {0, 0, 1, 0, 4, 5, 2, 0, 0},
                                    {7, 0, 0, 8, 0, 2, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 3, 0} }


                                };

            clock_t Time[5];

            for(int i = 0 ; i < 5 ; i++)
            {
                
                for(int j = 0 ; j < N ; j++)
                {

                    for(int k = 0 ; k < N ; k++)
                    {
                        grid[j][k] = Test[i][j][k];
                    }

                }

                start = clock();
                Solve(grid);
                end = clock();
                Time[0] = end - start;

                start = clock();
                Solve2(grid);
                end = clock();
                Time[1] = end - start;

                start = clock();
                ConstraintProagation(grid);
                end = clock();
                Time[2] = end - start;

                start = clock();
                DoBruteForce(grid);
                end = clock();
                Time[3] = end - start;

                start = clock();
                SolveKnuth(grid);
                end = clock();
                Time[4] = end - start;

                cout <<"\n\n\n\n";
                cout << "Time taken for Backtracking for test case " << i << " is: " << Time[0] << " ms" << endl;
                cout << "Time taken for Backtracking using recursion " << i << " is: "<< Time[1] << " ms" << endl;
                cout << "Time taken for Constraint Propagation for test case " << i << " is: "<< Time[2] << " ms" << endl;
                cout << "Time taken for Brute Force Search for test case " << i << " is: " << Time[3] << " ms" << endl;
                cout << "Time taken for Knuth for test case " << i << " is: " << Time[4] << " ms" << endl;

            }

        }

    }
    

    
    
     





/*

Test cases being used for this project 

Test[N][N][5] = {

{ {0, 0, 0, 0, 1, 5, 0, 7, 4},
{0, 0, 0, 0, 3, 0, 8, 0, 0},
{0, 8, 7, 0, 0, 0, 5, 0, 1},
{0, 2, 3, 0, 0, 4, 0, 0, 0},
{0, 1, 0, 0, 7, 0, 0, 2, 0},
{0, 0, 0, 2, 0, 0, 7, 9, 0},
{8, 0, 6, 0, 0, 0, 2, 4, 0},
{0, 0, 1, 0, 2, 0, 0, 0, 0},
{2, 3, 0, 6, 4, 0, 0, 0, 0} },

{ { 5, 3, 0, 0, 7, 0, 0, 0, 0},
{6, 0, 0, 1, 9, 5, 0, 0, 0},
{0, 9, 8, 0, 0, 0, 0, 6, 0},
{8, 0, 0, 0, 6, 0, 0, 0, 3},
{4, 0, 0, 8, 0, 3, 0, 0, 1},
{7, 0, 0, 0, 2, 0, 0, 0, 6},
{0, 6, 0, 0, 0, 0, 2, 8, 0},
{0, 0, 0, 4, 1, 9, 0, 0, 5},
{0, 0, 0, 0, 8, 0, 0, 7, 9} } ,

{ {8, 5, 0, 0, 0, 2, 4, 0, 0},
{7, 2, 0, 0, 0, 0, 0, 0, 9},
{0, 0, 4, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 1, 0, 7, 0, 0, 2},
{3, 0, 5, 0, 0, 0, 9, 0, 0},
{0, 4, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 8, 0, 0, 7, 0},
{0, 1, 7, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 3, 6, 0, 4, 0} } ,

{ {1, 0, 0, 0, 0, 7, 0, 9, 0},
{0, 3, 0, 0, 2, 0, 0, 0, 8},
{0, 0, 9, 6, 0, 0, 5, 0, 0},
{0, 0, 5, 3, 0, 0, 9, 0, 0},
{0,1, 0, 0, 8, 0, 0, 0, 2},
{6, 0, 0, 0, 0, 4, 0, 0, 0},
{3, 0, 0, 0, 0, 0, 0, 1, 0},
{0, 4, 0, 0, 0, 0, 0, 0, 7},
{0, 0, 7, 0, 0, 0, 3, 0, 0} } ,

{ {0, 4, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 2, 0, 3, 0, 0, 1},
{0, 0, 3, 4, 1, 0, 7, 0, 0},
{0, 6, 0, 1, 2, 9, 3, 5, 0},
{0, 0, 9, 7, 0, 8, 4, 0, 0},
{0, 8, 5, 6, 3, 4, 0, 1, 0},
{0, 0, 1, 0, 4, 5, 2, 0, 0},
{7, 0, 0, 8, 0, 2, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 3, 0} }


};






*/




}

































/*

SUPER SECRET DEV NOTE ;)

This code was all written by me Aashish Sharma 19BCE0971 
And I dont think anyone will know about this :(

*/
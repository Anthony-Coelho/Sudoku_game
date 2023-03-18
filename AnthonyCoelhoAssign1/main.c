//Name: Anthony Coelho
//Date: January 21, 2023,
//This code tests the grids of the testGrid and the grid of the user and makes sure they are valid Sudoku grids then displays them. the user will be prompted to enter
//a row in the grid, that row will be checked to see if its valid, the user will be prompted again if the input is incorrect

//here are all the #includes that I used throughout the program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
//creates the function "print" which will print "testGrid", and "uGrid"
void print(int arr[9][9]) {
    for (int a = 0; a < 9; a++) {
        for (int c = 0; c < 9; c++)
            printf("%d   ",arr[a][c]);
        printf("\n");
    }
}
//creates the function "randomness" which will be used to create random arrays that will be used in "uGrid", this function also makes sure the array does not have any duplicates
void randomness (int array[], int length, int min, int max) {
    for (int i = 0; i < length; i++) {
        int new;
        bool unique;
        do {
            new = rand() % (max - min + 1) + min;
            unique = true;
            for (int j = 0; j < i; j++) {
                if (array[j] == new) {
                    unique = false;
                }
            }
        } while (!unique);
        array[i] = new;

    }
}
int main()
{
//srand will seed the randomly generated arrays so the numbers will be different on each run of the program
    srand ( time(NULL) *getpid() );

    //the user arrays will be stored here
    int uArray1 [9];
    int uArray2 [9];
    //the randomly generated arrays will be stored here, as well of the function "randomness" to randomize the array and ensure there is no duplicates
    int array3[9];
    randomness(array3, 9, 1, 9);
    int array4[9];
    randomness(array4, 9, 1, 9);
    int array5[9];
    randomness(array5, 9, 1, 9);
    int array6[9];
    randomness(array6, 9, 1, 9);
    int array7[9];
    randomness(array7, 9, 1, 9);
    int array8[9];
    randomness(array8, 9, 1, 9);
    int array9[9];
    randomness(array9, 9, 1, 9);

    //here are the different variables that will be used later in the program
    int dup;
    int count;
    int pass = 0;
    bool isValid = true;
    bool isValid2 = true;
//test grid, this is an example to show the user in the program
    int testGrid[ 9 ][ 9 ] = {{5,3,4,6,7,8,9,1,2},
                              {6,7,2,1,9,5,3,4,8},
                              {1,9,8,3,4,2,5,6,7},
                              {8,5,9,7,6,1,4,2,3},
                              {4,2,6,8,5,3,7,9,1},
                              {7,1,3,9,2,4,8,5,6},
                              {9,6,1,5,3,7,2,8,4},
                              {2,8,7,4,1,9,6,3,5},
                              {3,4,5,2,8,6,1,7,9}};

    //here are the validation tests for "testGrid" each if statement will iterate through a different column of the grid and check for duplicates, if anyone of them has a duplicate "isValid" will be set to false
    for (int i=0;i<9;i++) {
        for (int j=i + 1;j < 9;j++) {
            if (testGrid[i][0] == testGrid[j][0]) {
                isValid = false;
            }
        }
    }
    for (int i=0;i<9;i++) {
        for (int j=i + 1;j < 9;j++) {
            if (testGrid[i][1] == testGrid[j][1]) {
                isValid = false;
            }
        }
    }
    for (int i=0;i<9;i++) {
        for (int j=i + 1;j < 9;j++) {
            if (testGrid[i][2] == testGrid[j][2]) {
                isValid = false;
            }
        }
    }
    for (int i=0;i<9;i++) {
        for (int j=i + 1;j < 9;j++) {
            if (testGrid[i][3] == testGrid[j][3]) {
                isValid = false;
            }
        }
    }
    for (int i=0;i<9;i++) {
        for (int j=i + 1;j < 9;j++) {
            if (testGrid[i][4] == testGrid[j][4]) {
                isValid = false;
            }
        }
    }
    for (int i=0;i<9;i++) {
        for (int j=i + 1;j < 9;j++) {
            if (testGrid[i][5] == testGrid[j][5]) {
                isValid = false;
            }
        }
    }
    for (int i=0;i<9;i++) {
        for (int j=i + 1;j < 9;j++) {
            if (testGrid[i][6] == testGrid[j][6]) {
                isValid = false;
            }
        }
    }
    for (int i=0;i<9;i++) {
        for (int j=i + 1;j < 9;j++) {
            if (testGrid[i][7] == testGrid[j][7]) {
                isValid = false;
            }
        }
    }
    for (int i=0;i<9;i++) {
        for (int j=i + 1;j < 9;j++) {
            if (testGrid[i][8] == testGrid[j][8]) {
                isValid = false;
            }
        }
    }
    puts("--------- Sudoku Grid -----------");
    //prints the "testGrid". If there were no duplicates in "testGrid" the grid will be printed with a message saying its valid, if there is duplicates it will print the grid with a message saying it's not valid
    if (isValid == true) {
        print(testGrid);
        puts("Given sudoku grid is valid");
    }
    else {
        print(testGrid);
        printf("!!GIVEN GRID IS NOT VALID!!");
    }
    printf("\n");
    //prompts user to give an input and gives instructions to the user
    puts("-1. Input must be exactly 9 inputs of numbers from 1 - 9"
         "\n-2. All numbers must be distinct "
         "\n-3. You will be notified of invalid inputs, then prompted to repeat the row "
         "\n-4. Each input must be on a different line. Input a number then hit 'ENTER', do this 9 times."
         "\n-5. Repeat '4.' when you get the prompt for row 2");

    //this will prompt the user for row 1 of the grid and will validate the array making sure there are no duplicates and all numbers are in range of 1 - 9.
    //this will code will loop upon an invalid array, it will continually loop until a valid array is given. upon an invalid array being given the user will
    //be shown the errors before being prompted to input values for the row.
    //Each valid and invalid array will be printed so the user can have a more clear view of their inputs
    while(pass != 324) {
        dup = 0;
        count = sizeof(uArray1) / sizeof(uArray1[0]);
        pass = 0;
        puts("\nEnter the first row of your sudoku");
        for (int y = 0; y < 9; y++) {
            scanf("%d", &uArray1[y]);
        }
        for (int y = 0; y < 9; ++y) {
            printf("%d ", uArray1[y]);
        }
        for (int y = 0; y < 9; ++y) {
            if(uArray1[y] > 9 || uArray1[y] < 1) {
                if (uArray1[y] > 9) {
                    printf("\nInput %d is too high. Must be 9 or below", uArray1[y]);
                } else if (uArray1[y] < 1) {
                    printf("\nInput %d is too low. Must be 1 or higher", uArray1[y]);
                }

            }
            else if(y != 99) {
                for (int i = 0; i < count - 1; i++) {
                    for (int j = i + 1; j < count; j++) {
                        if (uArray1[i] == uArray1[j]) {
                            dup ++;
                        }
                        else if (uArray1[i] != uArray1[j]) {
                            pass++;
                        }
                    }
                }
            }
        }
        if (dup != 0){
            printf("\nDuplicate Detected");
        }
    }
    //"pass" will be reset and the process will start again with the program asking the user for an array for the second row of the grid
    pass = 0;
    while(pass != 324) {
        dup = 0;
        count = sizeof(uArray2) / sizeof(uArray2[0]);
        pass = 0;
        puts("\nEnter the second row of your sudoku");
        for (int y = 0; y < 9; ++y) {
            scanf("%d", &uArray2[y]);
        }
        for (int y = 0; y < 9; ++y) {
            printf("%d ", uArray2[y]);
        }
        for (int y = 0; y < 9; ++y) {
            if(uArray2[y] > 9 || uArray2[y] < 1) {
                if (uArray2[y] > 9) {
                    printf("\nInput %d is too high. Must be 9 or below", uArray2[y]);
                } else if (uArray2[y] < 1) {
                    printf("\nInput %d is too low. Must be 1 or higher", uArray2[y]);
                }

            }
            else if(y!= 99) {
                for (int i = 0; i < count - 1; i++) {
                    for (int j = i + 1; j < count; j++) {
                        if (uArray2[i] == uArray2[j]) {
                            dup ++;
                        }
                        else if (uArray2[i] != uArray2[j]) {
                            pass++;
                        }
                    }
                }
            }
        }
        if (dup != 0){
            printf("\nDuplicate Detected");
        }
    }
    //with the user inputs for "uArray1" and "uArray2" along with the randomized arrays, they are all placed into "uGrid" and will be tested for validation
    int uGrid [ 9 ][ 9 ] = {{uArray1[0], uArray1[1], uArray1[2], uArray1[3], uArray1[4], uArray1[5], uArray1[6], uArray1[7], uArray1[8]},
                            {uArray2[0], uArray2[1], uArray2[2], uArray2[3], uArray2[4], uArray2[5], uArray2[6], uArray2[7], uArray2[8]},
                            {array3[0], array3[1], array3[2], array3[3], array3[4], array3[5], array3[6], array3[7], array3[8]},
                            {array4[0], array4[1], array4[2], array4[3], array4[4], array4[5], array4[6], array4[7], array4[8]},
                            {array5[0], array5[1], array5[2], array5[3], array5[4], array5[5], array5[6], array5[7], array5[8]},
                            {array6[0], array6[1], array6[2], array6[3], array6[4], array6[5], array6[6], array6[7], array6[8]},
                            {array7[0], array7[1], array7[2], array7[3], array7[4], array7[5], array7[6], array7[7], array7[8]},
                            {array8[0], array8[1], array8[2], array8[3], array8[4], array8[5], array8[6], array8[7], array8[8]},
                            {array9[0], array9[1], array9[2], array9[3], array9[4], array9[5], array9[6], array9[7], array9[8]}};

    //this code is the same as the validator for "testGrid", each column will be tested for duplicates. if there are any duplicates the grids validity will be set to false
    for (int i=0;i<9;i++) {
        for (int j=i + 1;j < 9;j++) {
            if (uGrid[i][0] == uGrid[j][0]) {
                isValid2 = false;
            }
        }
    }
    for (int i=0;i<9;i++) {
        for (int j=i + 1;j < 9;j++) {
            if (uGrid[i][1] == uGrid[j][1]) {
                isValid2 = false;
            }
        }
    }
    for (int i=0;i<9;i++) {
        for (int j=i + 1;j < 9;j++) {
            if (uGrid[i][2] == uGrid[j][2]) {
                isValid2 = false;
            }
        }
    }
    for (int i=0;i<9;i++) {
        for (int j=i + 1;j < 9;j++) {
            if (uGrid[i][3] == uGrid[j][3]) {
                isValid2 = false;
            }
        }
    }
    for (int i=0;i<9;i++) {
        for (int j=i + 1;j < 9;j++) {
            if (uGrid[i][4] == uGrid[j][4]) {
                isValid2 = false;
            }
        }
    }
    for (int i=0;i<9;i++) {
        for (int j=i + 1;j < 9;j++) {
            if (uGrid[i][5] == uGrid[j][5]) {
                isValid2 = false;
            }
        }
    }
    for (int i=0;i<9;i++) {
        for (int j=i + 1;j < 9;j++) {
            if (uGrid[i][6] == uGrid[j][6]) {
                isValid2 = false;
            }
        }
    }
    for (int i=0;i<9;i++) {
        for (int j=i + 1;j < 9;j++) {
            if (uGrid[i][7] == uGrid[j][7]) {
                isValid2 = false;
            }
        }
    }
    for (int i=0;i<9;i++) {
        for (int j=i + 1;j < 9;j++) {
            if (uGrid[i][8] == uGrid[j][8]) {
                isValid2 = false;
            }
        }
    }

    //this will print out "uGrid" along with a message weather It's valid or not
    puts("\n--------- Sudoku Grid -----------");
    if (isValid2 == true) {
        print(uGrid);
        puts("Your sudoku grid is valid");
    }
    else {
        print(uGrid);
        printf("!!YOUR GRID IS NOT VALID!!");
    }
    return 0;
}


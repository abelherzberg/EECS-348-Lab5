//Name: Abel Herzberg
#include <stdio.h>

#define SIZE 5 //Defines the constant "SIZE" which will be the size of the matrices (5x5). This value could be changed in the future to easily alter this program for other matrix sizes


int main(){ //main function that defines the m1 and m2 matrices, requests input from user, and calls the other functions 
    int m1[SIZE][SIZE] = { //m1 matrix that is 5x5
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    int m2[SIZE][SIZE] = { //m2 matrix that is 5x5
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };

    int printSelection; //declares integer printSelection that will store either a 1 or 2 entered by the user. This will be used to tell the code which matrix(m1 or m2) to print for the user
    printf("which matrix would you like to print out? 1.(m1) 2.(m2): "); //printf statement that prompts the user to type a 1 or 2 based on which matrix they want to see printed out
    scanf("%d", &printSelection); //stores the integer entered by the user into the printSelection variable defined earlier
    if (printSelection < 1 | printSelection > 2){ //checks to see if the integer entered by the user is outside the bounds(1-2) defined in the print statement that instructed the user 
        printf("ERROR: You did not select a valid option for printing one of the 2 defined matrices(m1,m2). Please reselect a choice.\n"); //print statement that tells the user their error and prompts them to re-enter a selection
        while (printSelection < 1 | printSelection > 2){//while loop that continues until the user selects an integer inside the bounds
            printf("Which matrix do you want to print? 1.(m1) 2.(m2): "); //print statement that prompts the user to enter a new value
            scanf("%d", &printSelection); //stores the value into the printSelection variable
        }
    }
    else if(printSelection == 1){ //checks to see if the user inputted integer is 1, meaning the user wants to see the first matrix(m1)
        printf("Printing Matrix m1: \n"); //print statement telling the user their selection(m1) is being printed
        printMatrix(m1); //calls to the printMatrix function with the array parameter set to m1
    }
    else if(printSelection == 2){ //checks ot see if the user inputted integer is 1, meaning the user wants to see the second matrix(m2)
        printf("Printing Matrix m2: \n"); //print statement telling the user their selection(m2) is being printed
        printMatrix(m2); //calls to the printMatrix function with the array parameter set to m2
    }

    int m1_rows, m1_columns, m2_rows, m2_columns; //initializes integers to store the calculations of the number of rows and columns in the m1 and m2 matrices using sizeOf() method. This will be used to check if matrix multiplication and addition is viable for the given arrays
    m1_rows = sizeof(m1) / sizeof(m1[SIZE]); //equation that defines m1_rows. takes size of m1 as whole and divides it by the size of its rows
    m1_columns = sizeof(m1) / sizeof(m1[SIZE][SIZE]); //equation that defines m1_columns. takes size of m1 as whole and divides it by the size of its columns
    m2_rows = sizeof(m2) / sizeof(m2[SIZE]); //equation that defines m2_rows. takes size of m2 as whole and divides it by the size of its rows
    m2_columns = sizeof(m2)/ sizeof(m2[SIZE][SIZE]); //equation that defines m2_columns. takes size of m2 as whole and divides it by the size of its columns

    if (m1_columns == m2_rows){ //if statement that checks to see if the number of columns in m1 is equal to the number of rows in m2. This is a requirement in order to multiply two matrices(m1 and m2)
        multiplyMatrices(m1,m2); //if the statement is valid, the multiply matrices function can be ran
    }
    else{ //else statement that runs if the if statement is not satisfied
        printf("ERROR: The multiplication of the two matrices is not possible since the number of columns in m1 does not equal the number of rows in m2\n"); //error statement that tells the user why the multiplyMatrices function can't be ran
    }

    if (m1_rows == m2_rows & m1_columns == m2_columns){//if statement that checks to see if the m1 and m2 matrices have the same dimensions(rows and columns)
        addMatrices(m1, m2); //runs the addMatrices function with array1 = m1 and array2 = m2
    }
    else{ //else statement that runs if the if statement is not satisfied
        printf("ERROR: The addition of the two matrices is not possible since they do not share the same dimensions\n"); //error statement that tells the user why the two matrices can't be added together (not same dimensions)
    }
    
    int transposeSelection; //int definition "transposeSelection" that will store an integer corresponding to the desired selection of the user for which matrix they want transposed
    printf("which matrix would you like to transpose? 1.(m1) 2.(m2): "); //printf statement that prompts the user to type a 1 or 2 based on which matrix they want to see transposed
    scanf("%d", &transposeSelection); //stores the integer entered by the user into the transposeSelection variable defined earlier
    if (transposeSelection < 1 | transposeSelection > 2){ //checks to see if the integer entered by the user is outside the bounds(1-2) defined in the print statement that instructed the user 
        printf("ERROR: You did not select a valid option for transposing one of the 2 defined matrices(m1,m2). Please reselect a choice.\n"); //print statement that tells the user their error and prompts them to re-enter a selection
        while (transposeSelection < 1 | transposeSelection > 2){//while loop that continues until the user selects an integer inside the bounds
            printf("Which matrix do you want to transpose? 1.(m1) 2.(m2): "); //print statement that prompts the user to enter a new value
            scanf("%d", &transposeSelection); //stores the value into the transposeSelection variable
        }
    }
    else if(transposeSelection == 1){ //checks to see if the user inputted integer is 1, meaning the user wants to see the transpose of the first matrix(m1)
        printf("Transposing Matrix m1: \n"); //print statement telling the user their selection(m1) is being transposed
        transposeMatrix(m1); //calls to the transposeMatrix function with the array parameter set to m1
    }
    else if(transposeSelection == 2){ //checks ot see if the user inputted integer is 1, meaning the user wants to see the transpose of the second matrix(m2)
        printf("Transposing Matrix m2: \n"); //print statement telling the user their selection(m2) is being transposed
        transposeMatrix(m2); //calls to the transposeMatrix function with the array parameter set to m2
    }
}

void addMatrices(array1, array2){
    int i, j; //initializes the counting variables i and j, which iterate through the rows and columns of the matrices m1 and m2
    int additionMatrix[SIZE][SIZE]; //creates a new matrix with the same size as defined at the beginning of the code, which will store the results of the addition between the two matrices(m1 and m2)
    
    for (i = 0; i < SIZE; i++){ //iterates through every row of the array
        for(j = 0; j < SIZE; j++){ //iterates through every column of the array
            additionMatrix[i][j] = (array1[i][j] + array2[i][j]); //adds the values at the same row and column location in both arrays(array1, array2) and sets the result to the same i and j(row and column) location in the defined additionMatrix. This is how matrix addition works
        }
    }
    printMatrix(additionMatrix); //prints the final matrix after the addition process has taken place
}


void multiplyMatrices(array1, array2){
    int i, j; //initializes the counting variables i and j, which iterate through the rows and columns of the matrices m1 and m2
    int multiplicationMatrix[SIZE][SIZE]; //creates a new matrix with the same size as defined at the beginning of the code, which will store the results of the multiplication between the two matrices(m1 and m2)

    for (i = 0; i < SIZE; i++){ //iterates through every row of the array
        for(j = 0; j < SIZE; j++){ //iterates through every column of the array
            multiplicationMatrix[i][j] += (array1[i][j] * array2[j][i]); //sums the multiplications of array1 and array2 to get the value of the multiplication matrix at each point. Matrix multiplication multiplies the value at a row in the first array with the value at the column row in the second array
        }
    }
    printMatrix(multiplicationMatrix); //prints the final matrix after the multiplication process has taken place
}

void transposeMatrix(array){
    int i, j; //initializes the counting variables i and j, which iterate through the rows and columns of the matrix chosen by the user 
    int transposeMatrix[SIZE][SIZE]; //creates a new matrix called "transposeMatrix" with the same size as the m1 and m2 matrices, since the transpose of a square matrix does not change the size

    for (i = 0; i < SIZE; i++){ //iterates through every row of the array
        for(j = 0; j < SIZE; j++){ //iterates through every column of the array
            transposeMatrix[i][j] = array[j][i]; //sets the transpose matrix to be the same values as given array, but with the given array having its rows and columns flipped(definition of transpose)
        }
    }
    printMatrix(transposeMatrix); //prints the final matrix after the transpose process has taken place
}

void printMatrix(array){
    
    int i, j; //initialize counting variables i and j to be used in the for loops below to iterate through the rows and columns of the array

    for (i = 0; i < SIZE; i++){ //iterates through every row of the array
        for(j = 0; j < SIZE; j++){ //iterates through every column of the array
            printf("%d", array[i][j]); //prints the value at each location of the array
        }
    }
}


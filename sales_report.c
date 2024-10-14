//Name: Abel Herzberg
#include <stdio.h>

char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"}; //array of length 12 that has the names of all the months
float salesFigures[12]; //array of length 12 that will store the sales figures of all the 12 months as floats
int i; //initializes the variable i as a counting variable for use in for-loops

void monthly_sales_report(){ //function that generates the monthly sales report
    printf("Monthly Sales Report for 2024\n"); //print statement that tells the user it is about to output the monthly sales report
    printf("Month:\t     Sales:\n"); //print statement that shows the format the sales report will be outputted in

    for(i=0; i<12; i++){ //for loop that goes for every month(12 iterations)
        printf("%s\t    %d\n", months[i], salesFigures[i]); //print statement that prints the month and float value at the same index(i)
    }
    
}

void sales_summary_report(){
    float minimum_sales = salesFigures[0]; //initial minimum sales is the sale of the first month
    float maximum_sales = salesFigures[0]; //initial maximum sales is the sales value of the first month
    float avg_sales = 0.0; //average sales is initially 0

    for(i=0; i < 12; i++){ //iterates through all months
        if (salesFigures[i] < minimum_sales){ //if statement that checks to see if the salesFigures value at index i is less than the current value of minimum_sales
            minimum_sales = salesFigures[i];  //if the if statement is true, change the value of minimum_sales to the value at salesFigures[i]
        }
    }

    for(i=0; i < 12; i++){ //iterates through all months
        if (salesFigures[i] > maximum_sales){ //if statement that checks to see if the salesFigures value at index i is greater than the current value of maximum_sales
            maximum_sales = salesFigures[i];  //if the if statement is true, change the value of maximum_sales to the value at salesFigures[i]
        }
    }

    for(i=0; i < 12; i++){ //iterates through all months
        avg_sales += salesFigures[i]; //adds the value of salesFigures[i] to the avg_sales variable, which will result in getting the total number of sales. Dividing this by the number of iterations(12) will get the avg_sales value
    }
    avg_sales = (avg_sales/12); //divides avg_sales by 12(number of months) to get the average monthly sales number

    printf("Maximum Sales: %f", maximum_sales); //print statement that outputs the result of the maximum(highest) sales month
    printf("Minimum Sales: %f", minimum_sales); //print statement that outputs the result of the minimum(lowest) sales month
    printf("Average Sales over 12 months: %f", avg_sales); //print statement that outputs the result of the average sales 

}

int main(){
    printf("Enter the name of the file that contains the sales numbers: "); //print statement that asks the user to enter the name of the sales figures file
    char nameOfFile[50]; //creates an array that stores the name of the text file provided by the user, with a max name length of 50
    scanf("%s", &nameOfFile); //stores the name of the file to the nameOfFile character array defined above(max character length 50)
    FILE *file = fopen(nameOfFile, "r"); //opens the file provided by the user and reads it('r')

    for(i = 0; i < 12; i++){ //for loop that iterates from 0 to 11 (12 iterations). This will get the data for each of the 12 months
        fscanf(nameOfFile, "%f", salesFigures[i]); //stores the number at each row of the file to the salesFigures array
    }

    fclose(nameOfFile); //closes the file given by the user

    monthly_sales_report(); //runs the monthly_sales_report function
    sales_summary_report(); //runs the sales_summary_report function

}

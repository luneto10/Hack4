/**
 * Name: Luciano Carvalho (lguedesdecarvalhon2@huskers.unl.edu)
 *
 * Date: 2023 - 09 - 12
 *
 * Uses the argument line to calculate the interest and total balance
 * of a retirement invest account
 *  document
 * 
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char **argv)
{
    // validating input 
    
    
    if (argc != 6)
    {
        printf("ERROR: incorrect number of command line arguments\n\n");
        exit(1);
    }

    // verify if the values are positive
    for (int i = 1; i < argc - 1; i++)
    {
        if (atof(argv[i]) < 0)
        {
            printf("ERROR: incorrect number of command line arguments\n\n");
            exit(1);
        }
    }

    // verify if the year is greater than 1
    if (atoi(argv[5]) < 1)
    {
        printf("ERROR: incorrect number of command line arguments\n\n");
        exit(1);
    }

    // verify if the annual Inflation and Return are greater than 0 and smaller than 1
    for (int i = 3; i < argc - 1; i++)
    {
        if (atof(argv[i]) < 0 || atof(argv[i]) > 1)
        {
            printf("ERROR: incorrect number of command line arguments\n\n");
            exit(1);
        }
    }

    // verify the annual contribution is greater tha the limit
    if (atof(argv[2]) * 12 > 18500)
    {
        printf("'ERROR: monthly contributions exceed $18,500 annual limit'\n\n");
        exit(1);
    }

    double initialBalance = atof(argv[1]);
    double monthlyContribution = atof(argv[2]);
    double annualRateReturn = atof(argv[3]);
    double annualInflationRate = atof(argv[4]);
    int yearsUntilRetirement = atoi(argv[5]);

    double inflationAdjustedRateYear = (((1 + annualRateReturn) / (1 + annualInflationRate)) - 1);
    double inflationAdjustedRateMonthly = inflationAdjustedRateYear / 12;
    double monthsUntilRetirement = yearsUntilRetirement * 12;
    double interest = 0;
    double totalInterest = interest;
    double totalBalance = initialBalance;
    
    printf("Month  Interest     Balance\t\n");

    for (int months = 0; months < monthsUntilRetirement; months++)
    {
        interest = ((totalBalance)*inflationAdjustedRateMonthly);
        interest = round(interest * 100) / 100;
        totalBalance += interest + monthlyContribution;
        totalBalance = round(totalBalance * 100) / 100;
        totalInterest += interest;
        printf("%d      $ %.2lf      $ %.2lf\t\n", months + 1, interest, totalBalance);
    }

    printf("\nTotal Interest Earned: $ %.2lf\t\n", totalInterest);
    printf("Total Nest Egg: $ %.2lf\t\n", totalBalance);

    return 0;
}
/*  INFO
    Name: Billy Leong
    Email: bleong@csu.fullerton.edu
    Course ID: CPSC223C
    Due Date: 09/08/2024 - 23:59:00
    Program Name: Assignment 1 Trigonometry
    Purpose: getting used to C libraries with simple IO, time, and math
    OS: Windows 11
*/



#include <stdio.h>
#include <time.h>
#include <math.h>

double compute_area(double, double, double);
double compute_side_c(double, double, double);

int main(int argc, char const *argv[])
{
    time_t currentTime = time(NULL);
    struct tm *humanTime = localtime(&currentTime);

    double side_a; 
    double side_b;
    double angle;
    double area_triangle;
    double side_c;
    
    //Program Boot
    printf("Welcome to Euclidean Triangles.\n");
    printf("This software was built by and maintained by Systems Programmer Billy Leong\n");

    printf("The date and time are now: %04d-%02d-%02d @ %02d:%02d:%02d\n",
            humanTime->tm_year+1900,
            humanTime->tm_mon+1,
            humanTime->tm_mday,
            humanTime->tm_hour,
            humanTime->tm_min,
            humanTime->tm_sec);
    printf("The number of seconds since the Great Epoch is %lu\n", currentTime);
    printf("This program will manage all of your triangles.\n");
    printf("Enter a float number for each quantity first side, second side, and angle in degrees between those two sides.\n");
    printf("Separate each quantity by whitespace.  After the third quantity press enter.\n");

    scanf("%lf %lf %lf", &side_a, &side_b, &angle);
    printf("You entered side 1: %5.5lf, side 2: %5.5lf, angle: %5.5lf\n", side_a, side_b, angle);

    if(side_a > 0 || side_b > 0 || angle > 0)
    {
        area_triangle = compute_area(side_a, side_b, angle);
        side_c = compute_side_c(side_a, side_b, angle);
        printf("The area of this triangle is %5.5lf\n", area_triangle);
        printf("The length of the third side is %5.5lf units \n", side_c);
    }
    else
    {
        printf("You have entered invalid parameters. Please run this program again.\n");
    }


    //Program exit
    printf("The number of seconds since the Great Epoch is %lu\n", time(NULL));
    printf("Have a nice day.\n");
    printf("An integer 0 will be sent to the operating system as a signal of successful execution.  Bye.\n");

    return 0;
}

double compute_area(double s1, double s2, double phi)
{
    const double pi = 3.14159;

    return 0.5 * s1 * s2 * sin(phi * pi / 180.0);
}
double compute_side_c(double s1, double s2, double phi)
{
    const double pi = 3.14159;

    return sqrt((s1 * s1) + (s2 * s2) + (2 * s1 * s2 * cos(phi * pi / 180.0)));
}
/*
 *  lab1exe_B.c
 *  ENSF 614 - Fall 2021 Lab 1, exercise B
 *  Created by Mahmood Moussavi
 *  Completed by: Graydon Hall and Jared Kraus
 *  Submission Date: Sept 21, 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// global declaration for our constants
const double G = 9.8;   /* gravitation acceleration 9.8 m/s^2 */
const double PI = 3.141592654;

// function prototypes/declarations
void create_table(double v);
double Projectile_travel_time(double a, double v);
double Projectile_travel_distance(double a, double v);
double degree_to_radian(double d);

int main(void)
{
    int n;
    double velocity;
    
    printf ("Please enter the velocity at which the projectile is launched (m/sec): ");
    n = scanf("%lf" ,&velocity);
    
    if(n != 1)
    {
        printf("Invlid input. Bye...");
        exit(1);
    }
    
    while (velocity < 0 )
    {
        printf ("please enter a positive number for velocity: ");
        n = scanf("%lf", &velocity);
        if(n != 1)
        {
            printf("Invlid input. Bye...");
            exit(1);
        }
    }
    
     create_table(velocity);
    return 0;
}

void create_table(double v)
{
    printf("Angle           t           d\n");
    printf("(deg)           (sec)       (m)\n");

    int i;
    for ( i = 5; i <= 90; i += 5 )
    {
        double dist = Projectile_travel_distance(i,v);
        double time = Projectile_travel_time(i, v);
        printf("%d         %lf     %lf\n", i, time, dist);
    }
}


double Projectile_travel_distance(double a, double v)
{  
    // d = v^2/g*sin(2*theta)
    double a_rad = degree_to_radian(a);  // convert angle from degrees to radians
    return pow(v,2)/G*sin(2*a_rad);
}

double Projectile_travel_time(double a, double v)
{
    // t = 2*v*sin(theta)/g
    double a_rad = degree_to_radian(a);  // convert angle from degrees to radians
    return 2*v*sin(a_rad)/G;
}

double degree_to_radian(double d){
    return d * PI/180;
}

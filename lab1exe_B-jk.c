/*
File Name: lab1exe_B.c
Assignment: Lab 1 Exercise B
Completed by: Jared Kraus
Submission Date: Sept 21, 2021
*/

#include <stdio.h>
#include <math.h>
#define PI 3.141592654
#define G 9.8

double projectile_travel_time(double trajectory_angle, double initial_velocity);
double projectile_travel_distance(double trajectory_angle, double initial_velocity);
double degree_to_radian(double angle_degrees);
void create_table(double initial_velocity);

double projectile_travel_time(double trajectory_angle, double initial_velocity)
{
    return (2 * initial_velocity * sin(trajectory_angle)) / G;
}

double projectile_travel_distance(double trajectory_angle, double initial_velocity)
{
    return (pow(initial_velocity, 2) * sin(2 * trajectory_angle)) / G;
}

double degree_to_radian(double angle_degrees)
{
    return (angle_degrees * PI) / 180;
}

void create_table(double initial_velocity)
{
    double time;
    double distance;
    double angle_radians;
    double angle_degrees = 0.0;

    printf("Angle                 t                 d\n");
    printf("(deg)               (sec)              (m)\n");

    while (angle_degrees < 90.0)
    {
        angle_radians = degree_to_radian(angle_degrees);
        time = projectile_travel_time(angle_radians, initial_velocity);
        distance = projectile_travel_distance(angle_radians, initial_velocity);

        printf("%lf          %lf          %lf\n", angle_degrees, time, distance);

        angle_degrees += 5.0;
    }
}

int main(void)
{
    double initial_velocity;
    //promp for initial velocity
    printf("Please enter the projectile's initial velocity: ");
    scanf("%lf", &initial_velocity);

    create_table(initial_velocity);
}

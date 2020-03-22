#include "ros/ros.h"
#include "map.h"
#include "sensor_msgs/LaserScan.h"
#include "math.h"
#ifndef MAIN_H
#define MAIN_H
double scan_angle_min;
double scan_angle_max;
double scan_angle_inc;
double scan_range_max;
double scan_range_min;

int scan_count;
int valid_scan_count;
float *scan_cart_x; //stores xi in cartesian form of ith valid range data
float *scan_cart_y; //stores yi in cartesian form of ith valid range data

bool firstscan;

// Map m;
#endif

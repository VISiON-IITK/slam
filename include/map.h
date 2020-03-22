#include "ros/ros.h"
#include "nav_msgs/OccupancyGrid.h"
#ifndef MAP_H
#define MAP_H
class Map
{
private:
  nav_msgs::OccupancyGrid map;

public:
  void init(int map_w, int map_h, int map_res);
  void clearMap();
  void publish(const ros::Publisher &pub);
};
#endif

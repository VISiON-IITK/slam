#include "main.h"

void scanCallback(const sensor_msgs::LaserScan::ConstPtr &msg)
{
  scan_angle_max = msg->angle_max;
  scan_angle_min = msg->angle_min;
  scan_angle_inc = msg->angle_increment;
  scan_count = (scan_angle_max - scan_angle_min) / scan_angle_inc + 1;
  ROS_INFO("%d", scan_count);
  valid_scan_count = 0;
  for (int i = 0; i < scan_count; i++)
  {
    int rangeData = msg->ranges[i];
    if (rangeData < 30 && rangeData > 0.1)
    {
      double angle = scan_angle_min + scan_angle_inc * i;
      scan_cart_x[valid_scan_count] = rangeData * std::cos(angle);
      scan_cart_y[valid_scan_count] = rangeData * std::sin(angle);
      valid_scan_count++;
    }
    // std::cout << msg->ranges[i] << "-";
  }
  // std::cout << '\n';
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "slam");
  ros::NodeHandle nh;

  ros::Publisher map_pub = nh.advertise<nav_msgs::OccupancyGrid>("map", 1000);
  ros::Subscriber scan = nh.subscribe("scan", 1, scanCallback);
  ros::Rate loop_rate(50);
  firstscan = true;
  // m.init(60, 60, 0.1);
  while (ros::ok())
  {
    // m.clearMap();
    if (firstscan)
    {
      firstscan = false;
    }
    // m.publish(map_pub);
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}

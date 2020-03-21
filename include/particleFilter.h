#include "ros/ros.h"
#include "geometry_msgs/Pose2D.h"
#include "nav_msgs/OccupancyGrid.h"
#include "map.h"
#include "sampler.h"

#ifndef PARTICLE_FILTER
#define PARTICLE_FILTER
class Particle
{
private:
  int pose_count;
  Map map;
  double *poses;       //queue size will be 3 times pose_count
  int curr_pose_index; //will be initialised to 0 in constructor
  ros::Publisher pose_pub;

public:
  void motionSample(double, double, double);
  ~Particle();
};
class ParticleFilter
{
private:
  int particle_count;
  Particle *particles; //will have particle_count no. of particles
  Sampler sampler;
  double *weights; // weights of particles
  int particle_count_eff;
  int paricle_eff_thresh;
  double alpha[6] = {0.1, 0.1, 0.1, 0.1, 0.1}; //TODO: move this to constuctor
  // double prev_pose[3];
  // double curr_pose[3];
  // ros::Publisher pose_pub;

public:
  ParticleFilter()
  {
  }
  void motionSample(double *odom);
  // void resampleParticles()
};
#endif

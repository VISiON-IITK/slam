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
  int pose_count; //set in constructor
  Map map;
  double *poses;       //queue size will be 3 times pose_count
  int curr_pose_index; //will be initialised to 0 in constructor

public:
  Particle(int pose_count, int map_h, int map_w, int map_res);
  void motionSample(double, double, double);
  ~Particle();
};

class ParticleFilter
{
private:
  int particle_count;
  std::vector<Particle> particles; //will have particle_count no. of particles
  Sampler sampler;
  double *weights; // weights of particles
  int particle_count_eff;
  int particle_eff_thresh;
  double alpha[6];
  // double prev_pose[3];
  // double curr_pose[3];

public:
  ParticleFilter(int count, int pose_count, int thresh, int error_param[],
                 int map_w, int map_h, double map_res);
  void motionSample(double *odom);
  // void resampleParticles()
  ~ParticleFilter();
};
#endif

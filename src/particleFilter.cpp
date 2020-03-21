#include "particleFilter.h"

void ParticleFilter::motionSample(double *odom)
{

  double *errors_r1, *errors_t, *errors_r2;
  double delta_r1 = odom[0], delta_t = odom[1], delta_r2 = odom[2];
  sampler.normalSamples(particle_count, 0, alpha[0] * delta_r1 + alpha[1] * delta_t, errors_r1);
  sampler.normalSamples(particle_count, 0, alpha[2] * delta_t + alpha[3] * (delta_r1 + delta_r2), errors_t);
  sampler.normalSamples(particle_count, 0, alpha[4] * delta_r2 + alpha[6] * delta_t, errors_r2);
  for (int i = 0; i < particle_count; i++)
  {
    particles[i].motionSample(delta_r1 + errors_r1[i], delta_t + errors_t[i], delta_r2 + errors_r2[i]);
  }
}

void Particle::motionSample(double delta_r1, double delta_t, double delta_r2)
{
  int index = 3 * curr_pose_index;
  double old_x = poses[index], old_y = poses[index + 1], old_theta = poses[index + 2];
  curr_pose_index = (curr_pose_index == pose_count - 1) ? 0 : curr_pose_index++;
  index = 3 * curr_pose_index;
  poses[index] = old_x + delta_t * std::cos(old_theta + delta_r1);
  poses[index + 1] = old_y + delta_t * std::sin(old_theta + delta_r1);
  poses[index + 2] = old_theta + delta_r1 + delta_r2; //TODO: make sure theta is between -pi and pi
}

Particle::~Particle()
{
  delete poses;
}
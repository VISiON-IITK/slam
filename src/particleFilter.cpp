#include "particleFilter.h"

void ParticleFilter::motionSample(double *odom)
{
  double *errors_r1, *errors_t, *errors_r2;
  double delta_r1 = odom[0], delta_t = odom[1], delta_r2 = odom[2];
  sampler.normalSamples(particle_count, 0, alpha[0] * delta_r1 + alpha[1] * delta_t, errors_r1);
  sampler.normalSamples(particle_count, 0, alpha[2] * delta_t + alpha[3] * (delta_r1 + delta_r2), errors_t);
  sampler.normalSamples(particle_count, 0, alpha[4] * delta_r2 + alpha[5] * delta_t, errors_r2);
  for (int i = 0; i < particle_count; i++)
  {
    particles[i].motionSample(delta_r1 + errors_r1[i], delta_t + errors_t[i], delta_r2 + errors_r2[i]);
  }
  delete[] errors_r1;
  delete[] errors_t;
  delete[] errors_r2;
}

ParticleFilter::ParticleFilter(int count, int pose_count, int thresh, int error_param[],
                               int map_w, int map_h, double map_res)
{
  particle_count = count;
  particle_eff_thresh = thresh;
  for (int i = 0; i < 6; i++)
    alpha[i] = error_param[i];
  particles.assign(count, Particle(pose_count, map_h, map_w, map_res));
  weights = new double[count];
  for (int i = 0; i < count; i++)
    weights[i] = 1 / count;
  particle_count_eff = count;
}

Particle::Particle(int pose_count, int map_h, int map_w, int map_res)
{
  Particle::pose_count = pose_count;
  map.init(map_w, map_h, map_res);
  poses = new double[pose_count];
  //initiallise current pose
  poses[0] = 0;
  poses[1] = 0;
  poses[2] = 0;
  curr_pose_index = 0;
}

ParticleFilter::~ParticleFilter()
{
  delete[] weights;
}

Particle::~Particle()
{
  delete[] poses;
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

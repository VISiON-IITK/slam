#include "sampler.h"

void Sampler::normalSamples(int count, double mean, double var, double *output)
{
  boost::random::normal_distribution<> norm_dist(mean, var);
  output = new double[count];
  for (int i = 0; i < count; i++)
  {
    output[i] = norm_dist(gen);
  }
}

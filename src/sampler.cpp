#include "sampler.h"

// boost::random::normal_distribution<> Sampler::normal(double mean, double var)
// {
//   return boost::random::normal_distribution<>(mean, var);
// }

void Sampler::normalSamples(int count, double mean, double var, double *output)
{
  boost::random::normal_distribution<> norm_dist(mean, var);
  output = (double *)malloc(count * sizeof(double));
  for (int i = 0; i < count; i++)
  {
    output[i] = norm_dist(gen);
  }
}
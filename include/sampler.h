#include <boost/random/mersenne_twister.hpp>
#include <boost/random/normal_distribution.hpp>
#ifndef SAMPLER_H
#define SAMPLER_H
class Sampler
{
private:
  boost::random::mt19937 gen;

public:
  // boost::random::normal_distribution<> normal(double mean, double var);
  void normalSamples(int count, double mean, double var, double *output);
};
#endif

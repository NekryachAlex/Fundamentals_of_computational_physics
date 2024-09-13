#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
template<class T>
void checking()
{
  T epsilon = 1.;
  while (1 + epsilon / 2 != 1 ) {
    epsilon /= 2;
  }
  std::cout <<"ULP: " << epsilon << std::endl;

  T number = 1;
  int count = 0;
  while(!std::isinf(number)){

    number *= 2;
    count += 1;
  }
  std::cout<<"Exp+ " << count << std::endl;
  number = 1;
  count = 0;
  while(number != 0){
    number /= 2;
    count += 1;
  }
  std::cout<<"Exp- " << count << std::endl;

 
}
int main() 
{
  //a)
  std::cout << "a) for float" << std::endl;
  checking<float>();
  std::cout << "a) for double" << std::endl;
  checking<double>();
  //б) 
  std::cout << std::endl << "b)" << std::endl;

  std::cout.precision(32); 
  double fromGreaterToLesserSum = 0.;
  for (size_t n = 10000; n >= 1; --n) {
    fromGreaterToLesserSum += pow(-1, n) / n;
  }
  std::cout << fromGreaterToLesserSum << std::endl;

  double fromLesserToGreaterSum = 0.;
  for (size_t n = 1; n <= 10000; ++n) {
    fromLesserToGreaterSum += pow(-1, n) / n;
  }
  std::cout << fromLesserToGreaterSum << "+-" << 
    (fromGreaterToLesserSum - fromLesserToGreaterSum) << std::endl;

  double fromGreaterToLesserPositiveSum = 0.;
  double fromGreaterToLesserNegativeSum = 0.;
  for (size_t n = 10000; n >= 1;) 
  {
    fromGreaterToLesserNegativeSum += 1. / n;
    --n;
    fromGreaterToLesserPositiveSum += -1. / n;
    --n;
  }
  std::cout << fromGreaterToLesserNegativeSum + fromGreaterToLesserPositiveSum << "+-" << 
    (fromGreaterToLesserNegativeSum + fromGreaterToLesserPositiveSum - fromLesserToGreaterSum) << std::endl;

  double fromLesserToGreaterPositiveSum = 0.;
  double fromLesserToGreaterNegativeSum = 0.;
  for (size_t n = 1; n <= 10000;) 
  {
    fromLesserToGreaterNegativeSum += -1. / n;
    ++n;
    fromLesserToGreaterPositiveSum += 1. / n;
    ++n;
  }
  std::cout << fromLesserToGreaterNegativeSum + fromLesserToGreaterPositiveSum << "+-" << 
    (fromGreaterToLesserNegativeSum + fromGreaterToLesserPositiveSum - fromLesserToGreaterNegativeSum - fromLesserToGreaterPositiveSum) << std::endl;

  return 0;
}
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
template<class T>
void checking()
{
  T epsilon = 1.;
  while (1 + epsilon / 2 != 1 ) {
    epsilon /= 2;
  }
  std::cout <<"ULP: " << epsilon << std::endl;


  float num = 1.0f;
    unsigned int bits = reinterpret_cast<unsigned int&>(num);

    std::cout << "1.0 в битах: ";
    for (int i = 31; i >= 0; --i) {
        std::cout << ((bits >> i) & 1);
    }
    std::cout << std::endl;


  T number = 1;
  int count = 0;
  while(!std::isinf(number)){
        unsigned int bits = reinterpret_cast<unsigned int&>(number);

    std::cout << "number: ";
    for (int i = 31; i >= 0; --i) {
        std::cout << ((bits >> i) & 1);
    }
    std::cout << std::endl;
    number *= 2;
    count += 1;

  }
  std::cout<<"Exp+ " << count << std::endl;
  number = 1;
  count = 0;
  while(number != 0){
unsigned int bits = reinterpret_cast<unsigned int&>(number);

    std::cout << "number: ";
    for (int i = 31; i >= 0; --i) {
        std::cout << ((bits >> i) & 1);
    }
    std::cout << std::endl;
    number /= 2;
    count += 1;
  }

  // do{
  //   number /= 2;
  //   count += 1;  
  // }while(number != 1);
  // std::cout<<"Exp- " << count << std::endl;

 
}
int main() 
{
  //a
  std::cout << "a) for float" << std::endl;
  checking<float>();
  std::cout << "a) for double" << std::endl;
  //checking<double>();






  // //b 
  // std::cout << std::endl << "b)" << std::endl;

  // std::cout.precision(16); 
  // double MaxToMin = 0.;
  // for (size_t n = 10000; n >= 1; --n) {
  //   MaxToMin += pow(-1, n) / n;
  // }
  // std::cout << MaxToMin << std::endl;

  // double MinToMax = 0.;
  // for (size_t n = 1; n <= 10000; ++n) {
  //   MinToMax += pow(-1, n) / n;
  // }
  // std::cout << MinToMax << std::endl;

  // double MaxToMinPositive = 0.;
  // double MaxToMinNegative = 0.;
  // for (size_t n = 10000; n >= 1;) 
  // {
  //   MaxToMinNegative += 1. / n;
  //   --n;
  //   MaxToMinPositive += -1. / n;
  //   --n;
  // }
  // std::cout << MaxToMinNegative + MaxToMinPositive << std::endl;

  // double MinToNegativePositive = 0.;
  // double MinToNegativeNegative = 0.;
  // for (size_t n = 1; n <= 10000;) 
  // {
  //   MinToNegativeNegative += -1. / n;
  //   ++n;
  //   MinToNegativePositive += 1. / n;
  //   ++n;
  // }
  // std::cout << MinToNegativeNegative + MinToNegativePositive << std::endl;
  // float inf = std::numeric_limits<float>::infinity();
  //   unsigned int bits = reinterpret_cast<unsigned int&>(inf);

    // std::cout << "inf: ";
    // for (int i = 31; i >= 0; --i) {
    //     std::cout << ((bits >> i) & 1);
    // }
    // std::cout << std::endl;


  return 0;
}
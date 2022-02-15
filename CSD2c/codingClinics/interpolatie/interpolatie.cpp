#include <iostream>
#define STEPS 20


float nnmap(float input,float min,float max){
  float output;
  if (input <= 0.5) {
    output = min;
  }else {
    output = max;}
  return output;
}

float linear(float input,float min,float max){
  float output;
  float range = max - min;
  output = range * input;
  output += min;

  return output;
}

float map(float input, float x1, float x2, float min, float max){
  float output = (min*(x2-input) + max*(input-x1) ) / (x2 - x1);
  return output;
}


int main()
{

  std::cout << "NNMap\n" ;
  for(int i=1; i<STEPS; i++){
    float input=(float)i/STEPS;
    std::cout << input << " -> lenker nummertje " << nnmap(input,3,5) << std::endl;
  }

  std::cout << "Linear\n" ;
  for(int i=1; i<STEPS; i++){
    float input=(float)i/STEPS;
    std::cout << input << " -> lenker nummertje " << linear(input,100,200) << std::endl;
  }

  std::cout << "map\n" ;
  for(int i=1; i<STEPS; i++){
    float input= 1 + (float)i/STEPS;
    std::cout << input << " -> lenker nummertje " << map(input,1,2,100,200) << std::endl;
  }


}

#include <iostream>
#define STEPS 20

//NNMAP
//Hard map a [0,1] to a certain min or max. if below 0.5 = min != max 
float nnmap(float input,float min,float max){
  float output;
  if (input <= 0.5) {
    output = min;
  }else {
    output = max;}
  return output;
}

//LINEAR
//Map a [0,1] range to choosen [min,max] range.
float linear(float input,float min,float max){
  float output;
  float range = max - min;
  output = range * input;
  output += min;

  return output;
}

//MAP
//map a [0,1] to another scale and interpolate that scale to choosen parameters.
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
    std::cout << input << " -> lenker nummertje " << linear(input,200,850) << std::endl;
  }

  std::cout << "map\n" ;
  for(int i=1; i<STEPS; i++){
    float input= 1 + (float)i/STEPS;
    std::cout << input << " -> lenker nummertje " << map(input,1,2,100,200) << std::endl;
  }


}

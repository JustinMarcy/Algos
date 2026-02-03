#include<iostream>
#include<math.h>
#include"quake3.c"

int main() {
    float x;
    std::cout<<"Welcome! Lets evaluate the quake3 algo"<<std::endl;
    std::cout<<"Enter a float to perform an inverse square operation on: ";
    std::cin>>x;
    std::cout<<"\n"<<"quake3: "<<fast_inv_sqrt(x,0)<<std::endl;
    std::cout<<"using std sqrt: "<<(1/sqrt(x))<<std::endl;
    std::cout<<"percent diff w/ 1 iteration: "<<((fast_inv_sqrt(x,0)-(1/sqrt(x)))/(1/sqrt(x)))*100<<std::endl;
    std::cout<<"percent diff w/ 2 iteration: "<<((fast_inv_sqrt(x,1)-(1/sqrt(x)))/(1/sqrt(x)))*100<<std::endl;

    return 0;
}
#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
#include <vector>

std::string solving(std::string equation, std::vector<std::vector<std::string>>& operations, int count){
  if(count>=operations.size()){
    return equation;
  }
  else{
    std::string operate = operations[count][0];
    std::string operate2 = operations[count][1];
      if(equation.find(operate)!=std::string::npos||equation.find(operate2) != std::string::npos){
        int leftLocation = 0;
        int rightLocation = 0;
        int solution = 0;
        int left = 0;
        int right = 0;
        std::string currOperate = "";
        while(equation.find(operate) != std::string::npos || equation.find(operate2) != std::string::npos){ // Check if the operation is found
          if(equation.find(operate)>equation.find(operate2)){
            currOperate = operate2;
          }
          else{
            currOperate = operate;
          }
          if(equation.length()!=3){
            for(int i = equation.find(currOperate); i--, i>=0;){
              if(isdigit(equation[i])==0){
                leftLocation = i+1;
                left = stoi(equation.substr(i+1, equation.find(currOperate)-i-1));
                }
              else if(i==0){
                left = stoi(equation.substr(0, equation.find(currOperate)));
                }
              }
            for(int i = equation.find(currOperate); i<=equation.length(); i++){
              if(isdigit(equation[i])==0){
                right = stoi(equation.substr(equation.find(currOperate)+1, i));
                rightLocation = equation.find(currOperate)+1;
                }
              else if(i==equation.length()){
                right = stoi(equation.substr(equation.find(currOperate)+1, i));
                }
              }
            }
          else{
            left = stoi(equation.substr(0, equation.find(currOperate)));
            right = stoi(equation.substr(equation.find(currOperate)+1, equation.length()));
            rightLocation = equation.find(currOperate)+1;
            }
          if(currOperate=="*"){
            solution = left*right;
            }
          else if(currOperate=="+"){
            solution = left+right;
            }
          else if(currOperate=="-"){
            solution = left-right;
            }
          else if(currOperate=="/"){
            solution = left/right;
          }
          int copyRight = right;
          int digits = 0;
          while(copyRight>0){
            copyRight/=10;
            digits++;
            }
          equation = equation.replace(leftLocation,rightLocation+digits, std::to_string(solution));
          }
        }
    return solving(equation, operations, count+1);
  }
  return "";
}
int main() {
  std::string response = "";
  std::vector<std::vector<std::string>> pemdas = {{"*", "/"}, {"+", "-"}};
  while(true){
    std::cout<<"Please type your equation here:\n";
    std::cin>>response;
    if(response=="off"){
      break;
    }
    std::cout<<solving(response, pemdas, 0)+"\n";
    }

}
#include <iostream>
#include <vector>
#include <sstream>

void displayNumbers(const std::vector<int> NEW_NUMBER_LIST){
    std::cout << "The deduplicated vector is: [";

    for (int i = 0; i < NEW_NUMBER_LIST.size(); i++){
        if(i < (NEW_NUMBER_LIST.size() - 1)){
            std::cout << NEW_NUMBER_LIST[i] <<",";
        }else{
            std::cout << NEW_NUMBER_LIST[i] <<"";
        }
    }
    std::cout << "]" << std::endl;
}

void removeDuplicate(const std::vector<int> NUMBER_LIST){
    std::vector<int> newNumberList;

    for (int i = 0; i < NUMBER_LIST.size(); i++){

        bool uniqueNumber = true;
        for (int j = 0; j < i; ++j){
            if (NUMBER_LIST[j] == NUMBER_LIST[i]){
                uniqueNumber = false;
            }
        }
        
        if (uniqueNumber){
            newNumberList.push_back(NUMBER_LIST[i]);
        }
    }

    displayNumbers(newNumberList);
}

int main(){
    std::string readLine;
    int number;
    std::vector<int> numberList;

    std::cout << "Enter the vector elements: " <<std::endl;

    std::getline(std::cin, readLine);
    std::istringstream isThereValue(readLine);

    while (isThereValue >> number){
        numberList.push_back(number);
    }

    removeDuplicate(numberList);
}
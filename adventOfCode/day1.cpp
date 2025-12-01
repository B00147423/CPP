#include <iostream>
#include <string>
#include <fstream>
int main(){
    std::ifstream file("../input.txt");
    if(!file.is_open()) {
        std::cerr << "Failed to open input file.\n";
        return 1;
    }

    std::string line;
    int pos = 50;
    int zeroCount = 0;
    const int MOD = 100;

    while(std::getline(file, line)){
        if(line.empty()){
            continue;
        }

        char direction = line[0];
        int steps = std::stoi(line.substr(1));

        if(direction == 'L'){
            pos = (pos - (steps % MOD) + MOD) % MOD;
        }
        else{
            pos = (pos + (steps % MOD)) % MOD;
        }
        if(pos == 0){
            zeroCount++;
        }

    }

    std::cout << "\nzeroCount"<< zeroCount << std::endl;
    return 0;
}
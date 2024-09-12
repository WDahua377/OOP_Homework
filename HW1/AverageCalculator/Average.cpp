#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <cstdlib>
#include<string>

using namespace std;

int main(){
    float average = 0;
    string input;
    int sum = 0, number = 0, flag = 0;
    //number is the number of scores read
    //flag is used to record whether it is the first calculation

    while(1){       //Program will keep calculating, unless the input is "-1"
        if(flag == 0){
            cout << "Please input the score : " << endl;      //first time
        }
        else{
            cout << "Please input the score of next set : " << endl;
        }

        cin >> input;   //input the score

         if(input.compare("-1") == 0){      //when input is "-1", calculate the average
            if(number == 0){    //if there is no input
                flag = 1;
                cout << "Average score is : 0.0" << endl;
            }
            else{
                average = (float)sum/number;
                cout << "Average score is : " << average << endl;
                sum = 0;         // Initialize number and sum to 0 before starting.
                number = 0;
                flag = 1;       //and change the flag to 1 to indicate that it is not the first calculation after
            }
        }

        else{
            for(int i = 0; i < input.length();i++){     //check if input is legal
                    if( !isdigit(input[i]) ){       //The isdigit() function checks whether a character is numeric character (0-9) or not.
                        cout << "illegal input, ending the program..." << endl;
                        return 0;       //if it is not integer, which means that it is illegal, return 0.
                        }
                    }
            int score = stoi(input);
            if(score >= 0 && score <= 100){     //Then check is score is 0~100
                sum += score;      // Add new score into sum
                number++;
                }
            else{       //score > 100 or score < 0
                cout << "illegal input, ending the program..." << endl;
                return 0;
                }
            }
    }
    return 0;
}


#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <sys/time.h>
#include <iomanip>
#include <windows.h>
#include <unistd.h>

using namespace std;

// Return sum of odd-place digits in the card number
int sumOfOddPlace (const string& cardNumber){
    int sum = 0;
    int len = cardNumber.length();  //cardNumber.length()-i >= 0 would be infinite loop, idk why
    for(int i = 1; len-i >= 0;i += 2){
        char c = cardNumber[cardNumber.length()-i];
        int n = c - '0';    //'4' - '0' equals to  4
        sum += n;
    }
    return sum;
}

// Return this number if it is a single digit, otherwise,
// return the sum of the two digits
int getDigit (int number){
    number = number*2;
    if(number >= 10){   //number*2 is two digits
        int a = number % 10;
        int b = number/10;  //because b is a int, we would get tens digit
        return a+b;
    }
    else{   //number*2 is one digit
        return number;      }
}

// Get the result from Step 2
int sumofDoubleEvenPlace (const string& cardNumber){
    int sum = 0;
    int len = cardNumber.length();  //same as sumOfOddPlace()
    for(int i = 2; len-i >= 0;i += 2){
        char c = cardNumber[cardNumber.length()-i];
        int n = c - '0';    //'4' - '0' equals to  4
        sum += getDigit(n);
    }
    return sum;
}

// Return true if the card number is valid
bool isvalid (const string& cardNumber){
    int sumofDouble = sumofDoubleEvenPlace(cardNumber);
    int sumofodd = sumOfOddPlace(cardNumber);
    int totalsum = sumofDouble + sumofodd;
    if(totalsum % 10 == 0){ // If the result is divisible by 10, the card number is valid;
        return true;        }
    else{   //otherwise, it is invalid
        return false;       }
}

// Return the prefix for cardNumber
int startsWith (const string& cardNumber){
    string nstr = cardNumber.substr(0, 2);      //get first two numbers
    int n = std::stoi(nstr);
    return n;
}

// Return a valid credit card number for the given brand:
// ¡§004¡¨ for Visa cards
// ¡§005¡¨ for MasterCard cards
// ¡§0037¡¨ for American Express cards
// ¡§006¡¨ for Discover cards
string fakeOne (const string& brand){
    char numstr[16];    //store fake number
    srand( time(NULL) );
    int n1 = stoi(brand);   //brand number
    int n2;
    if(n1 >= 10){   //if brand number is two digits
        numstr[0] = (n1/10) + '0';
        numstr[1] = (n1%10) + '0';
        for(int i = 0;i < 13;i++){
            n2 = rand() % (10);     //Randomly generate numbers from 0 to 9
            numstr[i+2] = n2 + '0';
        }
    }
    else{   //if brand number is one digits
        numstr[0] = n1 + '0';
        for(int i = 0;i < 14;i++){
            n2 = rand() % (10);
            numstr[i+1] = n2 + '0';
        }
    }
    numstr[16] = '\0';      //converting string to int requires end of sentence
    string str(numstr);
    return str;
}

int main(int argc, char *argv[]){
    string s;   //input string
    string cardtype;

    struct timeval t1,t2;   //time
    double timeuse;

    //open input file
    fstream file;
    file.open(argv[1], ios::in);   //allows input (read operations) from a stream
    if(!file){   //Check if the file can be opened correctly.
        cerr << "Error: Fail to open file " << argv[1] << " , ending the program." << endl;
        exit(1);
    }

    while( !file.eof() ){
        getline(file, s);  //read a line from file to s

        //if input string s is a card number
        if( s.length() <= 16 && s.length() >= 13){
            switch( startsWith(s) ){    //check card type
            case 40 ... 49:
                cardtype = ("Visa card");
                break;
            case 50 ... 59:
                cardtype = ("MasterCard card");
                break;
            case 37:
                cardtype = ("American Express card");
                break;
            case 60 ... 69:
                cardtype = (" Discover card");
                break;
            default:
                cardtype = ("Default");     //this brand number can't be identified
                break;
            }
            if( isvalid(s) ){   //check whether card number is valid or not
                cout << s << " : a valid " << cardtype << " # " << endl;        }
            else{
                if(cardtype == "Default"){
                    cerr << "00" << startsWith(s) << " isn't a valid brand number. " << endl;       }
                else{
                    cout << s << " : an invalid " << cardtype << " # " << endl;     }
            }
        }

        //input is only a newline, do nothing
        else if(s.length() == 0);

        //input string s is a brand
        else if(s.length() == 3 || s.length() == 4){
            //cout << "wait" << endl;
            switch( stoi(s) ){    //check card type
                case 4:
                cardtype = ("Visa card");
                break;
                case 5:
                cardtype = ("MasterCard card");
                break;
                case 37:
                cardtype = ("American Express card");
                break;
                case 6:
                cardtype = (" Discover card");
                break;
            }

            gettimeofday(&t1,NULL);     //get time
            string fakestr = fakeOne(s);
            int flag = isvalid(fakestr);    //check if fakestr is valid
	int aa = 0;
            while( !flag ){     //if not, generate another fake number
                fakestr = fakeOne(s);
                flag = isvalid(fakestr);
	//aa++;
	//cout << "aa : " << aa << endl;
	//cout << "flag : " << flag << "\nnumber : " << fakestr << endl;
                }
	//cout << "aa : " << aa << endl;
	//cout << "flag : " << flag << "\nnumber : " << fakestr << endl;
                gettimeofday(&t2,NULL);     //get time
                timeuse = (t2.tv_sec - t1.tv_sec) + (double)(t2.tv_usec - t1.tv_usec)/1000000.0;
           //cout << "Generated a valid "<< cardtype << " #: " << fakestr << "; Timing:  " << fixed  <<  setprecision(6) << timeuse <<" seconds" << endl;
	sleep(1);
	cout << "Generated a valid "<< cardtype << " #: " << fakestr << "; Timing:  " << fixed  <<  setprecision(6) << timeuse <<" seconds" << endl;
        }

        //any illegal input
        else{
            cerr << s <<" is illegal input" << endl;        }
    }

    return 0;
}

#include <iostream>
#include <cstdlib>
#include <tuple>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

class coins{
    public:
    //constructor
    coins(double i) : quarters(0), dimes(0), nickels(0), pennies(0), dollars(0), cents(0), value(i){
        extract_value(i*100);
        compute(dollars, cents);
    }
    coins() : quarters(0), dimes(0), nickels(0), pennies(0),dollars(0), cents(0), value(0){}

    void extract_value(double i);   //extract the dollars value and the cents value of the input and save them as integers
    void compute(int d, int c);     //compute and save q, d, n, and p

    //get the dollar(input) value
    inline float get_value() const{
        return value;
    }

    //return the value of q, d, n, and p as separate members
    inline tuple<int, int, int, int> get_monetary() const{
        tuple<int, int, int, int> result;
        result = make_tuple(quarters, dimes, nickels, pennies);
        return result;
    }

    //display computed result on terminal
    inline void display(){
    cout << "$" << value << " = " << quarters<<" quarters, "<< dimes 
        <<" dimes, " << nickels <<" nickels, " << pennies <<" pennies" << endl;
    }

    private:
    int quarters;   //25
    int dimes;      //10
    int nickels;    //5
    int pennies;    //1
    int cents;      //store (cents values*100) as integers
    int dollars;    //store dollars values as integers
    double value;   //store dollar(input) value
};

void coins :: extract_value(double i){
    dollars = i/100;
    cents = (int)round(i) % 100;    //強制轉換會造成誤差，因此使用round()進行適當的轉換
}

void coins :: compute(int d, int c){
    int total = dollars*100 + cents;    //單位調整，以cent為單位，$2.33會存為整數233
    quarters = total/25;
    total -= quarters*25;
    dimes = total/10;
    total -= dimes*10;
    nickels = total/5;
    total -= nickels*5;
    pennies = total;
}

void error_handler(double i){
    stringstream sstream;
    sstream << i;
    string numstr = sstream.str();
    if(i < 0){
        cout << "Input cannot be negative." << endl;
        exit(0);
    }
    if(numstr.length() > 4){
        cout << "Input should be the smallest unit \"cent\"." << endl;
        exit(0);
    }
}

int main(int argc, char *argv[]){
    double value = atof(argv[1]); //如果開頭不是數字就會輸出0
    error_handler(value);   //基本錯誤檢查
    cout << value << endl;
    coins p(value);
    p.display();
    return 0;
}
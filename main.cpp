#include <iostream>
using namespace std;


bool isEven(int RouletteValue,string OneOrNot){
    string result;
    if(RouletteValue == 0){
        return false;
    }
    else{
        if(RouletteValue%2==0){
            result = "even";
        }
        else{
            result = "odd";
        }
    }
    if(OneOrNot==result){
        return true;
    }
    else{
        return false;
    }
}

bool quadrantcheck(int RouletteValue,string quadrant){
    string result;
    if(RouletteValue == 0){
        return false;
    }
    else{
        if(RouletteValue>=19){
            result = "higher";
        }
        else{
            result = "lower";
        }
    }
    if(result == quadrant){
        return true;
    }
    else{
        return false;
    }
}

bool BlackorRed(string color[], string colorpick,int RouletteValue){
    if(color[RouletteValue]==colorpick){
        return true;
    }
    else{ 
        return false;
    }
}

bool straightup(int position,int RouletteValue){
    if(position == RouletteValue){
        return true;
    }
    else{
        return false;
    }
}

void Menu(){
    cout << "Pick 1 option below:" << endl;
    cout << "1. Bet if the color will be Black or Red, payout: 1:1 " << endl;
    cout << "2. Bet if the number will be Odd or even, payout: 1:1 " << endl;
    cout << "3. Bet which quadrant the number will be within, 1-18 or 19-36, payout: 1:1 " << endl;
    cout << "4. Bet which number comes up, payout: 35:1 " << endl;
    cout << "5. done playing " << endl;
    cout << endl;
}

int main(){
    string res;
    string color[37] = {"null","red","black","red","black","red","black","red","black","red",
                        "black","black","red","black","red","black","red","black","red",
                        "red","black","red","black","red","black","red","black","red",
                        "black","black","red","black","red","black","red","black","red"};
    int position,RouletteValue,option;
    double balance = 100.00;
    double bet;
    string colorpick,OneOrNot,quadrant;
    cout << "Welcome to Roulette, Wanna play(y,n): ";
    cin >> res;
    if(res == "N" || res == "n"){
        return 0;
    }
    cout << "Curent balance is: " << balance << endl;
    do{
    Menu();
    cin >> option;
    switch(option){
        case 1:
           cout << "Pick a Color, black or red: ";
           cin >> colorpick;
           cout << endl;
           cout << "Place your bets: ";
           cin >> bet;
           while(bet > balance){
               cout << "Don't have enough to make that bet" <<endl;
               cout << "Place your bets: ";
               cin >> bet;
           }
           balance = balance - bet;
           cout << endl;
           RouletteValue = rand() % 37;
           if(BlackorRed(color,colorpick,RouletteValue) == true){
               balance = balance + (bet*2);
               cout << "You won " << bet << ", your new balance is: " << balance << endl;
           }
           else{
               cout << "You lost " << bet << ", your new balance is: " << balance << endl;
           }
           break; 
        case 2:
           cout << "Pick if even or odd: ";
           cin >>  OneOrNot;
           cout << "Place your bets: ";
           cin >> bet;
           while(bet > balance){
               cout << "Don't have enough to make that bet" <<endl;
               cout << "Place your bets: ";
               cin >> bet;
           }
           balance = balance - bet;
           cout << endl;
           RouletteValue = rand() % 37;
           if(isEven(RouletteValue,OneOrNot)== true){
               balance = balance + (bet*2);
               cout << "You won " << bet << ", your new balance is: " << balance << endl;
           }
           else{
               cout << "You lost " << bet << ", your new balance is: " << balance << endl;
           };
           break;
        case 3:
           cout << "pick a quadrant, higher than or equal 19 or lower than or equal to 18(higher/lower): ";
           cin >> quadrant;
           cout << "Place your bets: ";
           cin >> bet;
           while(bet > balance){
               cout << "Don't have enough to make that bet" <<endl;
               cout << "Place your bets: ";
               cin >> bet;
           }
           balance = balance - bet;
           RouletteValue = rand() % 37;
            if(quadrantcheck(RouletteValue,quadrant)==true){
               balance = balance + (bet*2);
               cout << "You won " << bet << ", your new balance is: " << balance << endl;
            }
            else{
               cout << "You lost " << bet << ", your new balance is: " << balance << endl;
            }
            break;
        case 4:
            cout << "pick a number: 0 - 36: ";
            cin >> position;
            cout << "Place your bets: " << endl;
            cin >> bet;
            while(bet > balance){
               cout << "Don't have enough to make that bet" <<endl;
               cout << "Place your bets: ";
               cin >> bet;
            }
            balance = balance - bet;
            RouletteValue = rand() % 37;
            if(straightup(position,RouletteValue)==true){
               balance = balance + (bet*36);
               cout << "You won " << bet << ", your new balance is: " << balance << endl;
            }
            else{
               cout << "You lost " << bet << ", your new balance is: " << balance << endl;
            } 
            break;
        case 5:
            break;
        default:
            cout << "Please pick an option" << endl;
    }
    }while(option != 5 && balance > 0);
    return 0;
}
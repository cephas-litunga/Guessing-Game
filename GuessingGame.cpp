#include <iostream>
using namespace std;

class Game
{
public:
    int mainNum, trialNum, enterNum;

    void setNumber(){

        system("cls");
        cout<<"Welcome to my two player guessing game.\n";
        cout<<"----Rules---- \n";
        cout<<"One Player Sets a number... \n";
        cout<<"And the other trys to guess it within 5 tries. \n";
        cout<<endl;
        cout<<"Press 1 to continue:";


        while(!(cin>>enterNum) || enterNum != 1)
        {
            cin.clear();
            cin.ignore();
            system("cls");
            cout<<"Invalid input, try again. \n";
            cout<<"Press 1 to continue:";
        }

        if(enterNum == 1){
            system("cls");
        }else{
            return;
        }

        cout <<"Player 1 what number are you going to set (1-50):";

        while (!(cin>>mainNum) || (mainNum < 1 || mainNum > 50))
        {
            cin.clear();
            cin.ignore();
            system("cls");
            cout<<"Invalid input. Try again. \n";
            cout <<"Player 1 what number are you going to set (1-50):";     
        }
        system("cls");
    }

    void startGame(){
        int userNum, tries = 5;
        
        cout<<"Hello, player 2. \n";

        while(tries > 0){
            cout<<"Please Pick a number(1-50):";
            
            while (!(cin>>userNum) || (userNum < 1 || userNum > 50)){
                cin.clear();
                cin.ignore();
                system("cls");
                cout<<"Invalid input. Try again. \n";
                cout<<"Please Pick a number(1-50):";               
            }

            system("cls");

            if(userNum == mainNum){
                cout<<"Congratulations, Player 2 you win! \n";
                break;
            }else if (userNum < mainNum){
                cout<<"Higher. \n";
            }else{
                cout<<"Lower. \n";
            }
            
            tries--;
            cout<<"Tries left: "<<tries<<"\n\n";
        }

        if(tries <= 0){
            cout<<"Sorry, youre out of tries! The number was "<<mainNum<<".\n";
        }

        cout<<"Press 1 to play again, and any other key to exit. \n";
        cin>>trialNum;
        system("cls");
        if(trialNum == 1){
            setNumber();
            startGame();
        }else{
            cout<<"Thank you for playing. \n";
            return;
        }   
    }
};


int main()
{   
    Game game;
    game.setNumber();
    game.startGame();  
    system("pause");
    return 0;
}
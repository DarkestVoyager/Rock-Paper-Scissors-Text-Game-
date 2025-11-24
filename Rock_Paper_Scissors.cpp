#include <iostream>
#include <string>
#include <ctime> // time()
#include <cstdlib> // rand & srand()
#include <limits> // std::numeric_limits

// function delcarations
std::string who_Wins(const std::string& player, const std::string& computer);
bool player_Input();
void overall_Winner(unsigned short, unsigned short);
void blank();  
// global variables 
unsigned short _playerScore = 0;
unsigned short _computerScore = 0;
int main(){
    std::srand(std::time(0));
    // Variables
    bool _playing = true;
    std::string playerChoice;
    std::string computerChoices[] = {"rock", "paper", "scissors"};

    std::cout << "Welcome to Rock-Paper-Scissor!\n";

    while (_playing){
        
        while (true) { // Input validation loop
            std::cout << "Enter rock, paper, or scissors: \n";
            std::cin >> playerChoice;
            blank();
            if (playerChoice == "rock" || playerChoice == "paper" || playerChoice == "scissors") {
                break;
            } else {
                std::cerr << "Invalid input. Please enter 'rock', 'paper', or 'scissors'.\n";
            }
        }
        std::string computerChoice = computerChoices[rand() % 3]; // random choice for computer

        std::cout << who_Wins(playerChoice, computerChoice) << '\n';
        std::cout << "Computer Chose: " << computerChoice << " | You Chose: " << playerChoice << '\n'; blank();
        _playing = player_Input();
        system("cls"); // clears terminal after each round
        if(!_playing) break;
    }
    system("cls");  // This command is used to make the screen/terminal clear. Only the Scores and Overall Winner will be displayed
    std::cout << "Your Score: " << _playerScore << " | Computer Score: " << _computerScore << '\n';
    overall_Winner(_playerScore, _computerScore);

    blank();
    system("pause"); // It displays "Press any key to continue . . ." and waits for the user to press a key before closing the window. (windows only)
    return 0;

}

bool player_Input() {
    char Input;
    while (true) {
        std::cout << "Do you want to continue? y/n: \n" ;
        std::cin >> Input; blank();
        if (Input == 'y') return true;
        else if (Input == 'n') return false;
        else { // loops again
            std::cerr << "Invalid input. Please enter 'y' or 'n'.\n";
            std::cin.clear(); // clear error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard rest of line
        }
    }
}

std::string who_Wins(const std::string& player, const std::string& computer){
    if (player == computer) return "It's a Tie!";

    if ((player == "rock" && computer == "scissors") ||
        (player == "paper" && computer == "rock") ||
        (player == "scissors" && computer == "paper")) {
        _playerScore ++;
        return "You Win!";
    }
    _computerScore ++;
    return "You Lose!";
}

void overall_Winner(unsigned short x, unsigned short y){
    if(x == y) std::cout << "Overall, it's a tie.";
    else std::cout << ((x > y) ? "Overall Winner is You!" : "Overall Winner is the Computer.") ;
}

void blank(){ // leaves a blank line
     std::cout << std::endl;
}

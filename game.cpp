#include <iostream>
#include <random>

// Function to get a random choice for the computer
std::string getComputerChoice() {
    // Seed the random number generator
    std::random_device rd;
    std::mt19937 gen(rd());

    // Generate a random number between 1 and 3
    std::uniform_int_distribution<> dist(1, 3);
    int choice = dist(gen);

    // Return the corresponding choice
    if (choice == 1) {
        return "rock";
    } else if (choice == 2) {
        return "paper";
    } else {
        return "scissors";
    }
}

// Function to determine the winner
std::string determineWinner(std::string playerChoice, std::string computerChoice) {
    if (playerChoice == "rock") {
        if (computerChoice == "rock") {
            return "tie";
        } else if (computerChoice == "paper") {
            return "computer";
        } else {
            return "player";
        }
    } else if (playerChoice == "paper") {
        if (computerChoice == "rock") {
            return "player";
        } else if (computerChoice == "paper") {
            return "tie";
        } else {
            return "computer";
        }
    } else {
        if (computerChoice == "rock") {
            return "computer";
        } else if (computerChoice == "paper") {
            return "player";
        } else {
            return "tie";
        }
    }
}

int main() {
    while (true) {
        // Get the player's choice
        std::string playerChoice;
        std::cout << "Enter your choice (rock, paper, scissors, or quit): ";
        std::cin >> playerChoice;

        // Check if the player wants to quit
        if (playerChoice == "quit") {
            break;
        }

        // Get the computer's choice
        std::string computerChoice = getComputerChoice();

        // Determine the winner
        std::string winner = determineWinner(playerChoice, computerChoice);
        if (winner == "player") {
            std::cout << "You win! " << playerChoice << " beats " << computerChoice << std::endl;
        } else if (winner == "computer") {
            std::cout << "You lose! " << computerChoice << " beats " << playerChoice << std::endl;
        } else {
            std::cout << "It's a tie! Both choices were " << player

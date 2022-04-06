// Copyright (c) 2022 Hunter Connolly All rights reserved
// Created by: Hunter Connolly
// Created on: April 5, 2022
// This is a program that generates a random number
// and the user guesses a number, if the user enters something that is not 
// an integer than the program will know and let the user know


#include <iostream>
#include <random>
#include <string>


int main() {
    // declare variables
    int randomNumber, guessAsNumber;
    std::string guessAsString;

  std::random_device rseed;

  std::mt19937 rgen(rseed());  //  mersenne_twister

  std::uniform_int_distribution<int> idist(1, 9);  //  [0, 100]

  randomNumber = idist(rgen);


    // Get the guess from the user
    std::cout << "Enter a number between 1 and 9: ";
    std::cin >> guessAsString;
    std::cout << "" << std::endl;
    
    
    // switch the guess into an int and then check if it is a number and if 
    // it is correct or not
    try {
        guessAsNumber = std::stoi(guessAsString);
        if (guessAsNumber == randomNumber) {
            // display incorrect
            std::cout << "That is CORRECT! :)";
        } else {
            std::cout << "That is wrong! :(\n";
            std::cout << "The correct number was: " << randomNumber ;
    } 
    }catch (std::invalid_argument) {
        std::cout << "That is not a number! \n";
        std::cout << "The correct number was: " << randomNumber ;
    }
}

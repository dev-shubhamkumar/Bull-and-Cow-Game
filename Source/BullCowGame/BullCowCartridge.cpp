// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    // Setting up the game
    SetupGame();

    PrintLine(TEXT("The HiddenWord is: %s."), *HiddenWord); 
    
}


void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{   
    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else
    {
        if (Input == HiddenWord)
        {
            PrintLine(TEXT("You have Won!"));
            EndGame();
        }
        else
        {
            PrintLine(TEXT("Lost a life!"));
            PrintLine(TEXT("%i"), --Lives);
            if (Lives > 0)
            {
                if (Input.Len() != HiddenWord.Len()) 
                {
                    PrintLine(TEXT("Sorry, try guessing again! \nYou have %i lives remaining."), Lives);
                }
            }
            else
            {
                PrintLine(TEXT("You have no lives left!"));
                EndGame();
            }
            
        }
    }



    

    // Check if Isogram
    // Prompt to Guess Again
    // Check Right Number of Characters
    // Prompt to Guess Again

    // Remove Life

    // Check if Lives > 0
    // If yes "GuessAgain"
    // Show Lives Left
    // If no Show "GameOver" and "HiddenWord"
    // Prompt to play again, Press Enter to play again?
    // Check user input
    // PlayAgain or Quit
    
}

void UBullCowCartridge::SetupGame()
{
    PrintLine(TEXT("Welcome to Bull Cows!"));
    
    HiddenWord = TEXT("cakes");
    Lives = HiddenWord.Len();
    bGameOver = false;

    PrintLine(TEXT("Guess the %i letter word"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives."), HiddenWord.Len());
    PrintLine(TEXT("Type in your guess and \npress enter to continue..."));
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press enter to play again."));
}
#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <sstream>

int random(int min, int max){
    // Thank you to Stack overflow user 'Nawaz' and 'Pavan Manjunath' on stack overflow for this function: https://stackoverflow.com/questions/7560114/random-number-c-in-some-range
    bool isfirst = true;
    if(isfirst){
        srand(time(0));
        isfirst = false;
    }
    return min + rand() % ((max + 1) - min);
}

int main(void){
    using namespace std;

    cout << "Choose the low of the range:  ";
    int low;
    cin >> low;

    cout << "Choose the high of the range:  ";
    int hgh;
    cin >> hgh;

    //Call random function above
    int num = random(low, hgh);

    
    cout << "I have chosen a number between " << low << " and " << hgh <<  ". You have 3 guesses:  ";
    
    // Convert intager into string for comparison, as i type this i realise it could have just been inputed as a string, but oh well it is implemented now.
    stringstream numtotext;
    numtotext << num;
    string randstring;
    numtotext >> randstring;

    // User guess input
    string guess;
    cin >> guess;
    
    //Lives and boolean for while loop
    bool hasGuesses = false;
    int lives = 3;

    int halt;

    //cout << randstring << endl;  // <- to test if it is actually working

    while(!hasGuesses && lives > 1){
        if(guess.compare(randstring) == 0){
            cout << "Correct!";
            hasGuesses = true;
            cin >> halt;
        } else{
            cout << "Guess again";
            lives--;
            cin >> guess;
        }
    }
    return 0;
}
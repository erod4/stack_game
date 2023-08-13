// Enrique Rodriguez
// Chapter 19
// 04.11.23
#include "game.h"
#include <iostream>
#include <cctype>

using namespace std;

int menu(int &);
//delcaring functions
void push(Words &);

void pop(Words &);

void allCaps(Words &);

void display(Words &);

void story(Words &);

void exitFunc();

void error();

int main() {
  cout << "\nWelcome to Blank Frenzy: The Ultimate Cool Fill-in-the-Blank Game!\n\n";
  cout << "Instructions: Push a minimum of 5 words to your stack to fill in the blanks of a story. You can use pop to delete words from your stack and can also display all of the words in your stack. Capitalize your words before creating a story so they can stand out. Use option 5 to create a story using your word stack. \n\n";
  cout << "Story: __________ walked into the abandoned house, their heart pounding in their chest. As they stepped further into the darkness, they suddenly heard a __________ coming from the shadows, causing them to __________ and __________ before finally __________ the door behind them.\n\n";
  Words game;
  int choice = 0;
  //menu choice continues until user inputs option 6
  //game obj is passed to each function
  while (choice != 6) {
    choice = menu(choice);
    switch (choice) {
    case 1:
      push(game);
      break;
    case 2:
      pop(game);
      break;
    case 3:
      allCaps(game);
      break;
    case 4:
      display(game);
      break;
    case 5:
      story(game);
      break;
    case 6:
      exitFunc();
      break;
    default:
      error();
      break;
    }
  }
}

int menu(int &choice) {
  

  cout << "1. Push\n";
  cout << "2. Pop\n";
  cout << "3. All caps\n";
  cout << "4. Display words\n";
  cout << "5. Make story\n";
  cout << "6. Exit\n";

  // start menu above here
  cout << "\n\nPlease Enter an Option (1-6) and hit return: ";
  cin >> choice;
  return choice;
}

void push(Words &game) {
  string word;

  cout << "\n\nPlease Enter a word you would like added to word stack then hit return \nWord: ";
  cin >> word;
  cin.ignore();
  //validates word length if input is invalid asks user for new input
  while (word.length() > 10 || word.length() <= 0) 
  {
    cout << "Error: Word must be between 1-10 characters.\n";
    cout << "Enter Word: ";
    cin >> word;
    cin.ignore();
  }
  //calls pop function for game obj with users word choice
  game.push(word);
  cout << "\nThank you, word was added succesfully to word stack.\n\n";
}

void pop(Words &game) 
{
  //validates stack still contains words 
  if(game.sizeOf()==0)
  {
    cout<<"\nSorry, your word stack is empty. We suggest you add more words.\n\n";
  }
 else
  {
    //if words still in stack then it pops them off
  game.pop();
  cout << "\nThank you, word was deleted succesfully.\n\n";
  }
}

void allCaps(Words &game) 
{
    //validates stack still contains words 
  if(game.sizeOf()==0)
  {
    cout<<"\nSorry, your word stack is empty. We suggest you add more words.\n\n";
  }
 else
  {
    //if words still remain in stack then it capitalizes all words in stack
    game.toCaps();
  }
}

void display(Words &game) 
{
    //displays stack
    game.display();  
  
}

void story(Words &game)
{
  //pops users words from stack into story
  if(game.sizeOf()>=5)
  {
  game.story();
  }
  else
  {
    cout<<"\nSorry, you must have a minimum of 5 words in your stack before creating a story.\n\n";  
  }
}

void exitFunc() 
{
  cout<<"Exiting Application";
  for(int i=0;i<9;i++)
    {
      cout<<".";
    }
  exit(0);
}

void error() {
  cout << "\nSorry, incorrect option. Please try again.\n\n";
  
}

// Enrique Rodriguez
// Chapter 19
// 04.11.23
#ifndef GAME_H
#define GAME_H

#include <string>
#include <cctype>
using namespace std;


class Words
{
private:
  struct StackNode
{
  string word;
  StackNode *next;

};

StackNode *top;
  
public:
//constructor
  Words();
  int size=0;
string w;
//destructor
  ~Words();

  //Stack Operations
  void push(string);
  void pop();
  bool isEmpty() const;
  void toCaps();
  void display();
  void story();
  int sizeOf();
};
#endif

#include <iostream>
#include "game.h"
#include <cstring>
#include <cctype>

using namespace std;

Words::Words()//constructor
{
  top=nullptr;
}


Words::~Words()//destructor
{
  StackNode *nodePtr=nullptr;
  StackNode *nextNode=nullptr;
  //starts at top of stack
  nodePtr=top;

  //traverses list to delete each node
  while(nodePtr!=nullptr)
    {
      nextNode=nodePtr->next;
      delete nodePtr;
      nodePtr=nextNode;
    }
}
//member functions

void Words::push(string w)
{
  //length validation
  if(w.length()>10||w.length()<=0)
  {
    exit(EXIT_FAILURE);
  }


  
  StackNode *newNode=nullptr;//points to new node

  newNode= new StackNode; //creates a new stack node
  newNode->word=w;  //stores word into stack node

  //if stack is empty make new stack head and have it point to null
  if(isEmpty())
  {
    top=newNode;
    size=1;
    newNode->next=nullptr;
  }
    //otherwise the new stack node becomes new top node
  else
  {
    size++;
    newNode->next=top;
    top=newNode;
  }
}
void Words::pop()
{
  StackNode *temp=nullptr;

  if(isEmpty())
  {
    exit(EXIT_FAILURE);
  }
  else
  {
    w=top->word;  
    temp=top->next;//holds next node below top node
    delete top;//pops off top node
    size--;
    top=temp;//node below the top node becomes new node
  }
}

bool Words::isEmpty()const
{
  bool empty;

  if(!top)// checks if stack is empty and returns t or f
  {
    empty=true;
  }
  else
  {
    empty=false;
  }
  return empty;
}

void Words::toCaps()
{
  //temp pointer starts at top of stack
  StackNode *temp;
  temp=top;
  if(!temp)
  {
    exit(EXIT_FAILURE);
  }
  //iterates through each character of string and capitalizes 
  while(temp!=nullptr)
    {

      if(temp->word.length()<=0||temp->word.length()>10)
      {
        exit(EXIT_FAILURE);
      }
      for(int i=0; i<temp->word.length();i++)
        {
          temp->word[i]=toupper(temp->word[i]);
        }
      //goes to next stack node
      temp=temp->next;
      
    }
  
}

void Words::display()
{
  
  //starts at top of stack
    StackNode *display;
    display=new StackNode;
    display=top;
    //if stack is empty prompt user to add words
    if(display==nullptr)
    {
      cout<<"\n\nThere are currently no words in stack. Please select option 2\n";
      
    }
    else
    {
      cout<<"\nList of Words:\n";
      //iterates until reaching end of stack and displays each word
    while(display!=nullptr)
      {
        
        cout<<display->word<<endl;
        display=display->next;
      }
    }
      cout<<endl;
}
void Words::story()
{
  if(size>=5)
  {
    pop();
    cout<<endl<<w<<" walked into the abandoned house, their heart pounding in their chest. As they stepped further into the darkness, they suddenly heard a " ;
    pop();
    cout<<w<<" coming from the shadows, causing them to ";
    pop();
    cout<<w<<" and ";
    pop();
    cout<<w<<" before finally ";
    pop();
    cout<<w<<" the door behind them.\n\n";
  }
  
}
int Words::sizeOf()
{
  return size;
}

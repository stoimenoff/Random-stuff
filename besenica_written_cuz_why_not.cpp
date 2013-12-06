#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include <dos.h>
#include <conio.h>
#include<windows.h>

using namespace std;
string words[]={"patka" , "slon" , "hippopotam"};
int howManyDidIGuessed=0;
int tries=11,pos=0;
char usedLetters[11];
char input;
int selectRandomWord(){
    srand( time(0));
    int k=rand()%3;
    while(words[k]=="0")
        k=rand()%3;
    return k;
}
void printWord(string word, bool rletters[]){
    for(int i=0;i<word.size();i++)
    {
        if(rletters[i]==0)
            cout<<"_ ";
        else
            cout<<word[i];
    }
    cout<<endl;
}
bool didIusedThatLetter(char input, int lenght){
     for(int i=0;i<lenght;i++)
        {
            if(usedLetters[i]==input)
            return 1;
        }
     return 0;
}
void letterRecognising(string word,bool rletters[],char playerInput){
    for(int i=0;i<word.size();i++)
        {
            if(playerInput==word[i]&&didIusedThatLetter(playerInput,11)==0)
                {
                    rletters[i]=1;
                    howManyDidIGuessed++;
                }
        }
}
void play(string word, bool reviewedLetters[]){
    howManyDidIGuessed=0;
    tries=11;
    system("cls");
    for(int i=0;i<tries;i++)
    {
        usedLetters[i]=66;
    }
    while(tries>0)
    {
        printWord(word,reviewedLetters);
        cout<<"Enter a letter ... ";
        cin>>input;
        while(input>122||input<97)
        {
            cout<<"Wrong input!!! Please enter a LETTER ..."<<endl;
            cin>>input;
        }
        cout<<endl;
        letterRecognising(word, reviewedLetters, input);
        if(didIusedThatLetter( input, 11)==0){
        tries--;
        usedLetters[pos]=input;
        pos++;
        }
        if(howManyDidIGuessed==word.size())
        {
            printWord(word,reviewedLetters);
            cout<<"You won the game!!! Congrats!"<<endl;
            Sleep(1500);
            break;
        }
    }
    if(tries==0&&howManyDidIGuessed!=word.size()){
        cout<<"You lost the game. Sorry."<<endl;Sleep(1500);}
}
int main()
{
srand( time(0));
int numberOfUsedWords=0;
while(numberOfUsedWords<3)
{
    int randomWord=selectRandomWord();
    string word=words[randomWord];
    words[randomWord]="0";
    numberOfUsedWords++;
    bool reviewedLetters[word.size()];
    for(int i=0;i<word.size();i++)
        reviewedLetters[i]=0;
    cout<<"IMPORTANT:CAPITAL LETTERS ARE NOT ALLOWED AND WILL NOT BE RECOGNISED AS AN INPUT"<<endl<<endl<<endl;
    play(word, reviewedLetters);
}
cout<<endl<<endl<<"GAME OVER!!!"<<endl;
}


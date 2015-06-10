#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
int field[4][4];
int score = 0;
void initialize_board(){
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            field[i][j] = 0;
}
void new_element(){
    srand(time(NULL));
    int position = rand()%16;
    int x = position/4;
    int y = position%4;
    while(field[x][y] != 0){
        position = rand()%16;
        x = position/4;
        y = position%4;
    }
    int number = rand()%2 +1;
    field[x][y] = number*2;
}
int digits(int x){
    int num=0;
    while(x>0){
        x/=10;
        num++;
    }
    if(num == 0)
        num++;
    return num;
}
void change_console_background_color(int x){
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int color = 15;
    switch(x){
        case 2: color = 112;break;
        case 4: color = 128;break;
        case 8: color = 80;break;
        case 16: color = 96;break;
        case 32: color = 64;break;
        case 64: color =192;break;
        case 128: color = 96;break;
        case 256: color = 224;break;
        case 512: color = 32;break;
        case 1024: color = 160;break;
        case 2048: color = 144;break;
    }
    SetConsoleTextAttribute(hConsole, color);
}
void print_row(int i){
    cout<<"|";
    for(int j=0;j<4;j++){
        change_console_background_color(field[i][j]);
        int digitsnum = digits(field[i][j]);
            if(digitsnum == 1){
                cout<<"    "<<field[i][j]<<"   ";
            }
            if(digitsnum == 2){
                cout<<"   "<<field[i][j]<<"   ";
            }
            if(digitsnum == 3){
                cout<<"   "<<field[i][j]<<"  ";
            }
            if(digitsnum == 4){
                cout<<" "<<field[i][j]<<" ";
            }
        change_console_background_color(0);
        cout<<"|";
    }
    cout<<endl;
}
void color_print_help_function(int color, char symbol){
    change_console_background_color(color);
    for(int i=0;i<8;i++){
        cout<<symbol;
    }
    change_console_background_color(0);
    cout<<"|";
}
void print_color_row(int i, char symbol){
    cout<<"|";
    color_print_help_function(field[i][0], symbol);
    color_print_help_function(field[i][1], symbol);
    color_print_help_function(field[i][2], symbol);
    color_print_help_function(field[i][3], symbol);
    cout<<endl;
}
void print_board(){
    cout<<" ________ ________ ________ ________"<<endl;
    for(int i=0;i<4;i++){
        print_color_row(i, ' ');
        print_color_row(i, ' ');
        print_row(i);
        print_color_row(i, ' ');
        print_color_row(i, '_');
    }
    cout<<endl<<"Score : "<<score<<endl;
}
void move_up(){
    for(int j=0;j<4;j++){
        int mover[4]={0,0,0,0};
        int counter = 0;
        for(int i=0;i<4;i++){
            if(field[i][j] != 0){
                mover[counter] = field[i][j];
                counter++;
                field[i][j]=0;
            }
        }
        for(int i=0;i<3;i++){
            if(mover[i] == mover[i+1]){
                mover[i] *= 2;
                mover[i+1] = 0;
                score += mover[i];
            }
        }
        counter = 0;
        for(int i=0;i<4;i++){
            if(mover[i] != 0){
                field[counter][j] = mover[i];
                counter++;
            }
        }
    }
}
void rotate_left(){
    int field_cache[4][4];
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            field_cache[i][j] = field[i][j];
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
             field[3-j][i] = field_cache[i][j];
}
void up(){
    int field_cache[4][4];
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            field_cache[i][j] = field[i][j];
    move_up();
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(field_cache[i][j] != field[i][j]){
                new_element();
                i=4;
                j=4;
            }
        }
    }
}
void down(){
    int field_cache[4][4];
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            field_cache[i][j] = field[i][j];
    rotate_left();
    rotate_left();
    move_up();
    rotate_left();
    rotate_left();
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(field_cache[i][j] != field[i][j]){
                new_element();
                i=4;
                j=4;
            }
        }
    }
}
void left(){
    int field_cache[4][4];
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            field_cache[i][j] = field[i][j];
    rotate_left();
    rotate_left();
    rotate_left();
    move_up();
    rotate_left();
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(field_cache[i][j] != field[i][j]){
                new_element();
                i=4;
                j=4;
            }
        }
    }
}
void right(){
    int field_cache[4][4];
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            field_cache[i][j] = field[i][j];
    rotate_left();
    move_up();
    rotate_left();
    rotate_left();
    rotate_left();
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(field_cache[i][j] != field[i][j]){
                new_element();
                i=4;
                j=4;
            }
        }
    }
}
bool player_is_dead(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(field[i][j] == 0 || field[i+1][j] == 0 || field[i][j+1] == 0 || field[i+1][j+1] == 0){
                return false;
            }
            if(field[i][j] == field[i][j+1] || field[i][j] == field[i+1][j]){
                return false;
                break;
            }
        }
    }
    for(int j=0;j<3;j++){
        if(field[3][j] == field[3][j+1] || field[j][3] == field[j+1][3]){
            return false;
            break;
        }
    }
    return true;
}
int main(){
    bool up_arrow_is_locked = false, down_arrow_is_locked = false, right_arrow_is_locked = false, left_arrow_is_locked = false;
    initialize_board();
    new_element();
    new_element();
    print_board();
    while(1){
        if( (GetAsyncKeyState( VK_UP ) & 0x8000) && !up_arrow_is_locked){
            up();
            system("cls");
            print_board();
            up_arrow_is_locked = true;
        }
        else{
            if(!(GetAsyncKeyState( VK_UP ) & 0x8000)){
                up_arrow_is_locked = false;
            }
        }
        if( (GetAsyncKeyState( VK_DOWN ) & 0x8000) && !down_arrow_is_locked){
            down();
            system("cls");
            print_board();
            down_arrow_is_locked = true;
        }
        else{
            if( !(GetAsyncKeyState( VK_DOWN ) & 0x8000)){
                down_arrow_is_locked = false;
            }
        }
        if( (GetAsyncKeyState( VK_LEFT ) & 0x8000) && !left_arrow_is_locked){
            left();
            system("cls");
            print_board();
            left_arrow_is_locked = true;
        }
        else{
            if(!(GetAsyncKeyState( VK_LEFT ) & 0x8000)){
                left_arrow_is_locked = false;
            }
        }
        if( (GetAsyncKeyState( VK_RIGHT ) & 0x8000) && !right_arrow_is_locked){
            right();
            system("cls");
            print_board();
            right_arrow_is_locked = true;
        }
        else{
            if(!(GetAsyncKeyState( VK_RIGHT ) & 0x8000)){
                right_arrow_is_locked = false;
            }
        }
        if(player_is_dead()){
            break;
        }
    }
    system("pause");
    return 0;
}

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
int snake_positions[256];
int direction = 1;
char field[16][16];
int apple = 124;
bool dead = false;
void initialize_snake(){
    for(int i=0;i<256;i++){
        if(i<3){
            snake_positions[i] = i;
        }
        else{
            snake_positions[i] = 256;
        }
    }
}
void initialize_field(){
    for(int i=0;i<16;i++){
        for(int j=0;j<16;j++){
            field[i][j] = ' ';
        }
    }
}
void generate_apple(){
    bool positions[256];
    for(int i=0;i<256;i++){
        positions[i] = 1;
        if(i<256 && snake_positions[i] != 256){
            positions[ snake_positions[i] ] = 0;
        }
    }
    srand(time(NULL));
    int random_position = rand()%256;
    while(positions[random_position] == 0){
        random_position = rand()%256;
    }
    apple = random_position;
    field[ apple/16 ][ apple%16 ] = '*';
}
void move_snake(){
    if(snake_positions[0] != apple){
        field[ snake_positions[0]/16 ][ snake_positions[0]%16 ] = ' ';
        for(int i=0;i<255;i++){
            snake_positions[i] = snake_positions[i+1];
        }
    }
    else{
        generate_apple();
    }
    for(int i=0;i<256;i++){
        if(snake_positions[i] == 256){
            snake_positions[i] = snake_positions[i-1] + direction;
            if(snake_positions[i-1]%16 == 15 && direction == 1){
                snake_positions[i] -= 16;
            }
            if(snake_positions[i-1]%16 == 0 && direction == -1){
                snake_positions[i] += 16;
            }
            if(snake_positions[i-1] <= 15 && direction == -16){
                snake_positions[i] += 256;
            }
            if(snake_positions[i-1] >= 240 && direction == 16){
                snake_positions[i] -= 256;
            }
            break;
        }
    }
    for(int i=0;i<256;i++){
        if(snake_positions[i] == 256){
            break;
        }
        for(int j=i+1;j<256;j++){
            if(snake_positions[i] == snake_positions[j])
                dead = true;
        }
    }
    for(int i=0;i<256;i++){
        if(snake_positions[i] == 256){
            break;
        }
        if(snake_positions[i+1] == 256){
            field[ snake_positions[i]/16 ][ snake_positions[i]%16 ] = '0';
        }
        else{
            field[ snake_positions[i]/16 ][ snake_positions[i]%16 ] = 'O';
        }
    }
}
void change_direction(char arrow){
    if(arrow == 'U' && direction != 16)
        direction = -16;
    if(arrow == 'D' && direction != -16)
        direction = 16;
    if(arrow == 'L' && direction != 1)
        direction = -1;
    if(arrow == 'R' && direction != -1)
        direction = 1;
}
void print_field(){
    for(int i=0;i<16;i++){
        for(int j=0;j<16;j++){
            cout<<field[i][j];
        }
        cout<<endl;
    }
}
int main(){
    bool up_arrow_is_locked = false, down_arrow_is_locked = false, right_arrow_is_locked = false, left_arrow_is_locked = false;
    initialize_field();
    initialize_snake();
    generate_apple();
    print_field();
    int counter = 0;
    while(1){
        counter++;
        if(counter == 50000){
            //move snake
            move_snake();
            system("cls");
            print_field();
            counter = 0;
        }
        if( (GetAsyncKeyState( VK_UP ) & 0x8000) && !up_arrow_is_locked){
            //do stuff for up arrow
            change_direction('U');
            up_arrow_is_locked = true;
        }
        else{
            if(!(GetAsyncKeyState( VK_UP ) & 0x8000)){
                up_arrow_is_locked = false;
            }
        }
        if( (GetAsyncKeyState( VK_DOWN ) & 0x8000) && !down_arrow_is_locked){
            //do stuff for down arrow
            change_direction('D');
            down_arrow_is_locked = true;
        }
        else{
            if( !(GetAsyncKeyState( VK_DOWN ) & 0x8000)){
                down_arrow_is_locked = false;
            }
        }
        if( (GetAsyncKeyState( VK_LEFT ) & 0x8000) && !left_arrow_is_locked){
            //do stuff for left arrow
            change_direction('L');
            left_arrow_is_locked = true;
        }
        else{
            if(!(GetAsyncKeyState( VK_LEFT ) & 0x8000)){
                left_arrow_is_locked = false;
            }
        }
        if( (GetAsyncKeyState( VK_RIGHT ) & 0x8000) && !right_arrow_is_locked){
            //do stuff for right arrow
            change_direction('R');
            right_arrow_is_locked = true;
        }
        else{
            if(!(GetAsyncKeyState( VK_RIGHT ) & 0x8000)){
                right_arrow_is_locked = false;
            }
        }
        if(dead){
            break;
        }
    }
    cout<<"GAME OVER"<<endl;
    system("pause");
    return 0;
}

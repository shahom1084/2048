#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int grid[4][4]={ 0 };
int random_tile(int grid[][]){
    srand(time(nullptr));
    int x=rand()%4;
    srand(time(nullptr));
    int y=rand()%4;
    srand(time(nullptr));
    int num=rand()%2;
    if(num%2==0){
        grid[x][y]=2;
    }
    else{
        grid[x][y]=4;
    }



}
int main() {
    return 0;
}
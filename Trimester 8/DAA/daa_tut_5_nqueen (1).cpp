#include<iostream>
using namespace std;

bool check(int arr[100][100], int n, int x, int y){
    for(int row=0; row<n; row++){
        if(arr[row][y] == 1)
            return false;
    }

    int row = x, col = y;

    while(row >= 0 && col >= 0){
        if(arr[row][col] == 1)
            return false;
        row--; col--;
    }
    row = x; col = y;

    while(row >=0 && col < n){
        if(arr[row][col] == 1)
            return false;
        row--; col++;
    }

    return true;
}

void display(int arr[100][100], int n, int sol){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }
}

bool nqueen(int arr[100][100], int n, int x, int &sol_n){
    if(x >= n){
        sol_n++;
        cout<<"Solution No. : "<<sol_n<<endl;
        display(arr, n, sol_n);
    }

    for(int i = 0; i<n; i++){
        if(check(arr, n, x, i)){
            arr[x][i] = 1;
            if(nqueen(arr, n, x+1, sol_n))
                return true;
        }
        arr[x][i] = 0;
    }

    return false;

}

int main(){
    int arr[100][100],n;
    cout<<"Enter the number of rows : ";
    cin>>n;
    int sol_n = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            arr[i][j] = 0;
        }
    }
    nqueen(arr, n, 0, sol_n);
return 0;
}
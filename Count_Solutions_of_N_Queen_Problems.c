#include<stdio.h>
#include<stdbool.h>
int n;

bool isSafe(int b[n][n], int row, int col);

int setQueen(int b[n][n], int col);

int main(){
    scanf("%d", &n);
    int b[n][n];
    // đặt mặc định là 0
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            b[i][j] = 0;
        }
    }
    int count = setQueen(b, 0);
    printf("%d", count);
}

// xét vị trí đặt quân hậu theo cột
bool isSafe(int b[n][n], int row, int col)
{
    int i, j;
    // hàng ngang
    for(i = 0; i < col; i++){
        if(b[row][i] == 1){
            return false;
        }
    }
    // Kiểm tra đường chéo trên
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (b[i][j] == 1) {
            return false;
        }
    }

    // Kiểm tra đường chéo dưới
    for (i = row, j = col; j >= 0 && i < n; i++, j--) {
        if (b[i][j] == 1) {
            return false;
        }
    }
    return true;
}

int setQueen(int b[n][n], int col)
{
    if(col >= n){
        return 1;
    }
    int count = 0;
    // vòng lặp xét từng hàng i của cột col
    for(int i = 0; i < n; i++){
        if(isSafe(b, i, col)){
            b[i][col] = 1; // đặt hậu
            
            count += setQueen(b, col+1); // tiếp tục vs cột tiếp theo

            b[i][col] = 0; // nếu không thỏa mãn 1 cột thì đặt là 0 và tiếp tục hàng tiếp theo
        }
    }
    return count;
}

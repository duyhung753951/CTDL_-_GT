#include<stdio.h>
#include<stdbool.h>
void input(int a[], int n);
int longestUniqueSubsttr(int a[], int n);
int Max(int a, int b);
int n;
int main(){
    scanf("%d", &n);
    int a[n];
    input(a, n);
    int longest = longestUniqueSubsttr(a, n);
    printf("%d", longest);
}

void input(int a[], int n)
{
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
}

int longestUniqueSubsttr(int a[], int n)
{
    /* gọi ra 1 mảng "visited" để đánh dấu các số đã gặp trong dãy
       bằng cách đưa số đấy thành 1 index trong visited
       vd: 4 7 3 8 4
       với i = 0 -> visited[a[i]] = visited[4]
       với i = 1 -> visited[a[i]] = visited[7]
       với cách này ta có thể kiểm tra liệu số đó đã lặp lại hay chưa
       bằng cách đưa mọi giá trị visited[] về "false" và những số đã xuất hiện là "true"*/ 
    
    int visited[32767];
    int max = 0;
    for(int i = 0; i < n; i++){
        // đưa mọi phần tử hàm visited về false
        for(int v = 0; v < 32767; v++){
            visited[v] = false;
        }
        for(int j = i; j < n; j++){
            // check nếu số đã được visited thì break
            if(visited[a[j]] == true){
                break;
            }
            // else cập nhật max nếu window larger và đánh dấu số này đã được visited
            else{
                max = Max(max, j-i+1);
                visited[a[j]] = true;
            }
        }
        // loại bỏ các giá trị trước window
        visited[a[i]] = false;
    }
    return max;
}

int Max(int a, int b)
{
    if(a > b) return a;
    else return b;
}

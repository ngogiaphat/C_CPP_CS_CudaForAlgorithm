#include <stdio.h>
#include <string.h>
int countBeautifulStrings(char *str, int L, int R){
    int count = 0;
    int maxCount = 0;
    for(int i = L - 1; i < R; i++){
        if(str[i] == '1'){
            count++;
            if(count > maxCount){
                maxCount = count;
            }
        } 
        else {
            count = 0;
        }
    }
    return maxCount;
}
int main(){
    char str[10000];
    int q;
    printf("Nhap vao chuoi goc: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;
    printf("Nhap vao so luong cau hoi: ");
    scanf("%d", &q);
    fflush(stdin);
    for(int i = 0; i < q; i++){
        int type, L, R;
        printf("Nhap vao loai cau hoi (1 hoac 2): ");
        scanf("%d", &type);
        if(type == 1){
            char c;
            printf("Nhap vao ki tu: ");
            scanf(" %c", &c);
            int count = 0;
            for(int j = 0; j < strlen(str); j++){
                if(str[j] == c){
                    count++;
                }
            }
            printf("So luong ki tu %c trong chuoi la: %d", c, count);
        } 
        else if(type == 2){
            printf("Nhapi L: ");
            scanf("%d", &L);
            printf("Nhap R: ");
            scanf("%d", &R);
            int beautifulCount = countBeautifulStrings(str, L, R);
            printf("So luong chuoi dep nhat la: %d", beautifulCount);
        }
    }
    return 0;
}
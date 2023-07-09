#include <iostream>
#include <string>
#include <vector>
int countBeautifulStrings(const std::string& str, int L, int R){
    int count = 0;
    int maxCount = 0;
    for(int i = L - 1; i < R; i++){
        if (str[i] == '1'){
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
    std::string str;
    int q;
    std::cout << "Nhap chuoi goc: ";
    std::getline(std::cin, str);
    std::cout << "Nhap vao so luong cau hoi: ";
    std::cin >> q;
    std::cin.ignore();
    for(int i = 0; i < q; i++){
        int type, L, R;
        std::cout << "Nhap loai cau hoi: ";
        std::cin >> type;
        if(type == 1){
            char c;
            std::cout << "Nhap vao ki tu: ";
            std::cin >> c;
            std::cin.ignore();
            int count = 0;
            for(char ch : str){
                if(ch == c){
                    count++;
                }
            }
            std::cout << "So luong ki tu " << c << " trong chuoi la: " << count << std::endl;
        } 
        else if(type == 2){
            std::cout << "Nhap vao L: ";
            std::cin >> L;
            std::cout << "Nhap vao R: ";
            std::cin >> R;
            std::cin.ignore();
            int beautifulCount = countBeautifulStrings(str, L, R);
            std::cout << "So luong chuoi dep nhat la: " << beautifulCount << std::endl;
        }
    }
    return 0;
}
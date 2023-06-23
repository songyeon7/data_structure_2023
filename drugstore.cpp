#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

const int MAX_MEDICINES = 30;
const int NUM_MEDICINES = 5;

string medicines[NUM_MEDICINES] = { "해열제", "항생제", "소화제", "소염제", "멀미약" };
int quantities[NUM_MEDICINES] = { 0, 0, 0, 0, 0 };

void displayMedicineList() {
    cout << "< 약물 목록 > " << endl;
    for (int i = 0; i < NUM_MEDICINES; i++) {
        cout << i + 1 << ". " << medicines[i] << " (" << quantities[i] << "개)" << endl;
    }
}

void displayMedicine() {
    cout << "약물 목록:" << endl;
    for (int i = 0; i < NUM_MEDICINES; i++) {
        cout << i + 1 << ". " << medicines[i] << endl;
    }
}

int findMedicineIndex(string medicine) {
    for (int i = 0; i < NUM_MEDICINES; i++) {
        if (medicines[i] == medicine) {
            return i;
        }
    }
    return -1;
}

void addMedicine(string medicine, int quantity) {
    int index = findMedicineIndex(medicine);
    if (index != -1) {
        if (quantities[index] + quantity <= MAX_MEDICINES) {
            quantities[index] += quantity;
            cout << medicine << "을(를) " << quantity << "개 추가하였습니다." << endl;
        }
        else {
            cout << "약물의 최대 개수를 초과하여 추가할 수 없습니다." << endl;
        }
    }
    else {
        cout << "해당 약물은 목록에 존재하지 않습니다." << endl;
    }
}


void buyMedicine(string medicine, int quantity) {
    int index = findMedicineIndex(medicine);
    if (index != -1) {
        if (quantities[index] >= quantity) {
            quantities[index] -= quantity;
            cout << medicine << "을(를) " << quantity << "개 판매하였습니다." << endl;
        }
        else {
            cout << "약물의 재고가 부족합니다." << endl;
        }
    }
    else {
        cout << "해당 약물은 목록에 존재하지 않습니다." << endl;
    }
}

int main() {
    while (true) {
        system("pause");
        system("cls");
        cout << "[ 1. 약물 추가 / 2. 약물 판매 / 3. 약물 검색 / 4. 종료 ]\n입력 >> ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            string medicine;
            int quantity;
            system("cls");
            displayMedicineList();
            cout << "추가할 약물과 수량을 입력하세요 >> ";
            cin >> medicine >> quantity;
            addMedicine(medicine, quantity);
        }
        else if (choice == 2) {
            string medicine;
            int quantity;
            system("cls");
            displayMedicine();
            cout << "판매할 약물과 수량을 입력하세요 >> ";
            cin >> medicine >> quantity;
            buyMedicine(medicine, quantity);
        }
        else if (choice == 3) {
            string medicine;
            system("cls");
            displayMedicine();
            cout << "검색할 약물을 입력하세요 >> ";
            cin >> medicine;
            int index = findMedicineIndex(medicine);
            if (index != -1) {
                cout << medicine << "의 재고는 " << quantities[index] << "개입니다." << endl;
            }
            else {
                cout << "해당 약물은 목록에 존재하지 않습니다." << endl;
            }
        }
        else if (choice == 4) {
            break;
        }
        else {
            cout << "유효하지 않은 선택입니다. 다시 선택하세요." << endl;
        }
    }
}

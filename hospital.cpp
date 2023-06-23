#include <iostream>
#include <string.h>
#include <string>
#include <Windows.h>

// 최대 환자는 100명으로 제한
#define MAX_PATIENT 100
using namespace std;

// 환자 구조체
struct Patient {
    std::string name;
    int age;
    std::string address;
    std::string birthdate;
    double height;
    double weight;
};

// 진료과목의 이름, 설명을 저장하는 구조체
struct Department {
    string name;
    string explain;
};

// 변수
int front = -1;
int rear = 0;
Patient patientList[MAX_PATIENT];
int cnt = 0;

// 진료과목 정보들...
Department departments[10] = {
        { "외과", "외상, 종양, 선천성 이상 등에 대한 수술을 담당하는 학과입니다."},
        { "내과", "내부 질환에 대한 진단과 치료를 담당하는 학과입니다. 심혈관계, 호흡기, 소화기, 신장, 내분비 등 다양한 분야를 다룹니다."},
        { "흉부외과", "흉곽 내 각종 질환에 대한 진단과 치료를 담당하는 학과입니다. 흉부 수술과 관련된 전문성을 가지고 있습니다."},
        { "정형외과", "골절, 관절염, 척추질환 등에 대한 진단과 치료를 담당하는 학과입니다. 스포츠재활 등도 담당합니다."},
        { "신경외과", "뇌, 척추, 신경근계통 질환에 대한 진단과 치료를 담당하는 학과입니다. 뇌출혈, 뇌졸중 등 심각한 질환도 다룹니다."},
        { "산부인과", "여성의 생식기계 질환 및 임신 출산에 대한 진단과 치료를 담당하는 학과입니다."},
        { "비뇨기과", "신장, 요로 감염, 전립선 질환 등에 대한 진단과 치료를 담당하는 학과입니다."},
        { "이비인후과", "귀, 코, 목의 질환에 대한 진단과 치료를 담당하는 학과입니다. 후각, 맛, 발음 등의 기능을 담당합니다."},
        { "소아청소년과", "어린이와 청소년의 건강에 대한 진단과 치료를 담당하는 학과입니다. 성장 발달, 영양, 질병 예방 등을 다룹니다."},
        { "응급의학과", "급성 질환, 중증 외상 등 긴급한 상황에서 환자를 구조하고 치료하는 학과입니다. 응급치료에 대한 전문성을 가지고 있습니다."}
};

// 진료과목 함수
int info() {
    while (1) {
        int section, answer;

        while (1) {
            system("cls");

            cout << "현재 우리 병원에는 다음과 같은 과들이 있습니다.\n\n";
            for (int i = 0; i < 10; i++) {
                cout << i + 1 << ". " << departments[i].name << endl;
            }

            cout << "\n알아보고자 하는 과의 번호를 입력해주세요: ";
            cin >> section;

            if (section >= 1 && section <= 10) {
                break;
            }
            else {
                cout << "잘못된 입력입니다. 다시 시도해주세요." << endl;
                system("pause");
                continue;
            }
        }

        cout << "\n요청하신 과의 정보입니다:\n";
        cout << departments[section - 1].explain << endl;

        cout << "\n추가로 알아보고 싶으신 과가 있으십니까? ( YES : 1 | NO : 0 ) : ";
        cin >> answer;
        
        switch (answer) {
            case 1:
                continue;
            case 0:
                cout << "메인으로 돌아갑니다." << endl;
                system("pause");
                system("cls");
                return 0;
        }
    }
}

void Treat_recep() {
    if (cnt < MAX_PATIENT) {
        Patient patient;
        
        char name[20];
        cout << "환자 이름: ";
        cin >> name;
        patient.name = name;

        cout << "환자 나이: ";
        cin >> patient.age;
        cin.ignore();

        cout << "환자 주소: ";
        getline(std::cin, patient.address);

        cout << "생년월일: ";
        getline(std::cin, patient.birthdate);

        cout << "키 (cm): ";
        cin >> patient.height;
        cin.ignore();

        cout << "몸무게 (kg): ";
        cin >> patient.weight;
        cin.ignore();

        patientList[rear] = patient;
        rear = rear + 1;
        cout << "\n" << patient.name << " 환자 접수 완료." << endl;
        cnt = cnt + 1;
        cout << "접수 인원 [ " << cnt << " / 100 ]" << "\n\n";
    }
    else {
        cout << "접수 마감되었습니다.\n\n";
    }
    system("pause");
    system("cls");
}

void Treat_comp() {
    if (front + 1 == rear) {
        cout << "\n아직 환자가 없습니다..\n\n" << endl;
        system("pause");
        system("cls");
        return;
    }
    cout << "\n" << patientList[front + 1].name << " 환자 진료 완료.\n\n" << endl;
    front = front + 1;
    system("pause");
    system("cls");
}

// 대기열
void waiting() {
    int num = 1;
    system("cls");
    cout << "======== OOO병원 대기현황 ========\n\n";
    for (int i = front + 1; i < rear; i++) {
        cout << num << ". " << patientList[i].name << endl;
        num++;
    }
    cout << "\n\n";
    system("pause");
    system("cls");
}

int main() {
    while (1) {
        int choose;

        cout << "========== 선린병원 프로그램 ==========\n\n";
        cout << "[1. 진료접수 / 2. 진료완료 / 3. 환자대기열 / 4. 진료과목 / 5. 종료]\n\n";
        cout << "입력 >> ";
        cin >> choose;

        switch (choose) {
            case 1:
                Treat_recep();
                break;
            case 2:
                Treat_comp();
                break;
            case 3:
                waiting();
                break;
            case 4:
                info(); // 진료과목 함수
                break;
            case 5:
                cout << "프로그램을 종료합니다." << endl;
                exit(0);
            default:
                cout << "잘못된 입력입니다." << endl;
                system("pause");
                system("cls");
        }
    }
}

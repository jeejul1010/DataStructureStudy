// Study07.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//삽입정렬 //풀스왑 //하프스왑

#include <iostream>
const int MAX = 5;

void insertionFullSort(int data[], int num);
void print(int data[], int num);
void insertionHalfSort(int data[], int num);

int main()
{
    int data[MAX] = { 22,37,15,19,12 };
    print(data, MAX);
    insertionFullSort(data, MAX);
    print(data, MAX);
    insertionHalfSort(data, MAX);
    print(data, MAX);
    std::cout << "Hello World!\n";
}

void insertionFullSort(int data[], int num)
{
    for (int current = 1; current <= num - 1; current++)
    {
        int pick = current;
        while (pick >= 1)
        {
            if (data[pick-1] > data[pick])
            {
                int temp = data[pick];
                data[pick] = data[pick-1];
                data[pick-1] = temp;
                pick--;
            }
            else
            {
                break;
            }
        }
    }
}

void insertionHalfSort(int data[], int num)
{
    for (int current = 1; current <= num - 1; current++)
    {
        int pick = current;
        int temp = data[pick];

        for (; pick > 0 && data[pick - 1] > temp; pick--)
        {
            data[pick] = data[pick - 1];
        }
        data[pick] = temp;

    }
}

void print(int data[], int num)
{
    for (int i = 0; i < num; i++)
    {
        std::cout << data[i] << ' ';
    }
    std::cout << std::endl;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.

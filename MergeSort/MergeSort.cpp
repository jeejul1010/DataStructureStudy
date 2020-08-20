// MergeSort.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
const int MAX = 9;

void MergeSort(int data[], int first, int last);
void Merge(int data[], int first, int middle, int last);
void print(int data[], int num);

int main()
{
    int data[MAX] = { 12,14,19,27,38,5,16,18,20 };
    print(data, MAX);
    MergeSort(data, 0, MAX - 1);
    print(data, MAX);
    std::cout << "Hello World!\n";
}

void MergeSort(int data[], int first, int last)
{
    if (first < last)
    {
        int middle = (first + last) / 2;
        MergeSort(data, first, middle);
        MergeSort(data, middle + 1, last);
        Merge(data, first, middle, last);
    }
    
}

void Merge(int data[], int first, int middle, int last)
{
    int temp[MAX] = { 0, };


    int first1 = first;
    int last1 = middle;
    int first2 = middle + 1;
    int last2 = last;
    int index = first1;

    for (; (first1 <= last1)&& (first2 <= last2);)
    {
        if (data[first1] < data[first2])
        {
            temp[index++] = data[first1];
            first1++;
        }
        else
        {
            temp[index++] = data[first2];
            first2++;
        }
    }


    for (; first2 <= last2; first2++)
    {
        temp[index++] = data[first2];
    }

 
    for (; first1 <= last1; first1++)
    {
        temp[index++] = data[first1];
    }

    for (int i = first; i <= last; i++)
    {
        data[i] = temp[i];
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

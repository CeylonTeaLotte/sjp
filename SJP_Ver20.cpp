#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

struct Student
{
    int sNo;
    string name;
    int kor, eng, math;
    float ave;
};

int main()
{
    const int MAX_STUDENT=100;
    Student students[MAX_STUDENT];
    float TotalAve=0.0f;
    int NumberOfStudent=0;


     while(1)
    {
        cout << "\n-----메뉴-----\n";
        cout << "1. 학생 성적 추가\n";
        cout << "2. 전체 성적 보기\n";
        cout << "3. 프로그램 종료\n";
        cout << "--------------\n";
        cout << "원하는 작업의 번호를 입력하세요 : ";

        char select;
        cin >> select;

        switch(select)
        {
            case '1':
            {
            cout << "\n학생 성적 추가가 선택되었습니다.\n";
            if(MAX_STUDENT==NumberOfStudent)
            {
                cout << "\n더 이상 입력할 수 없습니다.\n";
                break;
            }

            Student& std = students[NumberOfStudent];
            //꼭 필요한 작업은 아니고 소스 코드를 일긱 좋게 하려는 것이다. 이번에 입력 받은 학생 정보는
            // students[NumberofStudent] 에 보관해야 하는데, 매번 이렇게 써주면 소스 코드가
            // 지저분해 질 수 있다.
            //그래서 간단하게 std라는 별명을 붙여 준다
            // 만약 지금이 첫번째 입력이라면 NumberOfStudent의 값은 0일 것이고 std는 student[0]의 별명이 된다.
            std.sNo=NumberOfStudent+1;

            
            cout <<"\n이름(공백없이) 국어, 영어, 수학 점수를 입력하세요: ";
            cin >> std.name >> std.kor >> std.eng >> std.math;
            std.ave=float(std.kor+std.eng+std.math)/3.0f;

            const int current=NumberOfStudent+1;
            const int prev = NumberOfStudent;
            TotalAve=(TotalAve*prev/current)+(std.ave/current); // 식 해석 필요
            NumberOfStudent++;
            cout << "\n학생 성적이 올바르게 입력되었습니다.\n";
            break;
            }
            
            case '2':
            {
            cout.precision(2);
            cout << fixed;
            cout << "\n        < 전체 성적 보기 >\n";
            cout << "\n   학번 국어 영어 수학   평균\n";

            for (int i=0;i<NumberOfStudent;++i)
            {
                const Student& std = students[i];
                
                cout << setw(7) << std.sNo << setw(5) << std.kor << setw(5)  <<std.eng;
                cout << setw(5)  << std.math << setw(7)  << std.ave << endl;
              
            }
            cout << "\n전체 평균 = " << TotalAve << endl;
            break;
            }

            case 'Q':
            case 'q':
            cout << "\n프로그램을 종료합니다.\n";
            return 0; // 요거 잘보기

            defalut:
            cout << "\n올바른 값을 입력해 주세요\n";
            break;

        }
        

    }
    return 0;

}
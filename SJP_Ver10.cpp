#include<iostream>
#include<iomanip> // setw
using namespace std;
////f
int main()
{
    int S1_No, S2_No, S3_No;
    int S1_Kor, S2_Kor, S3_Kor;
    int S1_Math, S2_Math, S3_Math;
    int S1_Eng, S2_Eng, S3_Eng;
    float S1_Ave,S2_Ave,S3_Ave;
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
            if(NumberOfStudent==3)
            {
                cout << "\n더 이상 입력할 수 없습니다.\n";
                break;
            }
            int Kor, Eng, Math;
            cout <<"\n국어, 영어, 수학 점수를 입력하세요: ";
            cin >> Kor >> Eng >> Math;
            float Ave=float(Kor+Eng+Math)/3.0f; // Warning

            if(0==NumberOfStudent)
            {
                S1_No=NumberOfStudent+1;
                S1_Kor=Kor; S1_Eng=Eng; S1_Math=Math; S1_Ave=Ave;
                TotalAve=Ave;
            }
            else if(1==NumberOfStudent)
            {
                S2_No=NumberOfStudent+1;
                S2_Kor=Kor; S2_Eng=Eng; S2_Math=Math; S2_Ave=Ave;
                TotalAve=(S1_Ave+S2_Ave)/2;
            }
            else
            {
                S3_No=NumberOfStudent+1;
                S3_Kor=Kor; S3_Eng=Eng; S3_Math=Math; S3_Ave=Ave;
                TotalAve=(S1_Ave+S2_Ave+S3_Ave)/3;

            }
            NumberOfStudent++;
            cout << "\n학생 성적이 올바르게 입력되었습니다.\n";

            break;
            }
            
            case '2':
            {
            cout.precision(2);
            cout << fixed;
            cout << "\n전체 성적 보기가 선택되었습니다.\n";
            cout << "\n 전체 성적 보기\n";
            cout << "\n   학번 국어 영어 수학   평균\n";

            for (int i=0;i<NumberOfStudent;++i)
            {
                if(i==0)
                {
                    cout << setw(7) << S1_No << setw(5) << S1_Kor << setw(5)  <<S1_Eng;
                    cout << setw(5)  << S1_Math << setw(7)  << S1_Ave << endl;
                }
                else if(i==1)
                {
                    cout << setw(7) << S2_No << setw(5) << S2_Kor << setw(5)  <<S2_Eng;
                    cout << setw(5)  << S2_Math << setw(7)  << S2_Ave << endl;
                }
                else
                {
                   cout << setw(7) << S3_No << setw(5) << S3_Kor << setw(5)  <<S3_Eng;
                    cout << setw(5)  << S3_Math << setw(7)  << S3_Ave << endl;

                }
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
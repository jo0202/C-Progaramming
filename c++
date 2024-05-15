#include <iostream>
#include <string>
using namespace std;



int main() {

    string s;
    cout << "식을 입력하시오 (예: 4+3*3/2): ";
    getline(cin, s, '\n'); // 문자열 입력
    double result = 0;
    char start = '+'; // 초기 연산자는 덧셈으로 설정
    size_t startIndex = 0; // 검색 시작 위치

    while (true) {
        size_t fIndex = s.find_first_of("+-*/", startIndex);
        if (fIndex == string::npos) { 
            string part = s.substr(startIndex); 
            if (!part.empty()) {
                int num = stoi(part);
                switch (start) {
                case '+':
                    result += num;
                    break;
                case '-':
                    result -= num;
                    break;
                case '*':
                    result *= num;
                    break;
                case '/':
                    result /= num;
                    break;
                }
            }
            break;
        }
        string part = s.substr(startIndex, fIndex - startIndex);
        int num = stoi(part); // 문자열을 정수로 변환

        switch (start) {
        case '+':
            result += num;
            break;
        case '-':
            result -= num;
            break;
        case '*':
            result *= num;
            break;
        case '/':
            result /= num;
            break;
        }

        start = s[fIndex];
        startIndex = fIndex + 1;
    }

    cout << "계산 결과: " << result << endl;

    return 0;
}

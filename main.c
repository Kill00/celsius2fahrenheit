#include <stdio.h>
#include <stdlib.h>

int main(const int argc, char *argv[]) {
    // UTF-8 지원 (Windows)
    system("chcp 65001");

    // 입력한 인자가 3개인지 확인
    if (argc != 3) {
        printf("Error: Invalid input.\n");
        printf("-----\n");
        printf("Usage: %s <celsius> <language>\n", argv[0]);
        printf("Supported languages: ENUS, KOKR, JAJP, ZHCN");
        return -1;
    }

    // 입력한 인자가 숫자인지 확인
    for (int i = 0; argv[1][i] != '\0'; i++) {
        if (argv[1][i] < '0' || argv[1][i] > '9') {
            printf("Error: %s is not a number.\n", argv[1]);
            printf("-----\n");
            printf("Usage: %s <celsius> <language>\n", argv[0]);
            printf("Supported languages: ENUS, KOKR, JAJP, ZHCN");
            return -1;
        }
    }

    // 섭씨를 화씨로 변환
    const int celsius = atoi(argv[1]);
    const float fahrenheit = celsius * (9 / 5) + 32;
    const int asciiToHex = (int) argv[2][0] + (int) argv[2][1] + (int) argv[2][2] + (int) argv[2][3];

    // 언어별 화씨값 출력
    if (asciiToHex == 0x13B) {
        // 0x45 + 0x4E + 0x55 + 0x53 = 0x13B (EN-US)
        printf("The temperature in Fahrenheit is: %f", fahrenheit);
    } else if (asciiToHex == 0x137) {
        // 0x4B + 0x4F + 0x4B + 0x52 = 0x137 (KO-KR)
        printf("화씨로 변환된 온도는 %f 입니다.", fahrenheit);
    } else if (asciiToHex == 0x125) {
        // 0x4A + 0x41 + 0x4A + 0x50 = 0x125 (JA-JP)
        printf("華氏に変換された温度は %f です。", fahrenheit);
    } else if (asciiToHex == 0x12E) {
        // 0x43 + 0x5A + 0x43 + 0x4E = 0x12E (ZH-CN)
        printf("华氏转换后的温度为 %f。", fahrenheit);
    } else {
        printf("Language not supported.\n");
        printf("Supported languages: ENUS, KOKR, JAJP, ZHCN");
    }

    // 변환된 화씨값을 리턴
    return fahrenheit;
}

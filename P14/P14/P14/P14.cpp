// P14.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
#include <stdio.h>
#include <stdlib.h>

#define STUDENTS 3
#define EXAMS 4

int minimum(const int grades[][EXAMS], int pupils, int tests);
int maximum(const int grades[][EXAMS], int pupils, int tests);
double average(const int setOfGrades[], int tests);
void printArray(const int grades[][EXAMS], int pupils, int tests);

int main(void)
{
    int student;
    const int studentGrades[STUDENTS][EXAMS] =
    {
        {77, 68, 86, 73},
        {96, 87, 89, 78},
        {70, 90, 86, 81}
    };

    printf("The array is:\n");
    printArray(studentGrades, STUDENTS, EXAMS);

    printf("\n\nLowest grade: %d\nHighest grade: %d\n",
        minimum(studentGrades, STUDENTS, EXAMS),
        maximum(studentGrades, STUDENTS, EXAMS));

    for (student = 0; student < STUDENTS; student++)
    {
        printf("The average grade for student %d is %.2f\n",
            student, average(studentGrades[student], EXAMS));
    }

    system("pause");
    return 0;
}

int minimum(const int grades[][EXAMS], int pupils, int tests)
{
    int i;
    int j;
    int lowGrade = 100;

    for (i = 0; i < pupils; i++)
    {
        for (j = 0; j < tests; j++)
        {
            if (grades[i][j] < lowGrade)
            {
                lowGrade = grades[i][j];
            }
        }
    }

    return lowGrade;
}

int maximum(const int grades[][EXAMS], int pupils, int tests)
{
    int i;
    int j;
    int highGrade = 0;

    for (i = 0; i < pupils; i++)
    {
        for (j = 0; j < tests; j++)
        {
            if (grades[i][j] > highGrade)
            {
                highGrade = grades[i][j];
            }
        }
    }

    return highGrade;
}

double average(const int setOfGrades[], int tests)
{
    int i;
    int total = 0;

    for (i = 0; i < tests; i++)
    {
        total += setOfGrades[i];
    }

    return (double)total / tests;
}

void printArray(const int grades[][EXAMS], int pupils, int tests)
{
    int i;
    int j;

    printf("                 [0]  [1]  [2]  [3]");

    for (i = 0; i < pupils; i++)
    {
        printf("\nstudentGrades[%d] ", i);

        for (j = 0; j < tests; j++)
        {
            printf("%-5d", grades[i][j]);
        }
    }
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案

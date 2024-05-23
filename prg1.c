#include <stdio.h>
#include <string.h>

// 1. a.
// struct datatype for student of BGSCET college
struct Student
{
    char name[100];
    char usn[20];
    char branch[10];
    char sex;
    double sgpa;
    long int phone_no;
    short is_pass; // It's ok to use int as boolean, but remember it should be only 0 and 1!
};

struct Student students[100];
int size = 0;

// 1. b.
void createStudent(char name[], char usn[], char branch[], char sex, double sgpa, long int phone_no)
{
    // 1. d.
    for (int i = 0; i < size; i++)
    {
        if (strcmp(students[i].usn, usn) == 0)
        {
            printf("Student with the given USN already exist!\n");
            return;
        }
        if (students[i].phone_no == phone_no)
        {
            printf("Student with the given PhoneNo already exist!\n");
            return;
        }
    }
    strcpy(students[size].name, name);
    strcpy(students[size].usn, usn);
    strcpy(students[size].branch, branch);
    students[size].sex = sex;
    students[size].sgpa = sgpa;
    students[size].phone_no = phone_no;
    // 1. c.
    students[size].is_pass = sgpa < 3.5 ? 0 : 1;

    size = size + 1;
}

// helper function
void printStudent(int indexNo)
{
    printf("%s \t %c \t %ld \t %s \t %s \t %f\n", students[indexNo].name, students[indexNo].sex,
           students[indexNo].phone_no, students[indexNo].branch,
           students[indexNo].usn, students[indexNo].sgpa);
}

// helper function
void printAll()
{
    for (int i = 0; i < size; i++)
    {
        printStudent(i);
    }
}

// 1. e.
void printByGender(char gender)
{
    for (int i = 0; i < size; i++)
    {
        if (students[i].sex == gender)
        {
            printStudent(i);
        }
    }
}

// 1. f.
void printInRefToPass()
{
    for (int i = 0; i < size; i++)
    {
        if (students[i].is_pass == 1)
        {
            printStudent(i);
        }
    }
}

// 1. g.
void printByBranch(char branch[])
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(students[i].branch, branch) == 0)
        {
            printStudent(i);
        }
    }
}

// helper function
void initiallyPersons()
{
    char names[10][100] = {"Sam", "Alan", "Alex", "Rose", "Violet"};
    char sex[10] = {'M', 'M', 'M', 'F', 'F'};
    char branch[10][10] = {"CSE", "CSD", "ISE", "AIDS", "AIML"};
    char usn[10][20] = {"1MP22CS001", "1MP22CD001", "1MP22IS001", "1MP22AD01", "1MP22AI001"};
    double sgpa[10] = {8.9, 7.88, 8.8, 9.2, 9.9};
    long int phone_no[10] = {8178921232, 8178921233, 8178921235, 8178921237, 8178921239};
    for (int i = 0; i < 5; i++)
    {
        createStudent(names[i], usn[i], branch[i], sex[i], sgpa[i], phone_no[i]);
    }
}

int main()
{
    int choice;

    char name[100];
    char usn[20];
    char branch[10];
    char sex;
    long int phone_no;
    double sgpa;

    initiallyPersons();
    while (1)
    {
        printf("Menu Driven Program: Enter your choice!\n");
        printf("1. Create a New Student\n");
        printf("2. Print All Students\n");
        printf("3. Print All Students By Gender\n");
        printf("4. Print All Students If they have Passed\n");
        printf("5. Print All Students By Their Branch\n");
        printf("6. Exit\n");
        printf("\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("\nEnter student name: ");
            getchar();
            scanf("%s", name);
            printf("\nEnter student sex (M | F | O): ");
            getchar();
            scanf("%c", &sex);
            printf("\nEnter student branch: ");
            getchar();
            scanf("%s", branch);
            printf("\nEnter student usn: ");
            getchar();
            scanf("%s", usn);
            printf("\nEnter mobile no.: ");
            scanf("%ld", &phone_no);
            printf("\nEnter student sgpa: ");
            scanf("%lf", &sgpa);
            createStudent(name, usn, branch, sex, sgpa, phone_no);
        }
        else if (choice == 2)
        {
            printf("\n");
            printf("Name \t Sex \t Phone_no \t Branch \t USN \t SGPA\n");
            printAll();
            printf("\n");
        }
        else if (choice == 3)
        {
            char gender;
            printf("\nEnter the gender (M | F | O): ");
            getchar();
            scanf("%c", &gender);
            printf("\n");
            printf("Name \t Sex \t Phone_no \t Branch \t USN \t SGPA\n");
            printByGender(gender);
            printf("\n");
        }
        else if (choice == 4)
        {
            printf("\n");
            printf("Name \t Sex \t Phone_no \t Branch \t USN \t SGPA\n");
            printInRefToPass();
            printf("\n");
        }
        else if (choice == 5)
        {
            char branch1[20];
            printf("\nEnter the branch (CSE | ISE | AIDS | AIML | CSD): ");
            scanf("%s", branch1);
            printf("\n");
            printf("Name \t Sex \t Phone_no \t Branch \t USN \t SGPA\n");
            printByBranch(branch1);
            printf("\n");
        }
        else if (choice == 6)
        {
            printf("Thank You!!\n");
            return 0;
        }
        else
        {
            printf("Invalid Choice!\n");
        }
    }
    return 0;
}
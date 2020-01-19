/*
联合体的目的是存储空间的共用
三种类型不会同时起作用
union 联合体名称 {
    公有成员
    protected:
        保护型成员
    private:
         私有成员
}
特点:
    成员共有同一组内存单元
    任何两个成员不会同时有效
*/
#include <iostream>
using namespace std;

/*
//表示成绩的联合体
union Mark {
    char grade;//等级制的成绩
    bool pass;//只计是否通过课程的成绩
    int percent;//百分制的成绩
};

无名联合
union {
    int i;
    float f;
};

    //在程序中可以这样使用
    i = 10;
    f = 2.2;
*/
//使用联合体保存成绩信息，并且输出；同一门课的一个学生的只能得到一种类型的成绩
class ExamInfo {
    private:
        string name;//课程名称
        enum {GRADE,PASS,PERCENTAGE} mode;//计分方式
        union {
            char grade;//等级制的成绩
            bool pass;//只计是否通过课程的成绩
            int percent;//百分制的成绩
        };
    public:
        ExamInfo(string name,char grade)
            :name(name),mode(GRADE),grade(grade) { }
        ExamInfo(string name,bool pass)
            :name(name),mode(PASS),pass(pass) { }
        ExamInfo(string name,int percent)
            :name(name),mode(PERCENTAGE),percent(percent) { }
        void show();
};

void ExamInfo::show(){
    cout << name << ": ";
    switch (mode)
    {
    case GRADE:
        cout << grade;
        break;
    case PASS:
        cout << (pass ? "PASS":"FAIL");
        break;
    case PERCENTAGE:
        cout << percent;
        break;
    }
    cout << endl;
}


int main(){
    ExamInfo course1("English",'B');
    ExamInfo course2("Calculus",true);
    ExamInfo course3("c++ Programming",85);
    course1.show();
    course2.show();
    course3.show();
    return 0;
}


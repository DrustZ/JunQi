#ifndef STRUCTS_H
#define STRUCTS_H
struct qizi{
    int x1,x2,y1,y2;
    int grade;
    int state;//0 -- dead 1 --- alive
    int team;//0 --- TEAM A 1 --- TEAM B
    int trail;
    int bianshu;//bianshu
    int bian[10];
    int leixing;//在大本营？不能走 类型0 在行营？受保护，类型-1 普通类型1
    int kangqi;
};

#endif // STRUCTS_H

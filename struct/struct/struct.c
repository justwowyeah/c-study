#include <stdio.h>

struct B
{
	char c;
	short s;
	double d;
};

struct Stu
{
	struct B sb;
	char name[20];
	int age;
	char BD[20];
};

void print1(struct Stu t)
{
	printf("%c %d %lf %s %d %s\n", t.sb.c, t.sb.s, t.sb.d, t.name, t.age, t.BD);
}

void print2(struct Stu *ps)
{
	printf("%c %d %lf %s %d %s\n", ps->sb.c, ps->sb.s, ps->sb.d, ps->name, ps->age, ps->BD);
}

int main(void)
{
	struct Stu s = { {'w', 20, 3.14}, "ÒÂ½ÇµÄÇåÏĞ", 18, "20040912" };
	print1(s);
	print2(&s);
	return 0;
}
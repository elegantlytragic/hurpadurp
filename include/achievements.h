#ifndef ACHIEVEMENTS_H
#define ACHIEVEMENTS_H
class achievement{
	public:
		bool got;
		char*name,*desc;
		void achcreate(char*,char*);
};
void achcreate();
void achievementcheck();
void acdisp(achievement);
#endif
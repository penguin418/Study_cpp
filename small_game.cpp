#include<iostream>
#include<cstring>
using std::cout;
using std::endl;

class Dovahzul{
	public:
		void learn();
		void shouting();
};
class Character{//base class
	public:
		Character(int _hp, int _power, int _exp):hp(_hp),power(_power), exp(_exp), is_die(0){}
		void attack(Character other){this->exp = other.damaged(this->power);}
		int damaged(int damage){this->hp -= damage; if(hp<0){die();return this->exp;}}
		void die(){cout<<"끄아악"<<endl; this->is_die = 1;}
		int is_die;
	protected:
		int hp;
		int power;
		int exp;
};
class Hero : protected Character{//단일 상속
	public:
		Hero(int hp, int power, const char *_name) : Character(hp, power, 0), name(_name){cout<<this->name<<endl;}
		const char *name;

};
class Monster : protected Character{
	public:
		Monster(int hp, int power, int _exp) : Character(hp, power, _exp) {}
		void die(){cout<<"꾸에엑"<<endl;}
};
class Spider : protected Monster{//sub class
	public:
		Spider(const char* _name) : Monster(150, 50, 30) name(_name) {}
		const char *name;
};
void dungeon(){
}
int meetMadSpider(Hero &hero){
	Spider spider("성난거미");
	while(1){
		spider.attack(*hero);
		if(hero->is_die){
			return 1;
		}
		hero->attack(spider);
		if(spider.is_die)
			return 0;
	}

}
int main(void){ 

}



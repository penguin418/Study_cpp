#include<iostream>
#include<cstring>

class Legendary_sword{
	public:
		Legendary_sword(){std::cout<<"전설의 검을 가진자가 나타났다."<<std::endl;}
		void hold(class Hero hero);
		void attack(class Monster monster);
};

class Monster{
	public:
		Monster(const char *_name, int _hp, int _po) : name(_name), hp(_hp), power(_po){}
		void hit(class Hero hero);
		void die(class Hero hero);
		const char *name;	
		int hp;
		int power;
};
class Hero{
	public:
		Legendary_sword Lsword;
		Hero(const char *_name, int _hp, int _po) : name(_name), hp(_hp), power(_po){}
		void hit(class Monster monster);
		/*int*/void hitted(int damage);
		void Legendary_hit(class Monster monster){Lsword.attack(monster);}//전설의 공격은 맞으면 죽어야 된다
		void die();
		const char *name;
		int hp;
		int power;
};
class Legendary_Monster:public Monster{
	public:
		Legendary_Monster(const char *_name, const char *_type, int _hp, int _po) : Monster(_name, _hp, _po){strcpy(type, _type);std::cout<<_type<<"의 "<<_name<<"이 나타났다"<<std::endl;}
		/*int*/void Legendary_hit(class Hero hero){std::cout<<"공격!!"<<std::endl;/*if(*/hero.hitted(90)/*)return 1*/;}
		char *type;
};

void hold(class Hero hero){std::cout<<hero.name<<"은 전설의 검을 들었다."<<std::endl;}
void attack(class Monster monster){std::cout<<monster.name<<"은 죽었다."<<std::endl;}
void Hero::hit(Monster monster){
	std::cout<<"죽어랏"<<monster.name<<"!!"<<std::endl;
	if(this->power <  monster.hp)
		std::cout<<"어 망했네"<<std::endl;
	else
		monster.die(*this);
}
/*int*/void Hero::hitted(int damage){
	std::cout<<"으악"<<std::endl;
	this->hp -= damage;
	if(hp<0){
		std::cout<<"으앙 주금"<<std::endl;
		/*return 1;*/
	}
	/*return 0;*/
}
void Hero::die(){
	std::cout<<"끄앙"<<std::endl;
	std::cout<<this->name<<"이 죽었다."<<std::endl;
}
void Monster::hit(Hero hero) {
	std::cout<<"죽어랏"<<hero.name<<"!!"<<std::endl;
	if(this->power < hero.hp)
		std::cout<<hero.name<<"은 살아남았다"<<std::endl;
	else
		hero.die();
}
void Monster::die(Hero hero){
	std::cout<<this->name<<"이 죽음"<<std::endl;
	std::cout<<hero.name<<"은 "<<this->hp<<"의 경험치를 획득하였다."<<std::endl;
}

int main(void){
	Hero hero("드래곤본", 100, 100);
	Monster goblin("고블린", 90, 50);
	goblin.hit(hero);
	hero.hit(goblin);
	Legendary_Monster golem("골렘","돌속성",1000,90);
	golem.hit(hero);
	/*if(*/golem.Legendary_hit(hero)/*)
		return 0*/;
	hero.Legendary_hit(golem);
	
}

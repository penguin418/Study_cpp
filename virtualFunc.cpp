#include<iostream>
#define COUT(x) std::cout<<#x<<std::endl
class Univ{
	public:
		Univ() {COUT(Univ_생성);}
		~Univ() {COUT(Univ_소멸);}
		virtual void Pure_VF_who_are_you(int a, int b) = 0;
		/*순수가상함수
		  반드시 지킬것 1 virtual, 2 =0
		  상관없는 것 1리턴형 2함수이름 3매개변수*/
};
class SoongSil{
	public:
		SoongSil() {COUT(숭실대_생성);}
		~SoongSil() {COUT(숭실대_소멸);}
		virtual void VF_who_are_you() {COUT(나는_숭실대(VF_SoongSil_CLASS));}
		void who_are_you() {COUT(나는_숭실대(SoongSil_CLASS));}
};
class SSS : public Univ{//*Student of *Soong*Sil Univ,
	public:
		SSS() {COUT(숭실대생_생성);}
		~SSS() {COUT(숭실대생_소멸);}
		virtual void VF_who_are_you() {COUT(나는_숭실대_IT(VF_SSS_CLASS));}
		void who_are_you() {COUT(나는_숭실대_IT(SSS_CLASS));}
};
class IT : public SSS, public Univ{
	public:
		IT() {COUT(IT대_생성);}
 		~IT() {COUT(IT대_소멸);}
		virtual void Pure_VF_who_are_you(int c, int d) {COUT(나는_숭실대_IT(P_VF_IT));}
		/*순수가상함수
		  오버라이딩함
		  반드시 지킬 것 1 리턴형 2 함수이름
		  상관없는 것 매개변수 이름*/
		virtual void VF_who_are_you() {COUT(나는_IT대(VF_IT_CLASS));}
		void who_are_you() {COUT(나는_IT대(IT_CLASS));}
};
class Soft : public IT{
	public:
	virtual void VF_who_are_you() {COUT(나는_숭실대_IT_soft(VF_SSS));}
	void who_are_yoou() {COUT(나는_숭실대_IT_Soft(SSS));}
};
/*
  SoongSil Univ(추상클래스)
	  ┃      ┃
   S S S    ┃
	  ┗━━┳━━━┛
       IT
	     ┃
		Soft
*/
int main(void){
	COUT(이_soft생은_IT대학_소속임);
	IT *ITsoft = new Soft;//상위클래스 포인터에 하위 클래스
	ITsoft->who_are_you();//who_are_you는 virtual이 아니라서 상위클래스 함수가 실행됨
	/*ITsoft->Soft::who_are_you();*///Soft가 IT의 base가 아니라면서 쓸수 없다고 한다.
	ITsoft->SSS::who_are_you();//위와 함수이름이 똑같으므로 ambiguous 경고가 표시된다. 
	/*ITsoft->SoongSil::who_are_you();*///SoongSil클래스는 IT의 base가 아니므로 사용할 수 없다. base가 아니므로 사용할 수 없다. base가 아니므로 사용할 수 없다.
	ITsoft->VF_who_are_you();//VF_~는 virtual이므로 하위클래스인 soft가 실행됨
	delete ITsoft;
	COUT(이_IT대생은_숭실대_학생임);

	SSS *SSS_IT = new IT;//SSS클래스타입 SSS_IT객체의 base클래스로 IT클래스를 불러왔다고도 말할 수 있다.(컴파일오류에서 확인가능)
	SSS_IT->who_are_you();//who_are_you는 virtual이 아니라서 상위클래스함수가 실행됨
	SSS_IT->VF_who_are_you();//VF_who_are_you는 virtual이라서 하위클래스인 IT 함수가 실행됨
	SSS_IT->SSS::VF_who_are_you();//하지만 범위지정으로 원하는 함수를 불러왔음
	//SSS_IT->Soft::VF_who_are_you();//Soft를 SSS_IT의 base 클래스로 선언하지 않았으므로, SSS_IT입장에서는 Soft를 모른다.
	SSS_IT->Pure_VF_who_are_you(0,0);

	delete SSS_IT;
/*
	COUT(이_soft생은_숭실대_학생임);
	SoongSil *soongsil_soft = new Soft;
	delete soongsil_soft;
*///한번에 클래스 두번을 뛰이넘을수는 없다.
	return 0;
}

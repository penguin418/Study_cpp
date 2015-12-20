#include<iostream>
class Friend_of_MyFriend{
	public:
	Friend_of_MyFriend(int specialnumber){
		password_fmf = specialnumber;
		std::cout<<"Friend of MyFriend생성자"<<std::endl;
	}
	friend class MyFriend;
	private:
		int password_fmf;
};
class MyFriend{
	public:
		MyFriend(int specialnumber){
		password_mf = specialnumber;
		std::cout<<"MyFriend생성자"<<std::endl;
	}
	friend class Me;//클래스도 친구가 될 수 있다.
	private:
	void tell_secret_of_friend(Friend_of_MyFriend &him){
		std::cout<<"친구의 비밀번호는"<<him.password_fmf<<std::endl;
}
	int password_mf;
};
class Me{
	public:
	Me(int specialnumber){
		password_m = specialnumber;
		std::cout<<"Me생성자"<<std::endl;
	}
	Me(const Me &me){
		password_m = me.password_m;
		std::cout<<"Me얕은복사생성자"<<std::endl;
	}
	void tell_my_secret(){
		std::cout<<"내 비밀번호는"<<this->password_m<<std::endl;
	}
	void tell_secret_of_friend(MyFriend &him){
		std::cout<<"친구의 비밀번호는"<<him.password_mf<<std::endl;
	}
/*	void tell_secret_of_friend_of_myfriend(Friend_of_MyFriend &him){
	std::cout<<"친구의친구의비밀번호는"<<him.password_mf<<std::endl;
	}*///친구의 친구의 비밀은 바로 알 수 없다.
	void tell_secret_of_your_friend(MyFriend &him, Friend_of_MyFriend &hisfriend){
		std::cout<<"네 친구의 비밀번호가 뭐니?"<<std::endl;
		him.tell_secret_of_friend(hisfriend);
	}//하지만 친구를 추궁하면 친구의 친구의 비밀번호를 알 수 있다.

	private:
		int password_m;	
};
void tellPassword(Me me){
	me.tell_my_secret();
}
void shallowCopyError(Me me){
	delete(&me);
}
int main(){
	Me Gaap(143);
	tellPassword(Gaap);
	MyFriend Eul(666);
	Friend_of_MyFriend Byeong(999);
	Gaap.tell_secret_of_friend(Eul);
	//Gaap.tell_secret_of_friend_of_myfriend(Byeong);
	Gaap.tell_secret_of_your_friend(Eul, Byeong);
	shallowCopyError(Gaap);
}


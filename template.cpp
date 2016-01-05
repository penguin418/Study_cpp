#include<iostream>
#include<stdlib.h>//malloc을 사용하기 위해 stdlib.h를 가져올 수 있다는 건 처음 알았다

/*템플릿으로 만드는 스택*/
//	template <typename T>
/*클래스나 함수 앞에 템플릿이 두 개이상 되면 too many template-parameter-list오류가 출력된다.
 */
template <class info_type>
class Stack{
	/*using IT = info_type;
	*typedef IT info_type;
	*둘다 사용할 수 없다  expected nested-name-specifier before 'IT'라는 오류와 함께 
	*이유는 템플릿 클래스에서 사용해서 그런 것 같다 스택오버플로를 뒤지고 있는데 아직 모르겠다
	 */
	public:
		Stack(int data_size):data_size(data_size), top(-1){data_storage = (info_type*)malloc(sizeof(info_type));}
		~Stack(){free(data_storage);}
		void _top(){
			if(is_empty()){
				std::cout<<"텅텅 비었음"<<std::endl;
			}
			else std::cout<<data_storage[top]<<std::endl;;
		}
		void push(info_type data){
			if(is_full()){
				std::cout<<"꽉참"<<std::endl;
			}
			else data_storage[++top] = data;//top의 시작값이 -1이므로
		}
		void pop(){
			if(is_empty()){
				std::cout<<"텅텅 비었음"<<std::endl;
			}
			else std::cout<<data_storage[top--]<<std::endl;
		}
		bool is_empty(){if(top == -1) return 1; else return 0;}
		bool is_full(){if(top == (data_size - 1)) return 1; else return 0;}
	private:
		info_type *data_storage;	//스택의 자료타입
		int data_size;					//스택의 사이즈
		int top;							//스택의 뚜껑
};
/*
	class Child_Class : public Template_Class{
	public:
	Child_Class(int input) : Template_Class(input) {std::cout<<input<<" is variable of 
	};
 */

//	template <class T>
/*main은 함수템플릿이 안된다
 */
Stack<int>* menu1(int data_size){
	Stack<int> *stack_int = new Stack<int>(data_size);
	return stack_int;
}
Stack<float>* menu2(int data_size){
	Stack<float> *stack_int = new Stack<float>(data_size);
	return stack_int;
}
Stack<char>* menu3(int data_size){
	Stack<char> *stack_int  = new Stack<char>(data_size);
	return stack_int;
}
int main(){
	std::cout<<"템플릿 스택"<<std::endl;
	int menu = 1, submenu = 1, data_size;
	int data_int;
	float data_float;
	char data_char;
	Stack<int> *stack_int;
	Stack<float> *stack_float;
	Stack<char> *stack_char;
	std::cout<<"1 정수 정보"<<std::endl;
	std::cout<<"2 부동 소수 정보"<<std::endl;
	std::cout<<"3 문자 정보"<<std::endl;
	std::cout<<"4 문자열 정보"<<std::endl;
	std::cout<<"q 끝내기"<<std::endl;
	std::cout<<"메뉴 번호 입력 : ";
	std::cin>>menu;
	std::cout<<"데이터는 몇개나 넣을 것 같습니까?"<<std::endl;
	std::cout<<"예상 데이터 개수 입력 : ";
	std::cin>>data_size;
	switch(menu){
		case 1:
			stack_int = menu1(data_size);
			while(submenu){
				std::cout<<"================="<<std::endl;
				std::cout<<"1 top"<<std::endl;
				std::cout<<"2 pop"<<std::endl;
				std::cout<<"3 push"<<std::endl;
				std::cout<<"0 끝내기"<<std::endl;
				std::cout<<"메뉴 번호 입력 : ";
				std::cin>>submenu;
				switch(submenu){
					case 1:
						stack_int->_top();
						break;
					case 2:
						stack_int->pop();	
					case 3:
						std::cout<<"데이터입력 : ";
						std::cin>>data_int;
						stack_int->push(data_int);
						break;
					default:/*무엇을 묻든 다시 묻지만, 0이 될때만 끝남*/
						break;
				}
			}
			free(stack_int);
			break;
		case 2:
			stack_float = menu2(data_size);
			while(submenu){
				std::cout<<"================="<<std::endl;
				std::cout<<"1 top"<<std::endl;
				std::cout<<"2 pop"<<std::endl;
				std::cout<<"3 push"<<std::endl;
				std::cout<<"0 끝내기"<<std::endl;
				std::cout<<"메뉴 번호 입력 : ";
				std::cin>>submenu;
				switch(submenu){
					case 1:
						stack_float->_top();
						break;
					case 2:
						stack_float->pop();	
					case 3:
						std::cout<<"데이터입력 : ";
						std::cin>>data_float;
						stack_float->push(data_float);
						break;
					default:/*무엇을 묻든 다시 묻지만, 0이 될때만 끝남*/
						break;
				}
			}
			free(stack_float);
			break;
		case 3:
			stack_char = menu3(data_size);
			while(submenu){
				std::cout<<"================="<<std::endl;
				std::cout<<"1 top"<<std::endl;
				std::cout<<"2 pop"<<std::endl;
				std::cout<<"3 push"<<std::endl;
				std::cout<<"0 끝내기"<<std::endl;
				std::cout<<"메뉴 번호 입력 : ";
				std::cin>>submenu;
				switch(submenu){
					case 1:
						stack_char->_top();
						break;
					case 2:
						stack_char->pop();	
					case 3:
						std::cout<<"데이터입력 : ";
						std::cin>>data_char;
						stack_char->push(data_char);
						break;
					default:/*무엇을 묻든 다시 묻지만, 0이 될때만 끝남*/
						break;
				}
			}
			free(stack_char);
			break;
		case 4:
			std::cout<<"현재 준비중입니다."<<std::endl;
			break;
		default:
			break;
	}
	return 0;
}

#include <iostream>

using namespace std;

class Stack{
private:
    int size;
    int *s;
    char *cs;
    int top;
public:
    Stack(int size) : size(size){
        top=-1;
        s=new int[size];
    }
    Stack(int size, char c) : size(size){
        top=-1;
        cs=new char[size];
    }
    void push(int x){
        if(!isFull()){
            top++;
            s[top]=x;
        }
        cout<<"full"<<endl;
    }
    void push(char x, char c){
        if(!isFull()){
            top++;
            cs[top]=x;
        }
        cout<<"full"<<endl;
    }
    int pop(){
        int x=-1;
        if(!isEmpty()){
            x=s[top];
            top--;
        }
        cout<<"empty"<<endl;
        return x;
    }
    char pop(char c){
        int x=-1;
        if(!isEmpty()){
            x=cs[top];
            top--;
        }
        cout<<"empty"<<endl;
        return x;
    }
    int stackTop(){
        if(!isEmpty()){
            return s[top];
        }
        else{
            cout<<"empty"<<endl;
            return -1;
        }
    }
    int isFull(){
        return top==size-1;
    }
    int isEmpty(){
        return top==-1;
    }
    void print(){
        for(int i=top;i>=0;i--){
            cout<<i<<" - "<<s[i]<<endl;
        }
    }
};

void paranmatch(){
    char exp[100];
    cout<<"enter: ";
    cin>>exp;
    count=0;
    while(exp[count]!='\0'){
        count++;
    }
    Stack stk(count, 'a');
    bool balanced=true;
    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{'){
            stk.push(exp[i], 'a');
        }
        else if (exp[i]==')' || exp[i]==']' || exp[i]=='}'){
            if(stk.isEmpty()){
                balanced=false;
                break;
            }
            char topBracket=stk.pop('a');
            if((topBracket=='(' && exp[i] != ')') || (topBracket=='[' && exp[i] != ']') || (topBracket=='{' && exp[i] != '}')){
                balanced=false;
                break;
            }
        }
    }
    if(balanced && stk.isEmpty()){
        cout<<"balanced"<<endl;
    }
    else{
        cout<<"not balanced"<<endl;
    }
}
int main(){
    int choice,size,x,temp;
    cout<<"size: ";
    cin>>size;
    Stack s(size);
    while(true){
        cout<<"1 push\n2 pop\n3 stacktop\n4 matching\nchoice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"enter: ";
                cin>>x;
                s.push(x);
                s.print();
                break;
            case 2:
                temp=s.pop();
                if(temp !=-1){
                    cout << temp <<" was deleted"<<endl;
                }
                s.print();
                break;
            case 3:
                cout << "stack top: "<< s.stackTop()<<endl;
                break;
            case 4:
                paranmatch();
        }
    }
}
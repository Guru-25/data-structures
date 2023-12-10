#include<iostream>

using namespace std;

class Stack{
private:
    int size;
    int top;
    int* s;
    char* cs;
public:
    Stack(int size):size(size){
        top=-1;
        s=new int[size];
    }
    Stack(int size, char c):size(size){
        top=-1;
        cs=new char[size];
    }
    void push(int x){
        if(!isFull()){
            top++;
            s[top]=x;
        }
        else{
            cout<<"full"<<endl;
        }
    }
    void push(char x, char c){
        if(!isFull()){
            top++;
            cs[top]=x;
        }
        else{
            cout<<"full"<<endl;
        }
    }
    int pop(){
        int x=-1;
        if(!isEmpty()){
            x=s[top];
            top--;
        }
        else{
            cout<<"empty"<<endl;
        }
        return x;
    }
    char pop(char c){
        int x=-1;
        if(!isEmpty()){
            x=cs[top];
            top--;
        }
        else{
            cout<<"empty"<<endl;
        }
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
    void print(){
        for(int i=top;i>=0;i--){
            cout<<i<<" - "<<s[i]<<endl;
        }
    }
    int isFull(){
        return top==size-1;
    }
    int isEmpty(){
        return top==-1;
    }
};

void paran(){
    char exp[100];
    cout<<"enter: ";
    cin>>exp;
    int count=0;
    while(exp[count]!='\0'){
        count++;
    }
    Stack stk(count,'c'); // string construtor else core dump error
    bool balanced=true;
    for(int i=0;i<count;i++){
        if(exp[i] =='(' || exp[i] =='[' || exp[i] =='{'){
            stk.push(exp[i],'c');
        }
        else if(exp[i] ==')' || exp[i] ==']' || exp[i] =='}'){
            if(stk.isEmpty()){
                balanced=false;
                break;
            }
            else{
                char topPar=stk.pop('c');
                if((topPar=='(' && exp[i]!= ')') || (topPar=='[' && exp[i]!= ']') || (topPar=='{' && exp[i]!= '}')){
                    balanced=false;
                    break;
                }
            }
        }
    }
    if(balanced&&stk.isEmpty()){
        cout<<"balanced"<<endl;
    }
    else{
        cout <<"not balanced"<<endl;
    }
}

int main(){
    int choice,x,temp,size;
    cout<<"size: ";
    cin>>size;
    Stack stack(size);
    while(true){
        cout<<"1 push\n2 pop\n3 stack top\n4 paran\nchoice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"enter: ";
                cin>>x;
                stack.push(x);
                stack.print();
                break;
            case 2:
                temp=stack.pop();
                if(temp!=-1){
                    cout<<temp<<" was deleted"<<endl;
                }
                else{
                    cout<<"not found"<<endl;
                }
                stack.print();
                break;
            case 3:
                cout<<"stack top: "<<stack.stackTop()<<endl;
                break;
            case 4:
                paran();
                break;
        }
    }

    return 0;
}
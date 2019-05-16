//
//  main.cpp
//  polynomial
//
//  Created by 陈俊睿 on 2019/5/12.
//  Copyright © 2019 陈俊睿. All rights reserved.
//

#include <iostream>

#include "polynomial.cpp"

#define MAXNUM 100

using std::cin;
using std::cout;
using std::string;
using std::endl;

int count;
polynomial *head[MAXNUM];
polynomial *hl;
polynomial *hr;
polynomial *r_;

polynomial* find(string name){
    for(int i=0;i<count;i++){
        if(name==head[i]->getname())
        return head[i];
    }
    polynomial *n=new polynomial(1);
    return n;
};

void help();
void info();
void list();

int main(int argc, const char * argv[]) {
    cout << "WELCOME\nenter:\"/help\" to get help.\n";
    
    
    string in;
    string name;
    string p2;
    char operation;
    char Bool;
    char end;
    int x0;
    while(cin>>in){
        end=getchar();
        //add a polynomial.
        if(end=='\n'){
            if(in[0]=='/'){
                if(in=="/help")help();
                else if(in=="/list") list();
                else if(in=="/exit") return 0;
                else info();
            }
            else if(in[0]!='P'){find(in)->display();}
            else{
                head[count]=new polynomial(in);
                cout<<"The polynomial you enter is:";
                head[count]->display();
                cout<<"Do you want to save it?(Y/N)"<<endl;
                cin>>Bool;
                if(Bool=='Y'||Bool=='y'){
                    cout<<"Please give it a name:";
                    cin>>name;
                    head[count]->rename(name);
                    count++;
                }
                else if(Bool=='N'){delete head[count];}
            }
        }
        //operation betweeen polynomial
        else if(end==' '){
            operation=getchar();
            if(operation=='x'){
                operation=getchar();
                if(operation=='='){
                    cin>> x0;
                    cout<< find(in)->result(x0) <<endl;
                }else if(operation=='\''){
                    r_=find(in)->diff();
                    cout<<"The result is:";
                    r_->display();
                    cout<<"Do you want to save it?(Y/N)"<<endl;
                    cin>>Bool;
                if(Bool=='Y'||Bool=='y'){
                    cout<<"Please give it a name:";
                    cin>>name;
                    head[count]=r_;
                    head[count]->rename(name);
                    count++;
                }else delete r_;
                }
            }
            else if(operation=='='){
                cin>>operation>>p2;
                if(in[0]=='P'){
                    hl=new polynomial(in);
                }
                else hl=find(in);
                
                
                if(p2[0]=='P'){
                    hr=new polynomial(p2);
                }
                else hr=find(p2);
                
                if(*hl==*hr)cout<<in<<"=="<<p2<<endl;
                else cout<<in<<"!="<<p2<<endl;
            }
            else if(operation=='+'||operation=='-'||operation=='*'||operation=='/'||operation=='%'){
                cin>>p2;
                
                if(in[0]=='P'){
                    hl=new polynomial(in);
                }
                else hl=find(in);
                
                
                if(p2[0]=='P'){
                    hr=new polynomial(p2);
                }
                else hr=find(p2);
                
            
            r_=new polynomial(0);
                if(operation=='+'){
                    *r_+=*hl;
                    *r_+=*hr;
                }
                else if(operation=='-') {
                    *r_-=*hl;
                    *r_-=*hr;
                }
                //free....
                if(in[0]=='P'){
                    delete hl;
                }
                
                if(p2[0]=='P'){
                    delete hr;
                }

            cout<<"The result is:";
            r_->display();
            cout<<"Do you want to save it?(Y/N)"<<endl;
            cin>>Bool;
            if(Bool=='Y'||Bool=='y'){
                cout<<"Please give it a name:";
                cin>>name;
                head[count]=r_;
                head[count]->rename(name);
                count++;
            }
            }
        }
    }
    //free...
    for(int i=0;i<count;i++){delete head[i];}
    return 0;
}

void help(){
    cout<<"There are modes."<<endl;
    cout<<"mode 1 find: enter the name of existed polynomial"<<endl;
    cout<<"       Example: \"p\"  "<<endl;
    cout<<"mode 2 create: enter a new polynomial in P(...)"<<endl;
    cout<<"       Example: \"P(3*x^4)\"  "<<endl;
    cout<<"mode 3 calculation betweeen polynomial: "<<endl;
    cout<<"       Example: \"p + q\" or \"p + P(...)\" "<<endl;
    cout<<"       Notice: there is a space before and after \"+\" "<<endl;
    cout<<"mode 4 calculation the result: enter \"P(...) x=...\" or \"(name) x=...\""<<endl;
    cout<<"       Example: \"p x=3\""<<endl;
    cout<<"mode 2 compare: whether the 2 polynomial are equivalent"<<endl;
    cout<<"       Example: \"p =? q\"  "<<endl;
    cout<<"       Notice: there is a space before  \"=\" "<<endl;
    cout<<"mode 6 derivation: enter \"(name) x\'\" "<<endl;
    cout<<"       Example: \"p x\'\" "<<endl;
    cout<<"mode 7 list: enter \"/list\" "<<endl;
    cout<<"exit:enter \"/exit\" "<<endl;
    
};

void info(){
    cout<<"polynomial version -1.0\nCreated by 陈俊睿 on 2019/5/12.\nCopyright © 2019 陈俊睿. All rights reserved.\n";
};

void list(){
    for (int i=0; i<count; i++) {
        cout<<head[i]->getname()<<"   ";
        head[i]->display();
    }
};

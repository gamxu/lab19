#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string file,vector<string> &n,vector<int> &s,vector<char> &g){
    ifstream source(file);
    string textline;
    
    while(getline(source,textline)){
        float a=0,b=0,c=0;
        char name[100];
        const char * text = textline.c_str();
        char format[] = "%[^:]: %f %f %f";
        sscanf(text,format,name,&a,&b,&c);
        n.push_back(name);
        int score = a+b+c;
        s.push_back(score);
        g.push_back(score2grade(score));
    }
}

void getCommand(string &comm, string &key){
    string str;
    cout << "Please input your command: ";
    cin >> comm;
    cin.ignore(); 
    getline(cin,key);
    
}

void searchName(vector<string> n,vector<int> s,vector<char> g,string k){
    for(int i=0;i<n.size();i++){
        if(toUpperStr(n[i])==k){
            cout << "---------------------------------\n";
            cout << n[i] << "'s score = " << s[i] << "\n";
            cout << n[i] << "'s grade = " << g[i] << "\n";
            cout << "---------------------------------\n";
            return;
        }
    }
    cout << "---------------------------------\n";
    cout << "Cannot found." << "\n";
    cout << "---------------------------------\n";
    return;        
}

void searchGrade(vector<string> n,vector<int> s,vector<char> g,string k){
    int count=0;
    cout << "---------------------------------\n";
    for(int i=0;i<n.size();i++){
        if(g[i]==(char)k[0]){
            cout << n[i] << "(" << s[i] << ")" << "\n";
            count++;
        }
    }
    if(count==0){
            cout << "Cannot found." << "\n";
        }    
    cout << "---------------------------------\n";
}

int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}
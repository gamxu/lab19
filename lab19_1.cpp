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
    ifstream source("D:\\com prog lab\\HelloWorld\\"+file);
    string textline, name;
    float a,b,c;
    while(getline(source,textline)){
        sscanf(textline.c_str(),"%[^:]: %b %b %b",&name,&a,&b,&c);
        n.push_back(name);
        s.push_back(a+b+c);
        g.push_back(score2grade(a+b+c));
    }           
}

void getCommand(string &comm, string &key){
    cout << "Please input your command: ";
    cin >> comm >> key;
    
}

void searchName(vector<string> &n,vector<int> &s,vector<char> &g,string k){
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

void searchGrade(vector<string> &n,vector<int> &s,vector<char> &g,string k){
    int count=0;
    cout << "---------------------------------\n";
    for(int i=0;i<n.size();i++){
        if(g[i]==(char)k[0]){
            cout << n[i] << "(" << s[i] << ")" << "\n";
            count++;
        }else if(count == 0){
            cout << "Cannot found." << "\n";
        }
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

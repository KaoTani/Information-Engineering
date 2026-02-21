//AJG23085 谷口香央
//Codespacesで採点お願いします。

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

void add_height(map<string, double> &a){
    string n;
    double h;
    cout << "name: ";
    cin >> n;
    cout << "height(cm): ";
    cin >> h;
    a.insert(make_pair(n,h));
}

void search_height(map<string, double> a){
    string n;
    cout << "name: ";
    cin >> n;
    map<string, double>::const_iterator p;
    p = a.find(n);
    if (p == a.end()) {
        cout << "not found" << endl;
    }else{
        cout << p->first << "'s height: " << p->second << " cm" << endl;
    }
}

void delete_height(map<string, double> a){
    string n;
    cout << "name: ";
    cin >> n;
    map<string, double>::iterator p;
    p = a.find(n);
    if (p == a.end()) {
        cout << "not found" << endl;
    }else{
        cout << p->first << "'s height: " << p->second << " cm" << endl;
        a.erase(p);
        cout << "delete completely" << endl;
    }
}

double average_height(map<string, double> a){
    double sum=0.0;
    for(const auto& i : a){
        sum += i.second;
    }
    return a.empty() ? 0.0 : sum/(double)a.size();
}

int main(){
    int a;
    int b=0;
    map<string, double> high;
    high["Inoue"]=170;
    high["Hashimoto"]=171;
    high["Igari"]=174;
    high["Sakuma"]=180;
    high["Takahashi"]=172;

    while(b==0){
        cout << "\nHeight data" << endl;
        cout << "1. Add data" << endl;
        cout << "2. Search" << endl;
        cout << "3. delete data" << endl;
        cout << "4. Calculate average" << endl;
        cout << "Select option: ";
        cin >> a;
        if(a==1){
            add_height(high);
        }else if(a==2){
            search_height(high);
        }else if(a==3){
            delete_height(high);
        }else if(a==4){
            cout << "Average: " << average_height(high) << " cm" << endl;
        }else{
            cout << "Invalid option" << endl;
        }
        cout << "Continue? (yes:0, no:1)" << endl;
        cin >> b;
    }
    
    return 0;
}
#include <iostream>

using namespace std;

string to_upper(string line, int i){
    if(i>=line.size()) return line;
    else{
        line[i]=toupper(line[i]);
        line = to_upper(line, i+1);
    }
    return line;
    
}
int main() {
    string line;
    while (getline(cin, line)) {
        cout << to_upper(line, 0) << endl;
    } 
    return 0;
}
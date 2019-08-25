#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>
using namespace std;

string input,string_a_comparar;
vector<string>lista_imprimir;
map<string,pair<string,int>> lista;
std::vector<string>::iterator it;

void no_anagramas(string input){
    string_a_comparar = input;
    transform(string_a_comparar.begin(),string_a_comparar.end(),string_a_comparar.begin(), ::tolower);
    sort(string_a_comparar.begin(),string_a_comparar.end());
    lista[string_a_comparar].second++;
    lista[string_a_comparar].first = input;



}
bool lexico(string a, string b){
    return a<b;
}




int main() {

    while(cin>>input){
        if(input=="#")break;
        no_anagramas(input);


    }

    for(auto item : lista){
        if(item.second.second==1){lista_imprimir.push_back(item.second.first);}
    }

    sort(lista_imprimir.begin(),lista_imprimir.end(),lexico);

    for(auto item : lista_imprimir){
        cout<<item<<endl;
    }


    return 0;
}
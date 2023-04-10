#include <iostream>
#include <string>
using namespace std;

struct palavra
{
    string nome;
    int pos;
};

void ordena (palavra ptr[], int SIZE){

  int inner, outer, temp;
  string name;
  
  for (outer = 0; outer < SIZE - 1; outer++) {
    for (inner = outer+1; inner<SIZE; inner++){
      if (ptr[outer].pos > ptr[inner].pos){
        temp = ptr[outer].pos;
        name = ptr[outer].nome;
        ptr[outer].pos = ptr[inner].pos;
        ptr[outer].nome = ptr[inner].nome;
        ptr[inner].pos = temp;
        ptr[inner].nome = name;
      }
    }
  }
  
}



int main() {
  int n;
  cout << "Quantas strings serão inseridas? ";
  cin >> n;

  palavra * vet = new palavra[n];

  for (int i=0; i<n; i++){
    cin >> vet[i].nome;
    vet[i].pos = vet[i].nome.size();
  }

  /*for (int i=0; i<n; i++){
    cout << vet[i].pos << " " << vet[i].nome << endl;
  }*/

  ordena(vet, n);

  /*for (int i=0; i<n; i++){
    cout << vet[i].pos << " " << vet[i].nome << endl;
  }*/

  int match = 0;
  int menor = 0;
  int maior = 1;
  //int cont = 1;
  int contmatch = 1;
  //string smaior;
  //string smenor;

  while (maior<n){
    
    //smaior = vet[maior].nome;
    //smenor = vet[menor].nome;
    //cout << smaior << "  " << smenor << endl;
    
    match = vet[maior].nome.find(vet[menor].nome);
    
    if (match != -1){
      contmatch++;
      if (maior-menor > 1){
        menor = maior-1;
      }
      maior ++;
      menor ++;
    } else {
      maior++;
    }
    //cont++; 
  }

  cout << "\nForam encontrados " << contmatch << " matches\n";

  delete [] vet;

}
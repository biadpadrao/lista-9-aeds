#include <iostream>
using namespace std;

// Crie uma classe Equipamento com o atributo ligado (tipo boolean) e com os métodos liga e  desliga.  O  método  liga()  torna  o  atributo  ligado  true  e  o  método  desliga()  torna  o  atributo ligado false. 
class Equipamento {
private:
bool ligado;

public:
void ligar () {
  ligado = true;
  printf("O equipamento está ligado!\n");
}
void desligar () {
  ligado = false;
  printf("O equipamento está desligado!\n");}
};


// Crie uma classe EquipamentoSonoro que herda as características de Equipamento e que  possui  os  atributos  volume  (tipo  short)  que  varia  de  0  a  10  e  stereo  (tipo  boolean).  A classe ainda deve possuir métodos get para retornar valor de cada atributo e set para gravar um  valor  em  um  atributo.
class EquipamentoSonoro: public Equipamento {
private: 
short volume; 
bool stereo;

public:
void setVolume (short volume) {this->volume = volume;}
short getVolume () {return volume;}

void setStereo (bool stereo) {this->stereo = stereo;}
bool getStereo () {return stereo;}

// Crie  também  os  métodos  mono()  e  stereo().  O  método  mono() torna o atributo stereo falso e o método stereo() torna o atributo stereo verdadeiro.
void mono () {stereo = false;}
void estereo () {stereo = true;}

// Ao ligar o EquipamentoSonoro através do método liga, seu volume é automaticamente ajustado para 5.
EquipamentoSonoro (): Equipamento () {volume = 5;}
};

int main() {
  EquipamentoSonoro JBL;
  JBL.ligar();
  JBL.getVolume();
  printf("Volume: %i\n", JBL.getVolume());
  JBL.desligar();
}



// protected = classe e subclasse
// private = so a classe acessa  

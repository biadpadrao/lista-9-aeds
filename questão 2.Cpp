#include <iostream>
#include <string.h>
using namespace std;

class Pessoa {
private: 
  char nome[20];
  char sobrenome[20];
public:
  Pessoa (char *n, char *s) { // construtor com os dados de nome e sobrenome para os atributos
    strcpy (nome, n);
    strcpy (sobrenome, s);
  }
  char *getNomeCompleto() {return strcat(nome, sobrenome);} // getNomeCompleto() que não possui parâmetros de entrada e que escreve a concatenação do atributo nome com o atributo sobrenome;
};

class Funcionario: public Pessoa { // subclasse de Pessoa, chamada Funcionario
protected:
  int matricula;
  double salario;

public:
  Funcionario (char *n, char *s): Pessoa (n, s) {} //  construtor  que invoca o construtor da superclasse e acrescenta os valores aos seus atributos.
  void setSalario (double s) {salario = s;} 
  double getSalarioPrimeiraParcela() {return salario * 0.6;} // retorna o valor da primeira parcela do salário - 60%
  double getSalarioSegundaParcela() {return salario * 0.4;} // retorna o valor da segunda parcela - 40%
};

class Professor: public Funcionario { // subclasse de Funcionario, chamada Professor
public:
  double getSalarioPrimeiraParcela () {return salario;} // recebe o salário em uma única parcela
  double getSalarioSegundaParcela () {return 0;}
  Professor (char *n, char *s): Funcionario (n, s) {} //  Crie também um construtor que invoca o construtor da superclasse
};

int main() {
  double valor;
  Funcionario f("Bia", " Padrão");
  f.setSalario(2000);
  valor = f.getSalarioPrimeiraParcela();
  printf ("Valor da primeira parcela do funcionário %s: %.2lf\n", f.getNomeCompleto(), valor);
  valor = f.getSalarioSegundaParcela();
  printf ("Valor da segunda parcela do funcionário %s: %.2lf\n", f.getNomeCompleto(), valor);
  Professor p("Fulano", " Da Silva");
  p.setSalario(4000);
  valor = p.Funcionario::getSalarioSegundaParcela();
  printf("Valor do salário do professor %s: %.2lf", p.getNomeCompleto(),valor);
}

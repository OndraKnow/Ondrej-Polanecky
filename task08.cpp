/*
  Tento příklad demonstruje přetěžování operátorů << a >> knihovny iostream.

  Zapíšeme-li "cout << x << y", pak se to vyhodnotí jako "((cout << x) << y)".
  Tedy operátor << má na levé straně objekt ostream a na pravé straně to, co má vypsat.
  Návratová hodnota je objekt na levé straně (cout), po "cout<<x" se tedy provede "cout<<y".
  Knihovny iostream definuje objekt ostream "cout" pro standardní výstup a "cin" pro vstup".

  Podobně funguje i stringstream, ale vstup a výstup je zde řetězec.
  Všimněte si operátorů << a >> definovaných níže a jejich použití v metodě main.
  Tyto funkce lze také použít pro načítání Vector2 z řetězce.
  Protože stringstream dědí z iostream, zdědí se a fungují stejně jako se standardním vstupem.

  Nyní se podívejte na tento obrázek: http://www.cplusplus.com/reference/iolibrary/
  knihovna fstream, která čte a zapisuje ze souboru, funguje stejně.
  Použijte tedy tentýž kód pro ukládání Vector2 do souboru a načítání Vector2 ze souboru.
  Jediný rozdíl je v konstruktoru, který očekává jméno souboru, např.
  fstream data("data.txt");
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
using namespace std;

struct Vector2 {
  double x;
  double y;
  Vector2(double x, double y) : x(x), y(y) { }
  Vector2() : x(0), y(0) { }
};

ostream& operator<<(ostream& out, const Vector2& v) {
  out << "[" << v.x << "," << v.y << "]";
  return out;
}

istream& operator>>(istream& in, Vector2& v) {
  char c;
  in >> v.x >> c >> v.y;
  return in;
}

ofstream& operator<<(ofstream& out, const Vector2& v){
  out << v.x << "," << v.y ;
  return out;
}

ifstream& operator>>(ifstream& in, Vector2& v){
  char c;
  in >> v.x >> c >> v.y;
  return in;
}

struct Node{
  int x;
  int y;
  vector<Node> edges;
  Node(int x, int y) : x(x), y(y) { }
  Node() : x(0), y(0) { }
};

ostream& operator<<(ostream& out, const Node& nod){
  out << "x: " << nod.x << ", y: " << nod.y << endl;
  cout << "edges: " << endl;
  for(const auto& edge : nod.edges){
      out << "x: " << edge.x << ", y: " << edge.y << endl;
  }
  return out;
}

istream& operator>>(istream& in, Node& nod) {
    char c;
    in >> nod.x >> c >> nod.y;
    return in;
}



int main() {
  Vector2 a;

  // čtení a výpis Vector2 ze standardního IO
  cin >> a;
  cout << "a = " << a << endl;

  // čtení a výpis Vector2 z řetězce
  stringstream ss;
  ss << "3.14,7";
  ss >> a;
  cout << "a = " << a << endl;

  // zapisování do souboru
  cout << "writing vector 'a' to file " << endl;
  ofstream writefile;
  writefile.open("data.dat");
  writefile << a << endl;
  writefile.close();

  // čtení ze souboru
  ifstream readfile;
  readfile.open("data.dat");
  cout << "reading vector from file: ";
  Vector2 b;
  readfile >> b;
  cout << b << endl;
  readfile.close();

  // doplňte čtení a výpis Vector2 ze souboru
  // Pokuste se vytvořit vlastní třídu a definujte na ní operátory << a >>


  Node A = Node(5,4);
  Node B = Node(6,4);
  Node C = Node(5,5);
  Node D;
  A.edges.push_back(B);
  A.edges.push_back(C);
  // vypisování
  cout << A << endl;
  // zapisování
  cin >> D;
  cout << D;

}
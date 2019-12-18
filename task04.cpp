#include <cstring>
#include <cstdio>
struct Animal {
  const char* name;
  
  virtual const char* whatDoesItSay(){
	  sprintf(buff,"%s says ",name);
	  return buff;
  }
  Animal(const char* name){
	this->name = name;
  }
protected:
  char buff[48];
};

struct Dog : Animal {
  // TODO
  const char* sound;
  const char* whatDoesItSay(){
	  Animal::whatDoesItSay();
	  strcat(buff,sound);
	  return buff;
  }
  Dog(const char* name, const char* sound):Animal(name){
	  this-> sound = sound;
  }
};

struct Fox : Animal {
  const char* sound;
  const char* whatDoesItSay(){
	  Animal::whatDoesItSay();
	  strcat(buff,sound);
	  return buff;
  }
  Fox(const char* name, const char* sound):Animal(name){
	  this-> sound = sound;
  }
};

int main() {
  Animal* animals[] = {
    new Dog("dog", "woof"),
	new Fox("fox", "ringidingidingidingiding")
    
  };
  for(Animal* animal : animals) {
    puts(animal->whatDoesItSay());
  }
  // dog says woof
  // fox says ringidingidingidingiding
}
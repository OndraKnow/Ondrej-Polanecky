#include <cstring>
#include <cstdio>
struct Animal {
  const char* name;
  const char* sound;
  
  virtual const char* whatDoesItSay(){
  sprintf(buff,"%s says %s",name,sound);
	  return buff;
  }
  Animal(const char* name){
	this->name = name;
	this->sound = "";
  }
  
protected:
  char buff[48];
};

struct Dog : Animal {
  // TODO

  
  Dog(const char* name, const char* sound):Animal(name){
	  this-> sound = sound;
  }
};

struct Fox : Animal {
  
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
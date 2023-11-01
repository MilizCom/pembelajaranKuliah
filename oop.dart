class Animal1 {
  String? name;
  int? numberOfLegs;
  int? lifeSpan;
  Animal({required String name, required int kaki, required int umur}) {
    this.name = name;
    this.numberOfLegs = kaki;
    this.lifeSpan = umur;
  }

  void printdata() {
    print(name);
  }

  void display() {
    print(numberOfLegs);
  }
}

class Darat extends Animal1 {
  void display() {
    printdata();
    super.display;
    print(lifeSpan);
  }
}

void printer(
    {required String nama, required int NumberOfLegs, required int lifeSpan}) {
  print('nama: $nama kaki: $NumberOfLegs umur: $lifeSpan');
}

void printAnimalObjec({required Animal1 animal}) {
  print("Animal name: ${animal.name}");
  print("Number of Legs: ${animal.numberOfLegs}");
  print("Life Span: ${animal.lifeSpan}");
}

class Messege {
  String? sucses;
  String? error;
}

class Error extends Messege {
  void displayError() {
    print(error);
  }
}

class Sucses extends Messege {
  void displaySucses() {
    print(sucses);
  }
}

void main() {
  Animal1 anjing = Animal1().Animal(name: 'arkad', umur: 10, kaki: 4);
  Animal1 buaya = Animal1().Animal(name: 'bagong', kaki: 0, umur: 100);

  buaya.name = 'paldi';
  anjing.name = 'arkad';
  anjing.numberOfLegs = 4;
  anjing.lifeSpan = 10;

  printer(
      nama: anjing.name!,
      NumberOfLegs: anjing.numberOfLegs!,
      lifeSpan: anjing.lifeSpan!);
  printAnimalObjec(animal: buaya);
}

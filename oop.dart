class Animal {
  String? name;
  int? numberOfLegs;
  int? lifeSpan;
  Animal({required String name, required int kaki, required int umur}) {
    print("ada mi $name");
    this.name = name;
  }
  void printdata() {
    print("adakah100");
  }
}

void main() {
  Animal anjing = Animal(name: 'arkad', umur: 10, kaki: 4);
  Animal buaya = Animal(name: 'bagong', kaki: 0, umur: 100);

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

void printer(
    {required String nama, required int NumberOfLegs, required int lifeSpan}) {
  print('nama: $nama kaki: $NumberOfLegs umur: $lifeSpan');
}

void printAnimalObjec({required Animal animal}) {
  print("Animal name: ${animal.name}");
  print("Number of Legs: ${animal.numberOfLegs}");
  print("Life Span: ${animal.lifeSpan}");
}

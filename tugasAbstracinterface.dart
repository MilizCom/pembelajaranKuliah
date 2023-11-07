abstract class NPC {
  void atribut(
      {required int healt, required int stamina, required String name});
  void talk({required String interaksi});
}

class teman extends NPC {
  @override
  void atribut(
      {required int healt, required int stamina, required String name}) {
    print(name);
    print(healt);
    print(stamina);
  }

  @override
  void talk({required String interaksi}) {
    print(interaksi);
  }
}

class musuh extends NPC {
  @override
  void atribut(
      {required int healt, required int stamina, required String name}) {
    print(name);
    print(healt);
    print(stamina);
  }

  @override
  void talk({required String interaksi}) {
    print(interaksi);
  }
}

void main() {
  teman obiwan = teman();
  obiwan.atribut(healt: 100, stamina: 10000, name: "obiwan");
  obiwan.talk(interaksi: "halo bujang");
  musuh Arkad = musuh();
  Arkad.atribut(healt: 700, stamina: 10, name: "arkad");
  Arkad.talk(interaksi: "mana ki jordi");
  List<Map<String, teman>> player = [
    {"paldi": teman()},
    {"hidir": teman()},
    {"inul": teman()},
    {"aidil": teman()},
  ];
  player[0]["paldi"]!.atribut(healt: 100, stamina: 200, name: "paldi");
  player[0]["paldi"]!.talk(interaksi: "kamu mau makan?");
}

abstract class Vehicle {
  // Abstract method
  void start();
  // Abstract method
  void stop() {
    print("stop");
  }

  void modulo() {
    print("adakah");
  }
}

class Car extends Vehicle {
  @override
  void start() {}
  @override
  void stop() {
    super.stop();
  }

  @override
  void modulo() {}
}

class Bike extends Vehicle {
  // Implementation of start()
  @override
  void start() {
    print('Bike started');
  }

  // Implementation of stop()
  @override
  void stop() {
    print('Bike stopped');
  }
}

void main() {
  Car car = Car();
  car.start();
  car.stop();

  Bike bike = Bike();
  bike.start();
  bike.stop();
}

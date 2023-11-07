Future<void> fetchingData() {
  return Future.delayed(Duration(seconds: 3), () => print("berhasil data"));
}

void main() async {
  await fetchingData();
  print("loading");
}

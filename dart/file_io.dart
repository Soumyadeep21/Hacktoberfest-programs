import 'dart:io';

void main() async {
  try {
    File file = File('sample.txt');
    if (await file.exists()) {
      List<String> lines = await file.readAsLines();
      int wordCount = countWords(lines);
      print("Word count: $wordCount");
    } else {
      print("File not found.");
    }
  } catch (e) {
    print("An error occurred: $e");
  }
}

int countWords(List<String> lines) {
  int count = 0;
  for (String line in lines) {
    List<String> words = line.split(' ');
    count += words.length;
  }
  return count;
}

void main() {
  String input = "racecar";
  bool isPalindrome = checkPalindrome(input);
  
  if (isPalindrome) {
    print("$input is a palindrome.");
  } else {
    print("$input is not a palindrome.");
  }
}

bool checkPalindrome(String text) {
  String reversed = text.split('').reversed.join('');
  return text == reversed;
}

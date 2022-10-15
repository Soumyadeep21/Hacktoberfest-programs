import 'dart:convert' as convert;

import 'package:http/http.dart' as http;

void main(List<String> arguments) async {
  // This example uses the Google Books API to search
  // for books about HTTP. For details, see
  // https://developers.google.com/books/docs/overview
  final url = Uri.https(
    'www.googleapis.com',
    '/books/v1/volumes',
    {'q': '{http}'},
  );

  // Await the HTTP GET response, then decode the
  // JSON data it contains.
  final response = await http.get(url);

  if (response.statusCode == 200) {
    final jsonResponse = convert.jsonDecode(response.body);
    final itemCount = jsonResponse['totalItems'];
    print('Number of books about HTTP: $itemCount.');
  } else {
    print('Request failed with status: ${response.statusCode}.');
  }
}

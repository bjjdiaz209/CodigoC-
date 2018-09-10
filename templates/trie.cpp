

//Remember, no memory leaks, trying to have the best possible performance.

//  https://en.wikipedia.org/wiki/Trie

 

     

void show_items_int(const string& s, const int& x)

{

      cout << s << "; " << x << "\n";

}

 

void show_items_person(const string& s, const Person& p)

{

      cout << s << "; " << p.first_name << " " << p.last_name << "\n";

}

 

int main()

{

      TRIE<int> nums;

      nums.add("uno", 1);

      nums.add("dos", 2);

      nums.add("tres", 3);

      nums.add("cuatro", 4);

      nums.add("cinco", 5);

      nums.add("seis", 6);

      nums.add("siete", 7);

      nums.add("ocho", 8);

      nums.add("nueve", 9);

      nums.add("diez", 10);

     

      cout << nums["cinco"] << "\n";

      cout << nums["veinte"] << "\n";

     

      nums.get_all_items_that_start_with("ci", show_items_int);

 

      TRIE<Person> people;

      people.add("12039212", Person { "Juan", "Perez" });

      people.add("56934568", Person { "Maria", "Lopez" });

      people.add("56934566", Person { "Alfredo", "Acuna" });

      people.add("56934554", Person { "Jaime", "Aguirre" });

      people.add("12039763", Person { "Brian", "Lopez" });

     

      people.get_all_items_that_start_with("12", show_items_person);

     

      cout << "************\n";

     

      auto people2 = people;

      people2.add("56934555", Person { "Pablo", "Bellido" });

      people2.add("569345556", Person { "Marcelo", "Rollano" });

      people2.get_all_items_that_start_with("56", show_items_person); // should show 5 elements

     

      cout << "************\n";    

      people.get_all_items_that_start_with("56", show_items_person); // should show 3 elements

      return 0;

}

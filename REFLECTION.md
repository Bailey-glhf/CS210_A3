Reflection Questions

1. In LinkedList::deleteFront(), why does it take two separate delete calls instead of one?
   Name exactly what each one frees, and name the two new calls back in the program responsible
   for putting them on the heap in the first place.

    
    1) The deleteFront call has two seperate delete calls because the first delete (with arrow) removes 
    the value and the next pointer, and the second delete removes the space that was holding those. The two 
    new calls that put them in the heap in the first place are the "list->addFront(new int(10));" adds in 
    the main function which calls to "Node<T>* fresh = new Node<T>(value);" setting "fresh->next = head_;" 
    and "head_ = fresh;".
2. ArrayList never had a destructor before today. Explain, in your own words, why switching
   from T data[CAPACITY] to T* data_[CAPACITY] is what made a destructor necessary, and what
   would happen if you forgot to write one. Would you get a compiler error? Why or why not?


    2) Before when we used T data[CAPACITY] our values were stored in stack memory, meaning they'd be 
    deleted when the list is. With T* data_[CAPACITY] we are storing these values with nodes in 
    the heap so they exist even after the list is deleted so we need a destructor to delete them
    manually. Without a deconstructor deleting these values we'd get memory leaks (allocated unused mem)
    , but we wouldn't get a compile error since technically it can run without it as long as it 
    doesn't run out of memory in that instance.

3. search() and addFront() both take a T*, but they treat that pointer completely differently.
   Explain the difference in terms of ownership: which one is allowed to delete what you hand it,
   and which one is never allowed to?


    3) For our search our value is treated as a constant, so that function doesn't have ownership
    over it and can't alter or modify it in anyway, no delete capability, the passed value is owned
    by the main function that gave it. The add function has no constant constraints so the list can 
    take ownership of it and delete/modify it within the list functions.


4. You swapped LinkedList<T> for ArrayList<T> inside makeList() and reran main.cpp without
   changing a single line there. What two mechanisms, by name, made that possible?


    4) Encapsulation and inheritance make this possible. The inheritence is done with the
    "public List <T>" after the class start for ArrayList and LinkedList, and the encapsulation
    is done with our private variables.


5. Pick one keyword from the Key Terms glossary that you either had to add today or wouldn’t have
   thought to add on your own (explicit, override, virtual, const, or any other). Describe, in
   your own words and without copying the guide’s wording, the smallest example you can think
   of where leaving it out would cause a real problem.


    5) The keyword that I had trouble with on this lab was virtual. In the List class testing the program
    when testing the alternate return, I couldn't compile while the virtual was there and I still had
    overrides in the ArrayList destructor. With virtual in this case caused a mismatch, but with the original
    return statement if I had forgotten the virtual I also wouldn't have been able to compile since I'd 
    need the virtual and override (in deconstructor) to ensure they can prevent the heap memory leaks.

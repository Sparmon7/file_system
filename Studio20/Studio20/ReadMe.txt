Studio 20 ReadMe.txt

1) Garrett Ramsey, Ethan Weilheimer, Spencer Armon

2) It is necessary to delete the pointer to the actual file in the destructor, because if it is ignored there will
be a memory leak when the PasswordProxy object is destroyed.

4) To test the functionality of our password proxy, we made a PasswordProxy object and tested each of the member functions
both with and without the correct password. The results were as expected.

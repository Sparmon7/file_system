Spencer Armon, Garrett Ramsey, Ethan Weilheimer
CSE 332S Lab5

What this program does:
This program simulates a command line with image and text files, as well as commands to interact with these files.

How this work was split up:
The work was initially done with all three of us together doing work whether it was in class or on our own time.
Later, we began working individually on parts of it and meeting up after to figure out what was left.
Notably, Garrett worked on debugging, Ethan worked on DisplayCommand, and Spencer worked on MacroCommand. It is difficult to list every individual contribution but overall, the work was shared evenly and fairly.

Associated Files:
This project has a bunch of different files, but they are split up primarily between command files, visitor files, parsing strategies, file types/systems, factories, and the main Lab5.cpp file.

Return values:
This project should only ever return 1, which is an error value corresponding to quit. Although it seems counterintuitive that there is no possibility for a successful program, it makes sense, since our while loop should only ever be terminated if the user chooses to terminate it. This is why it should always return an error value of 1.

Our additional MacroCommand:
We created a MacroCommand that is a combination of cat and ds. It is called using cd and it allows you to use the cat command and the ds command. We built in the ability to use one (or both) of -a and -d in the cat and display commands respectively.
We tested this command using a fake file, and then a real file with the following possibilites after the file name: -a, -a -d, -d, (nothing). Each worked as expected.


Errors encountered:
1. One error that we had to deal with was testing for the ds -m command. When coding it, we thought it worked when testing it ourselves but it was failing the unit tests. After some time looking through it, it became apparent we made a simple mistake with the manner in which our display visitor printed things out, since it went in the wrong order. This was an easy fix.
2. Another error was with the cat -a command. It also failed the unit tests because we thought the only difference with the -a was that it printed out the contents before, not realizing it also appends instead of writing over it. 
3. The final error we found was with forgetting to close files out of laziness. It made us fail many unit tests, so that was a tedious fix.


Tests:
The first test we ran was the unit tests, which all passed (eventually).
We then tested the quit command, which also worked as expected.
We also tested help and it printed out all the commands, as expected.
I then tested the following commands:
-touch
-cat
-ls
-ds
-copy
-rn
-rm

For each command, they were tested on both image files and text files (of the password and non-password varieties), as well as non-existent files. If the commands had possibilities after them (including -a, -d, etc.), we tested those as well. Although most of these should have been covered by the unit tests, we wanted to make sure, so we ran these tests, which all worked as expected. We also tried help then each of the above command names, to make sure the descriptions worked.
The most important tests were the cd command ones, since these were not covered by the unit tests. We checked the following 4 options on both image and text files: nothing, -a, -d, -a -d, and they all passed.

Design decisions:
One design decision we made was in our special cd macro command, we made it so you could choose to include -a and -d for the cat and ds commands respectively. Specifically, we made it more user-friendly by allowing the user to include one, neither, or both, which meant the parsing method had to determine what information to send to each command. The tricky part about this is what happens if there is no -a but a -d, but for the sake of usability, we made it possible to not need a placeholder for -a and simply type -d after.
Another decision we made was to allow copies of password files without supplying the password. To do anything with the file, you need to supply the same password, so the file information remains secure. Professor Shidal said to do this, so we did.
For the extra credit, we decided to make it so that if the file the user is trying to set the permission of writability for does not exist, a new file is created. 

Extra Credit:
For the extra credit, I created a Chmod proxy that inherits the Abstract File interface. By doing this, I was able to override the functions the same way we did for password proxy with the appropriate code for a Chmod enabled file.
The chmodProxy object also contained a variable indicating whether or not it could be written to (which is checked upon write and append attempts).
As for when a user tried to switch the permission on a chmod file, the class will clone the object, delete the old one and assign the new one the proper permission (writable or not writable) depending on the user input before placing it in the file system.
Once the proxy object was created, the variable containing the permissions could be changed accordingly.


Tests Ran for Extra Credit:
I tested the chmod command with a + and minus following and then tried to use cat on each file to see if it would allow me to write. 
I wrote to a file, switched it to read-only, tried to write, switched it back to writable, and then wrote it. 
I tested this with image files, text files, and password files.
I tried the chmod command without a + or minus. Result: Command failed. 

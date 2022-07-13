Mahgabin Khanom
Procedure :
1) make big five functions to default
2) sequence MAP constructs two strings, which is recognition sequence and enzyme acronyms. Therefore, they need to equal to each other from left hand side to right hand side
3) operator< shows the comparison from left hand side to right hand side (rhs is bigger)
4) operator<< will print out all the values for enzyme acronyms in the file 
5) merge function= first has an edge case checking if theyre equal to each other and then the enzyme acronyms push back (since its a vector) to the other sequences enzyme acronym values based off the for loop
6) query tree is altered with the new function value being filled in, as the new file is ifstreamed in and then skipping the first ten lines
7)
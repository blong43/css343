1. Describe the state of your program, exactly what works and what does not work. 

	I believe all the classes work as they should and the output is correct.
	I don't know if there is really anything in my program that doesn't work
	but I tested many cases and haven't crashed, so that's a good sign.
	 
2. List your hash table(s): briefly what they are used for and file found in. 
     (Include any factories that are essentially hash tables.) 

	The Product and Command factories both use hash tables to sort their
	data. They are used to create new products (genres) and new commands.
	I'm not sure what you mean by 'file found in', but they are included in
	the manager class to create new objects per function calls.

3. Describe which file and which function you read the movie data, high level function call,
     	 i.e., how/where it gets into your movie collections.

	The function I read the movie data with is the setData and setCmdData in
	the Product class, which its children will take in and sort out by itself.
	The movie collections is stored in an hash table of BSTs, and they are
	inserted into the tree as the data4movie.txt file gets read in the
	StoreManager class, in the buildInventory(istream&) function.

4. Describe which file and which function you read command data, high level function call,
     	 i.e., how/where you perform the commands/transaction​s. 

	The function I use to read command data is the storeCommand() function
	which is in the Command class. It is performed in the runCommands()
	function and is located in the StoreManager class. The storeCommand()
	function sets the data into the object that is created in the class and
	then that command is created.

5. Describe any dirty little secrets (e.g., switch used, or if-else-if, etc.) 
     If you feel they do not violate the open-closed design principle, explain. 

	I think in the StoreManager class, the runCommands() function has way too
	many if-else statements that kill the readability of that function as a
	whole. I do not think it violates the open-closed design principle because
	it understands what to do with the command code that it is given.
	Some areas of this program that may contain violations of the open-closed
	design principle would be the variables in each class, such as director,
	title, genre, year; the only way to add more is by accessing a class and
	adding them in, meaning I would need to create a class that could create
	new variables. 

6. Describe anything you are particularly proud of ... 

	The scale of this project was quite large, and hard to figure out where 
	to start and what to keep from the design to make the program work. 
	The implementation phase of the program was quite difficult with all the
	inheritance that was happening. In the end, I am proud of myself for
	finishing the project on time and getting output.

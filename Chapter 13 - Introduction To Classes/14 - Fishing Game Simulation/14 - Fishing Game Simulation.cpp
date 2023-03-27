14. Fishing Game Simulation

For this assignment, you will write a program that simulates a fishing game.In this
game, a six - sided die is rolled to determine what the user has caught.Each possible
item is worth a certain number of fishing points.The points will not be displayed until 
the user has finished fishing, and then a message is displayed congratulating the user
depending on the number of fishing points gained.
Here are some suggestions for the game’s design :
• Each round of the game is performed as an iteration of a loop that repeats as long
as the player wants to fish for more items.
• At the beginning of each round, the program will ask the user whether he or she
wants to continue fishing.
• The program simulates the rolling of a six - sided die(use the Die class that was
	demonstrated in this chapter).
	• Each item that can be caught is represented by a number generated from the die.For
	example, 1 for “a huge fish, ” 2 for “an old shoe, ” 3 for “a little fish, ”and so on.
	• Each item the user catches is worth a different amount of points.
	• The loop keeps a running total of the user’s fishing points.
	• After the loop has finished, the total number of fishing points is displayed, along
	with a message that varies depending on the number of points earned.
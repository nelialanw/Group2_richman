# Group2_richman
#### Team Members:
Li Chi Shing (nelialanw) u3571237@connect.hku.hk<br>
Wong Wing Lam (WongWingLam) u3568502@connect.hku.hk
## Game Discription
This is a text-based game similar to Monopoly and we called it Richman.
Richman is single/multiple players game that can be played on command-line interface.
Here's the flow of the game.
1. Executing the compiled cpp of the game.
2. Select the game's mode i.e. Single or Double, Difficulties,etc.
2.1 Single is offline module while double is online module?
2.2 Difficulties: Easy/ Medium/ Hard; main difference will be the initial fund that the player has and if the inflation factors are activated.
3. Game starts
3.1 Players and computers (in total 4 participants) were represented by their chesses and placed in a squared path with the same starting point which also represents the end of a loop. In each round, participants roll dice (1 per each time) sequentially and the chess steps with the dice's number clockwisely. There are 10 steps each side with 4 corners (in total 44 steps as one loop). Each corner represents a public facility including 1. Starting point, 2. Hospital, 3. Prison, 4. Car Park while each step represents either property, chance or destiny. Participant who first stepped on the property step has the authority to purchase the property and become the owner depending on the wealthiness of the participant and price of the property. The last partcipant who remains in the game and didn't bankrupt will win.
3.2 Chance: Participant who stepped on the Chance step will draw a chance card randomly from the chance library which stored with some different chances that are beneficial to the particpants. Chance library will be reset once the last chance card is drawn.
3.3 Destiny: Participant who stepped on the Destiny step will draw a destiny card randomly from the destiny library which stored with some different destiny that are destructive to the particpants' wealth or chances to win. Destiny library will be reset once the last destiny card is drawn.
3.4 Starting point: Partcipants who finished a loop and stepped on/ passed through the starting point will get a starting fund from the central bank.
3.5 Hospital: Destiny card's penalty which keeps the participants in there and skips their chance from rolling dice. Participants resume playing from the Hospital.
3.6 Prison: Same as Hospital.
3.7 Car Park: For damaged car?
## Features/Functions

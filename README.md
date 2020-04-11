# Group2_richman
#### Team Members:
Li Chi Shing (nelialanw) u3571237@connect.hku.hk<br>
Wong Wing Lam (WongWingLam) u3568502@connect.hku.hk
## Game Discription
This is a text-based game similar to Monopoly and we called it Richman.
Richman is single/multiple players game that can be played on command-line interface.
Here's the basic rules of the game.
### Game Mode
1. Single mode: player vs 3 AIs
2. Multiplayer mode: 2-4 players 
### Game Flow
Players / computers were represented by their chesses and placed in a squared path with the same starting point which also represents the end of a loop. Each of them will have an initial cash of $100000. In each round, participants roll dice (1 per each time) sequentially and the chess steps with the dice's number clockwisely. There are many opportunities for the participants to earn/lose money during their journey in the map. Participlants whose total assests drop to 0 will bankrupt. In the end, the last partcipant who remains in the game and didn't bankrupt will win. 
### Map Setting
There are 10 steps each side with 4 corners (in total 44 steps as one loop). Each corner represents a public facility including 1. Starting point, 2. Hospital, 3. Prison, 4. Winglam Water&Electricity Ltd. while each step represents either property, chance/destiny, Chi Shing Store<br>
* **Property**
<br>participant who first stepped on the property step has the authority to purchase the property and become the owner depending on their cash and price of the property. Other participants have to pay rent to the owner when they step into other's property. Owner of the property can invest and upgrade it in order to receive more rent when he steps into the property again
* **Chance/Destiny** 
<br>Participant who stepped on the Chance/Destiny step will draw a chance/destiny card randomly from the library which stored with some different chances/destinies that are beneficial/destructive to the particpants. 
* **Hospital**
<br>Participants may get into hospital due to different events and skips their chance from rolling dice for 1-3 rounds. Participants resume playing from the Hospital.
* **Prison**
<br>Same as Hospital.
* **Alan Water&Electricity Ltd.**
<br>Participants have to pay money base on the number of property they owns
* **Chi Shing Store**
<br>Participants can buy some special tools when they stepped in
### Special Tools
Pariticipants can use special tools in their round before rolling the dice. Special tools have several effects such as control the dice in their round, shoot a missile to a player in order to send him to the hospital
### Centre Bank Service
Pariticipants can use centre bank service in their round before rolling dice. There are 2 services,
* **Loan**
<br>Borrow a maximum of $100000 cash, and have to return part of the loan with interset when passing through the starting point
* **Mortgage**
<br>Mortgage their properties in order to get cash, the moetgaged properties cannot charge rent from other players before unmortgage, properties can be unmortgaged when passing through starting point
## Features/Functions
### Dice rolling
Roll a dice in range of 1-6 randomly and return the number
### Event triger
Event and its effect will be store in csv file, and will be randomly drew and triger the effect when player stepped in the Chance/Destiny 
### Status storing
Using structures to store the game status (i.e. name/cash of each players, property ownerships, etc)
### Saving/Loading game
Game status (i.e. name/cash of each players, property ownerships, etc) will outout to csv files when using safe function in the game, and can input the file before game start in order to load the pervious game
### Rent/Interest calculation
Calculate the rent/ interest need to pay by the player
### Display
Display the map and the corresponding position of the players
### Program codes in multiple files
Functions will be codes in multiple files for collaboration
### Daynamic memory management
Variables will daynamically allocate memory if nacessary 

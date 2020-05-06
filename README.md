# Group2_richman
#### Team Members:
Li Chi Shing (nelialanw) u3571237@connect.hku.hk<br>
Wong Wing Lam (WongWingLam) u3568502@connect.hku.hk
## Game Discription
This is a text-based game similar to Monopoly and we called it Richman.
Richman is single/multiple players game that can be played on command-line interface.
Here's the basic rules of the game:
### Game Mode
1. Single mode: 1 player vs 3 AIs
2. Multiplayer mode: 2-4 players 
### Game Flow
Players / computers were represented by their chesses and placed in a squared path with the same starting point which also represents the end of a loop. Each of them will have an initial cash of $100000. In each round, participants roll dice (1 per each time) sequentially and the chess steps with the dice's number clockwisely. There are many opportunities for the participants to earn/lose money during their journey in the map. Participlants whose total assests drop to or below 0 will bankrupt. In the end, the last partcipant who remains in the game and didn't bankrupt will win. If the player(s) get bankrupted before AI, the game ends and annouces "Player lost".
### Map Setting
There are 10 steps each side with 4 corners (in total 40 steps as one loop). Each corner represents a public facility including 1. Starting point, 2. Hospital, 3. Prison and 4. E.Harbour Crossing, while each step represents either property, chance, destiny.
* **Property**
<br>participant who first stepped on the property step has the authority to purchase the property and become the owner depending on their cash and price of the property. Other participants have to pay rent to the owner when they stepped into other's property. Owner of the property can invest and upgrade it in order to receive more rent when he steps into the property again.
* **Chance/Destiny** 
<br>Participant who stepped on the Chance/Destiny step will draw a chance/destiny card randomly from the library which stored with some different chances/destinies that are beneficial/destructive to the particpants. 
* **Hospital**
<br>Participants may get into hospital due to different events and skips them from rolling dice for 1-3 rounds. Participants resume playing from the Hospital.
* **Prison**
<br>Same as Hospital.
## Features/Functions
### Dice rolling
A function returns the number of steps in range of 1-6 randomly.
### Event triggering
Event and its effect will be stored in .txt file, and will be randomly drew and trigger the effect when player stepped into the Chance/Destiny.
<br>Events in Macro-environment (fFunction): After 5 complete rounds of rolling dice, random events will happen to affect the macro-environment. For instance, earthquarkes to destroy the buildings, inflation to increase the price for everything, etc.
<br>Chance header: Stores the list of chances and effects (function) of Chance.
<br>Destiny header: Stores the list of Destinies and effects (function) of Destiny.
### Status storing 
Using structures to store the game status (i.e. name/cash of each players, property ownerships, etc).
<br>Two types of variables to store players' status:
#### Static
Information like name, cash, position in map, rolling rounds in the game, sequence of rolling dice, etc, will be stored in a static array which are necessary information of each player.
#### Dynamic
Information like Property ownership, special tools ownership, loan, etc. will be stored in dynamic arrays.
### Saving/Loading game (File I/O)
Game status (i.e. name/cash of each players, property ownerships, etc) will outout to .txt files when using Save function (File out) in the game, and can load game status via Load function (File in) before game start.
#### Save Function
Save header used to access save function which calls the file output to location /Save_status/<user-input>.txt and display 3 fixed saving slots with the player-tailored name. 
<br>Player can save into particular slot and over-write the original save file. 
<br>Save function writes game's and players' statuses into a .txt file with specific format.
#### Load Function
Load header used to access load function which calls the file input and display 3 fixed saving slots. 
<br>By choosing the saving slot, the load function returns game status to the game's main functoin.
<br>Load function reads game's and players' statuses from a .txt file with specific format.
### Rent/Interest calculation Function
Calculate the rent/ interest need to be paid by the player and arrange the deduction for payer's assets and increment for owner's assets.
### Display
Display the map, status of properties, and the corresponding position of the players
### Program codes in multiple files
Functions will be coded in multiple files for collaboration.
### Daynamic memory management
Variables will dynamically allocate memory if necessary. (e.g. status storing)

# quantumPang
pang type of game using quantum theory concepts

### 0.What is quantumPang
![image](https://user-images.githubusercontent.com/58128848/96974153-c9f9eb00-1553-11eb-8861-88ee1d5cf044.png)

It is a game of pang type that uses quantum entanglement concepts in the game.

Basically, it is a game that collects blocks of the same color and explodes to get points.

However, you can separate blocks so that they exist at the same time in two different locations with a 50% probability, as quantum, 

and you can merge them.

this aims to score high points by exploding blocks at once using these properties.

See below for details.

### 1.compiled distributionfile download path
on Windows, you can download the game from the link below, extract it, and run it right away to play.
https://www.notion.so/f87e13edb6334beeaf1b07f20e063c14

### 2.operation

Menu movement: Up, Down key

Select Menu: Spacebar or Enter

Optional value adjustment: Left, Right keys

Block movement: Up, Down, Left, Right keys

Quantum Separation: ALT

Quantum Merge: C

Drop Block: Spacebar

End Game: Esc

### 3.main menu
![image](https://user-images.githubusercontent.com/58128848/96973820-5f48af80-1553-11eb-82b1-4ef12ce85c20.png)

from the top, it means 'start game', 'game settings'

### 4.game settings
![image](https://user-images.githubusercontent.com/58128848/96973862-6ec7f880-1553-11eb-8323-e83833824720.png)

Selecting 'Game Settings' from the main menu will take you to the options page above.

from the top, it means 'width', 'hight', 'merge mode', 'save settings'.

'width' and 'hight' is a function that allows you to set the number of blocks that can be placed on the screen when playing a game.

Please check the 'merge mode' below for a description of the merge mode.

### 5.How to play
![image](https://user-images.githubusercontent.com/58128848/96973970-8d2df400-1553-11eb-8d95-b5d0c30b102f.png)

Basically, you can use the space bar to position blocks of different colors by moving the arrow keys as shown above.

The blocks must be placed in 8 seconds, and when the time is exceeded, you lose your score, and it changes to a different color randomly.

When three blocks of the same color are attached, they disappear and get points.

assume that the number of blocks of the same color disappeared at once is n, 

then you'll get 1+2+3+4+...+n scores.

Therefore, the more blocks you pop at once, the more points you'll get

![image](https://user-images.githubusercontent.com/58128848/96976139-6d4bff80-1556-11eb-9c71-be5ad0a40edd.png)

But as soon as the three blocks are attached, they pop right away, so after placing the blue blocks in a cross-shaped position,

if you put a blue block in the middle, you can score 45 points with a total of nine blocks burst.

However, using quantum separation, you can get higher scores.

![image](https://user-images.githubusercontent.com/58128848/96974021-9cad3d00-1553-11eb-8d6a-11edb0f02e2d.png)

Instead of placing blocks using the space bar, 

you can place blocks through the ALT key, they will be placed as dimly colored blocks as above.

Also, if you press the ALT key, you must place one block in two locations.

These two-positioned blocks are actually one block, but they exist at the same time with a 50% chance.

So no matter how many blocks are attached around, they don't pop.

![image](https://user-images.githubusercontent.com/58128848/96974153-c9f9eb00-1553-11eb-8861-88ee1d5cf044.png)

And with the quantum separation block as shown above, pressing the quantum merge 'c' key will confirm the block as the location of either of the two as shown below.

![image](https://user-images.githubusercontent.com/58128848/96974176-d2522600-1553-11eb-91e0-612d2971d542.png)

At this time, if there are more than three same blocks around, they will pop. This allows you to pop more blocks than nine at once.

the method of merging depends on the merge mode of the options.

Please check the merge mode below for a description of the merge mode.

If you press the ALT key to place quantum separated blocks, you must place them in two different locations.

After placing the first quantum separation block, press the ALT key again to place the second block elsewhere.

While these two blocks are being placed, the time passes, 

and if you exceed 8 seconds, you'll lose some points.

However, the blocks currently being deployed do not change. The placement of 2 blocks must be completed.

### 6. merge mode
Merge mode has two modes: 0 and 1. It can be set in Options.

If the merge mode is 0, pressing the c key will merge all the blocks that have been quantum separated so far.

in merge mode 1, if you press the c key, Only blocks that are the same color as the blocks you are currently placing are merged.

### 7. discovered bug

After placing the first quantum block with the ALT key, press the c key to attempt the merge, 

and even the quantum block that has not yet been placed is determined at that location.

At this point, if you place the second quantum block that needs to be placed, the block is placed at a third location with a 50% probability, even though the block has already been determined by a 100% probability.

Although it is a bug, it is not modified because it can be used for gameplay as a strategic element.


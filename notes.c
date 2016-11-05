/*
 *TO USE MAIN, SIMPLY COMPILE IT.  THEN USE THE COMMAND IN THE COMMAND_ARGS.TXT FILE,
 CAT COMMAND_ARGS, COPY PASTE
 *
 GIT BRANCH STUFF:
 git branch -    //shoows branch
 git branch -a  //shows all branches local and remote
 git branch -r //shows only remote branches.
 git checkout gould //to checkout the gould branch
 
 *
 *
EVERYTHING BELOW HERE ARE PERSONAL CODING NOTES.

 *

get input,
assign to 3d matrix
verify /update soduku
-if not a valid soduku, return error.
you now have verified soduku
pick square to solve, pick square with least options.
-try to solve
-recursively call down on itself to solve.
-if it fails, then return error.
-if it passes, updated passes count.
Iif it fails start back at verified soduku.
-updated so the value you tried is no longer an option.
-repeat process on next options.
If it passes, and passes > 1, then fail it.
save each solution so you can call them later if necessary.


backtracking algorithm

a 9 x 9 cube
made of 9 3 x 3 squaes

81 spaces all together.

9 left to right rows
9 top to bottom columns
9 squares
each have to have the numbers 1 through 9.

column match
row match
square match

calculate row possible in each square
calculate column possible in each column
- do cross match until you get down to one.

then do square compare if you have to.

if there is more than 1 solution, then it fails as not a true soduku
so you say it's not a valid soduku.
display "Error" followed by a line break.

will have to backtraced to find all possible solutions.

steps:
get soduku
see if it has "given" solutions already by checking rows, squares, and columns.  
you now have a "updated soduku"
make sure updated soduku is the best you can, therte are no more "simple solve" cases.
then pick a square with the least number of possible solutions - min 2.
pick a number.
this is "backsolve_soduku"
resolve it.
-if that can'ts olve, return error.
__determinme what can't solve means.
-reset backsolve soduku with eliminated value.
-send back through simple solve "verify soduku. for example if it has just one solution then it can update otehr columns and rows.
this is the new backsolve soduku.
pick a number for the next one in the box.
repeat.
poor computer will be working forever!




*/

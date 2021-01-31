To run the problem:
1. Run make clean
2. Run make
3. run ./my_game 

Then the game should be open with a rocket launch site picture, a blue rectangle, and an animation of a rocket.

Requirements for the project are:
1) Load an image from outside the program, and display it (3pts)
    The launch site and the rocket is an image from outside the program

2) Use the SDL_Rect class to fill some part of the screen (3pts) - not using an image.
    The blue rectangle is made from the SDL_Rect class, and no outside image is used

3) Add some form of animation to make it interesting (3pts)
    The rocket animation should go up and reapear at the bottom of the screen. It should repeat the animation.
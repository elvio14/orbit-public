NOTE: This was my submission to Ubisoft Toronto NEXT 2024.

[January 2024]

Part 1: Introduction

“Orbit” is a 2D multiplayer game set in outer space. The players play as a spaceship with the ability to defy gravity by launching from planet to planet while being actively influenced by each planet’s gravitational forces. While flying in space, the players can boost against the gravitational force that is affecting them to steer toward the desired direction. 

The game's objective is to collect 1000 points earlier than the opponent. Points are gained by passing through as much area as you can, represented by dots. The dots, that the player occupies by passing through them, will change colour to the player’s colour and can be stolen by the opponent. There are five special bonus dots that are worth 150 points each, while each regular dot is worth only one point. Therefore, the gameplay is mostly focused on occupying the five special bonus dots to reach 1000 points as quickly as possible while trying to steal the opponents’ dots.

What makes this game fun?

The physics of gravitational forces by the planets becomes a fun challenge. Experiencing a space simulation in itself is already fun. The bigger the planet, the bigger the mass and therefore also the gravitational force. The player needs to get familiar with how their spaceship reacts to those forces, and how to use it to their advantage.
It is fair and simple. A game becomes fun when the rules are simple but enough to build a fair playing environment for good competition between players. All the player can control is the direction of the projectile while launching, and when to boost while flying. The rest is up to the gravitational forces in the space. This limitation makes the game challenging and fair.
Element of surprise. Even though the gravitational forces by the planets stay the same, it can still make the trajectory of the rocket hard to predict, especially when the rocket is at high velocity. It keeps the players from getting bored.

	Here are the control settings:

Commands: [Player Green / Player Red]
Aim counter-clockwise [A Key / Left-Arrow Key]
Aim clockwise [D Key / Right-Arrow Key]
Launch / Boost * [Spacebar / Enter Key]
Rematch [Backspace Key]


*When the rocket lands on a planet / at its initial position, this command will Launch the rocket with a velocity high enough to escape the planet’s gravity. When the rocket is in the air, it will apply a force against the gravitational force that is affecting the rocket



Part 2: Classes Breakdown


IMPORTANT NOTES:
Rockets / Spaceships as described in the introduction are represented by the Ball class in the codebase.
Classes or members of classes that are not used in the game are excluded here.

[Player]
Holds the complete package of each player. There are two players in the game, Green and Red, or player 0 and player 1.

Variables: 
float pr_sign: Holding value of either 0.f or 1.f as a parameter for Player constructor. It is used to differentiate between players to determine the initial location and render colour, red or green.
float pr_ypos: Y coordinate of the initial position.

Objects:
Ball pr_ball
Launcher pr_launcher

Functions:
void addAngle(float angle): Takes a float and adds pr_launcher’s angle variable.
void setBoost(float boost): Takes a float to set as pr_ball’s boost variable.
bool isBallActive(): Returns pr_ball’s isActive state.
void launch(): Activate pr_launcher’s launchBall() that launches pr_ball.
void boosting(): Called when the player is boosting. Activates pr_ball’s boosting().
void update(bool isWon): Condition the player to the initial state when the game is over.
void render(): Renders pr_launcher when the ball landed on a planet or in the initial position.


[Ball]
Represents a spaceship/rocket that can launch and boost and gets points by passing through point dots.

Variables:
float b_xpos: The ball’s x coordinate.
float b_ypos: The ball’s y coordinate.
float b_rad: The ball’s radius.
Utils::Position b_velocity: Containing the ball’s velocity in x and y directions.
bool isActive: False when the ball is stationary, which is either landed on a planet or in its initial position. True when moving
float b_boost: Set to -2.f when boosting, and 1.f when not boosting.

Objects:
CircleShape b_circle: Instanced for rendering.

Functions: 
Utils::Position getPosition(): Returns b_xpos and b_ypos as a Utils::Position.
void setPosition(float x, float y): Takes float values to set to b_xpos and b_ypos.
void setColor(float r, float g, float b): Takes float values to set b_circle’s color.
void makeActive(): Sets isActive to true.
void boosting(std::vector<std::shared_ptr<Effect>>* effects): Adds a boost effect to a dynamic array of pointers to Effect objects. Sets b_boost value to -2.f;
bool isInBound(): Checks whether the ball is within the window view.
void update(): Calls isInBound() and sets the state isActive accordingly.
void render(): Renders b_circle in the ball’s position.


[Launcher]
Launching Ball objects and providing a visual trajectory guide.

Variables:
float initialX: The initial x coordinate.
float initialY: The initial y coordinate.
float l_angle: The angle of the Launcher measured from the y-axis clockwise.
float l_xpos: The current x coordinate.
float l_ypos: The current y coordinate.

Objects:
CircleShape l_circle: Instanced for rendering.

Functions:
void setPosition(float x, float y): Takes float values to set l_xpos and l_ypos.
void launchBall(Ball& ball): Takes a reference to a Ball object, and sets the ball’s velocity with directions using the sine and cos value of l_angle. When the ball is on a planet, the value is multiplied 1.8 times so that the ball can escape the planet’s gravity.
void resetBall(Ball& ball): Sets the ball’s position to the launcher’s position.
void render(float sign): Renders the launcher’s trajectory guide using l_circle. Takes the player’s sign to determine the colour, green or red.


[Grid]
The framework of the point dots.

Variables:
int g_div: Constant value to set the distance between dots.
int g_row: The number of rows in the grid, calculated by dividing the window width with g_div.
int g_col: The number of columns in the grid, calculated by dividing the window height with g_div.
Int g_grid[g_row][g_col]: An array of integers representing a grid of point dots holding the state of each dot. The states are:
-1: default dot.
0: regular dot occupied by player 0.
1: regular dot occupied by player 1.
9: default bonus dot.
10: bonus dot occupied by player 0.
11: bonus dot occupied by player 1.
Utils::Position g_bonusPos[5]: An array of x and y coordinates of each bonus dot.

Objects:
CircleShape g_circle: Instanced for rendering.

Functions:
void dotsInit(): Sets the value of each dot in g_grid to -1.
void bonusInit(): Sets the value of each bonus dot in g_grid to 9. These dots are derived from the x-y coordinates of each bonus dot in g_bonusPos[5].
void update(Player* players): Updates the states of each dot that is passed by the ball, or technically, is closest to the current position of the ball.
void render(): Renders each dot with the colours according to its state: Green when occupied by player 0, Red when player 1, and Blue when never occupied.


[Score]
Handles the scores and the state of the game.

Variables:
int s_0: The score of player 0.
int s_1: The score of player 1.
bool isWon: True when the game is won by one of the players.
std::string s_winner: The winner of the game, “Red” or “Green” for rendering.
float s_0posX, s_0posY, s_1posX, s_1posY: Coordinates of the scores for rendering.

Functions:
void rematch(Grid* grid): Reset the grid and set the value of isWon to false.
bool getStatus(): Returns the value of isWon.
void update(const Grid* grid): Counts the points of each player by iterating through the dots in the grid, and checks if either player has reached 1000 points, which then declares isWon and sets s_winner accordingly.
void render(): Renders the scores as texts, and winner statement when the game is won.


[Planet]
Exerts gravitational force and provides a surface for balls to land.

Variables: 
float p_xpos, p_ypos: The x and y coordinates of the planet.
float p_rad: The radius of the planet.
float p_mass: The mass of the planet which is directly proportional to the radius.
float max_rad: The maximum radius of the planets to normalize the mass.
float p_cR, p_cG, p_cV: The float RGB values.

Objects:
CircleShape p_circle: Instanced for rendering.

Functions:
Utils::Position getPosition(): Returns p_xpos and p_ypos as Utils::Position.
void setColor(float r, float g, float b): Takes float values to set the planet’s RGB values.
void render(): Renders the planet using p_circle.


[Physics]
Handles the physics calculation of gravitational forces.

Functions:
void updatePos(std::vector<Planet> planets, Ball& ball,  Launcher& launcher, float deltaTime): Takes an array of planets, a ball, and a launcher and updates the ball’s position.
Explanation:
According to Newton’s Law of Gravitation, every object in the universe attracts each other with a force that is directly proportional to the product of the masses and inversely proportional to the square of the distance between them. F = (G * m1 * m2)/r^2. G is constant.

This program simplifies this concept and takes into account the mass of each planet and the distance from the ball to affect the ball’s velocity. In each frame, the updatePos function iterates through each planet and does the following:
Calculate the difference vector (D) from the position vector of the planet (P) and the ball (B).
(Math notation)
D = P - B

Then, calculate the scalar distance (d) between the planet and the ball.
(Math notation)
d = Dx2 + Dy2

Then, separate and normalize the difference vectors with the distance, and call them directionX and directionY.
directionX = Dx / d
directionY = Dy / d

Calculate the scalar gravity acceleration g by dividing the planet’s mass by the distance, and then multiplying with directionX and directionY to get acceleration aX and aY.
g = p_mass / d
aX = g * directionX
aY = g * directionY

Add the acceleration multiplied by the deltaTime and boost value to the ball’s velocity.
ball.b_velocity.x += aX * deltaTime * ball.b_boost
ball.b_velocity.y += aY * deltaTime * ball.b_boost

Add the new velocity to the ball’s position.
ball.b_xpos += ball.b_velocity.x * deltaTime
ball.b_ypos += ball.b_velocity.y * deltaTime
If the ball touches the planet, the velocity is set to 0.

Notice that the value of G and the multiplication of the distance by itself is neglected, but it still gives a physically coherent simulation because:

We are not using any real units and we keep the right proportional relations between the values.
The mass is tuned to be in the range that gives a good gravitational force value for the scale of the game space.


[BoostEffect]
Emulates an ignition effect like smoke and fire from vehicle exhaust. Inherits from class Effect.

Variables: 
int maxFrames_ = 20: The number of frames of the effect.
int frames_: The current frame.
float radiusFactor_: The factor that determines the default initial size of the particles.
int numParticles: The number of particles emitted every frame.

Objects:
Effect::particle particles_[numParticles_]: Array of Particle objects.
Effect effect_
CircleShape circle_: Instaned for rendering.

Functions:
void particlesInit(): Initialize Particle objects in particles_.
void addBoost(std::vector<std::shared_ptr<Effect>>& effects, float x, float y, float radius): Adds a boost effect with a specific radius to the passed-on array of Effect pointers as a shared pointer.
void addBoost(std::vector<std::shared_ptr<Effect>>& effects, float x, float y): Adds a boost effect without specifying radius and therefore uses the default radiusFactor_.
void update(float deltaTime): Mark the effect as done when all frames are executed and add a random deviation to the particle position in each frame for a natural look.
void render(): Renders each particle.


[Effect]
Contains necessary building blocks for visual effects.

Variables:
Utils::Position origin_: The origin position of the effect.
bool isDone: Stating whether the effect is finished.

Objects:
An Effect object.

Structs:
Particle: Contains a Utils::Position value, and three floats as r, g, and b color values.

Functions:
void makeDone(): Sets isDone to true.
void update(float deltaTime): To be overridden by child effect classes.
void render(): To be overridden by child effect classes.


[CircleShape]
Renders a circle, empty or filled. Inherits from Shape.

Variables:
float c_radius: Radius of the circle.

Objects:
A Shape object.

Functions:
void setRadius(float radius): Takes a float to set c_radius.
void Draw(): Renders a circle using App::DrawLine. It draws 24 straight lines that revolve around the center of the Shape position.
void DrawFilled(): Renders a filled circle using App::DrawLine. It draws 360 lines that are rotated one degree apart from each other making it seem like a solid color-filled circle when drawn in small radii.


[Shape]
Contains necessary building blocks for a shape.

Variables:
float s_xpos, s_ypos: The x and y coordinates of the shape.
float s_cR, s_cG, s_cB: The r, g, and b colour values of the shape.

Functions:
void SetPosition(float x, float y): Takes float values to set the position of the shape.
void SetColor(float r, float g, float b): Takes float values to set the colour of the shape.


[Utils]
Contains miscellaneous functions and variables to be used by other classes.

Variables:
float fPI: Value of pi as a float.
float app_width: Holds the width of the window.
float app_height: Holds the height of the window.

Structs:
Position: Contains float x and y coordinates.

Functions:
Position getDifference(Position p1, Position p2): Subtracting two position vectors.
float getLength(Position vec): Calculating the scalar length of a position vector Px2 + Py2


Part 3: Game Design Pattern


Because this game is relatively simple, it is not necessary to incorporate sophisticated design patterns like Flyweight, Bytecode, or Observer patterns. However, there are a couple of simple patterns that are incorporated into this game.

State Pattern
The game incorporates states for communicating between objects of different classes. For example, the Score class has a bool state called isWon, which is listened to by other classes’ update functions. Other than that, the Ball class also has isActive state which determines the action of Launcher objects.

Component Pattern
The games use component classes as a building block for other classes. For example, the Player class contains Ball and Launcher objects and uses their update and render functions.

	Even though not many design patterns are incorporated, the design of this game still takes into account memory and performance efficiency. For example, instead of creating new objects in each frame for rendering, objects that need to be rendered have a Shape instance as a part of the class to be reused for rendering. This way, the program does not need to construct and deconstruct hundreds of objects in every frame.


The game also uses modern C++ features to prevent memory leaks from creating regular pointers. It uses smart pointers to handle visual effects. The visual effects in the game are contained in a std::vector array consisting of shared pointers to effect objects. This way, each pointer will be allocated and deallocated automatically.


–END OF DOCUMENTATION–

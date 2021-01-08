#include "Animator.h"
#include <sstream>



Animator::Animator()
{
    backgroundImageTexture.loadFromFile("images/AnimDebugger/GridBackground.png");
    backgroundImage.setTexture(backgroundImageTexture);
    frameClockTime = sf::seconds(5);
    


    //buttons and textures
    
    pauseButtonTextureOn.loadFromFile("images/AnimDebugger/Pause.png");
    pauseButtonTextureOff.loadFromFile("images/AnimDebugger/Unpause.png");
    pauseButton.setTexture(pauseButtonTextureOn);
    pauseButton.setPosition(1500, 200);

    moveAllFramesTexture.loadFromFile("images/AnimDebugger/battleMap.png");
    moveAllFrames.setTexture(moveAllFramesTexture);
    moveAllFrames.setPosition(1500, 300);
    
    
    moveSingleFrameTexture.loadFromFile("images/AnimDebugger/battleMap.png");
    moveSingleFrame.setTexture(moveSingleFrameTexture);
    moveSingleFrame.setPosition(1500, 400);

    TurnOnGhostTextureOn.loadFromFile("images/AnimDebugger/ShadowAlign.png");
    TurnOnGhostTextureOff.loadFromFile("images/AnimDebugger/ShadowAlign.png");
    TurnOnGhost.setTexture(TurnOnGhostTextureOn);
    TurnOnGhost.setPosition(1500, 300);


    nextAnimationTexture.loadFromFile("images/AnimDebugger/nextAnimation.png");
    nextAnimation.setTexture(nextAnimationTexture);
    nextAnimation.setPosition(1500, 400);


    prevAnimationTexture.loadFromFile("images/AnimDebugger/prevAnimation.png");
    prevAnimation.setTexture(prevAnimationTexture);
    prevAnimation.setPosition(1500, 500);



    nextFrameTexture.loadFromFile("images/AnimDebugger/nextFrame.png");
    nextFrame.setTexture(nextFrameTexture);
    nextFrame.setPosition(1500, 600);

    prevFrameTexture.loadFromFile("images/AnimDebugger/prevFrame.png");
    prevFrame.setTexture(prevFrameTexture);
    prevFrame.setPosition(1500, 700);
    
    upTexture.loadFromFile("images/AnimDebugger/Up.png");
    upButton.setTexture(upTexture);
    upButton.setPosition(1100, 500);

    downTexture.loadFromFile("images/AnimDebugger/Down.png");
    downButton.setTexture(downTexture);
    downButton.setPosition(1100, 600);

    leftTexture.loadFromFile("images/AnimDebugger/Left.png");
    leftButton.setTexture(leftTexture);
    leftButton.setPosition(1000, 600);

    rightTexture.loadFromFile("images/AnimDebugger/Right.png");
    rightButton.setTexture(rightTexture);
    rightButton.setPosition(1200, 600);

    SaveTexture.loadFromFile("images/AnimDebugger/Save.png");
    Save.setTexture(SaveTexture);
    Save.setPosition(1500, 800);
}

//handles clickable buttons on the screen such as pause, next frame, ect
int Animator::readInputForButtons(sf::RenderWindow& window, sf::Event event)
{

    //creates a vector that holds the mouses position
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    //gets the bounds of the sprite
    sf::FloatRect saveBounds = Save.getGlobalBounds();
    sf::FloatRect pauseBounds = pauseButton.getGlobalBounds();
    sf::FloatRect ghostBounds = TurnOnGhost.getGlobalBounds();
    sf::FloatRect nextFrameBounds = nextFrame.getGlobalBounds();
    sf::FloatRect prevFrameBounds = prevFrame.getGlobalBounds();
    sf::FloatRect nextAnimationBounds = nextAnimation.getGlobalBounds();
    sf::FloatRect prevAnimationBounds = prevAnimation.getGlobalBounds();
    sf::FloatRect upButtonBounds = upButton.getGlobalBounds();
    sf::FloatRect downButtonBounds = downButton.getGlobalBounds();
    sf::FloatRect leftButtonBounds = leftButton.getGlobalBounds();
    sf::FloatRect rightButtonBounds = rightButton.getGlobalBounds();


    //fills the event
    while (window.pollEvent(event))
    {
       /* if (frameClock.getElapsedTime().asMilliseconds() > 30)
        {*/
            //checks to see if the event filled is the mouse being pressed
            if (event.type == sf::Event::MouseButtonPressed)
            {
                frameClock.restart();
                //save
                if (saveBounds.contains(mousePos))
                {                   
                    return 1;
                }
                //pause
                else if (pauseBounds.contains(mousePos))
                {           
                    //set texture to an unpause button
                    pauseButton.setTexture(pauseButtonTextureOff);
                    return 2;
                }
                //show ghost
                else if (ghostBounds.contains(mousePos))
                {
                    //set texture to an unpause button
                    TurnOnGhost.setTexture(TurnOnGhostTextureOff);
                    return 3;
                }
                //next frame button
                else if (nextFrameBounds.contains(mousePos))
                {
                    return 4;
                }
                //prev frame button
                else if (prevFrameBounds.contains(mousePos))
                {
                    return 5;
                }
                //Next Animation
                else if (nextAnimationBounds.contains(mousePos))
                {
                    return 6;
                }
                //previous animation
                else if (prevAnimationBounds.contains(mousePos))
                {
                    return 7;
                }
                //up button
                else if (upButtonBounds.contains(mousePos))
                {
                    return 8;
                }
                //down button
                else if (downButtonBounds.contains(mousePos))
                {
                    return 9;
                }
                //left button
                else if (leftButtonBounds.contains(mousePos))
                {
                    return 10;
                }
                //rightButton 
                else if (rightButtonBounds.contains(mousePos))
                {
                    return 11;
                }
            }
        //}
    }
    return 0;
}

vector<MoveGroup> Animator::groupMultiSheetGroupsTogether()
{
    MoveGroup moveGroup;
    std::vector<MoveGroup> listOfMovesByGroup;


    string currentMoveName = listOfAllMoves[0].nameOfFile;

    //exampe NinjaStar1Data1.json = NinjaStar
    string nameTemplate = currentMoveName.substr(0, currentMoveName.length() - 11);

    for (int i = 0; i <= listOfAllMoves.size(); i++)
    {
         currentMoveName = listOfAllMoves[i].nameOfFile;

        //exampe NinjaStar1Data1.json = NinjaStar
        string CurrentNameTemplate = currentMoveName.substr(0, currentMoveName.length() - 11);
        
        if(nameTemplate == CurrentNameTemplate) moveGroup.moveGroup.push_back(listOfAllMoves[i]);
        else
        {
            nameTemplate = currentMoveName.substr(0, currentMoveName.length() - 11);

            listOfMovesByGroup.push_back(moveGroup);
            moveGroup.moveGroup.clear();
            moveGroup.moveGroup.push_back(listOfAllMoves[i]);
            //have a container of movesByGroup called ListOfGroups and push the previous group in the container and start on a new one until search through for loop is done
        }
    }
    return listOfMovesByGroup;
}

int Animator::getTotalFrameCount(vector<oneMove> group)
{
    int total = 0;
    for (int i = 0; i < group.size(); i++)
    {
        total += group[i].move.size();
    }
    return total;
}

void Animator::animateCurrentMove(sf::RenderWindow& renderWindow, sf::Event event)
{
    static int xAxis = 50;
    static int yAxis = 50;
    int currentFrame = 0;

    double player1PassedTime = (double)(frameClock.getElapsedTime().asSeconds());

    bool currentMoveHasntChanged = true;
    std::ostringstream stringStream;

    int eventTrigger = 0;
    static bool singleFrame = false;
    static bool drawPrevFrame = false;
    sf::Text currentFrameDisplay;
    sf::Text currentPixelDisplay;

    vector<MoveGroup> listOfMovesByGroup = groupMultiSheetGroupsTogether();
    vector<sf::Texture> listOfTextures = loadAllTextures(listOfMovesByGroup);

    sf::Font font;
    font.loadFromFile("Text/times.ttf");

    //ghost coords
    sf::Text previousPixelDisplay;
    currentFrameDisplay.setColor(sf::Color::Black);
    currentFrameDisplay.setFont(font);
    currentFrameDisplay.setPosition(700, 500);
    currentFrameDisplay.setCharacterSize(60);


    currentPixelDisplay.setColor(sf::Color::Black);
    currentPixelDisplay.setFont(font);
    currentPixelDisplay.setPosition(700, 600);
    currentPixelDisplay.setCharacterSize(60);
    

    previousPixelDisplay.setColor(sf::Color::Black);
    previousPixelDisplay.setFont(font);
    previousPixelDisplay.setPosition(700, 700);
    previousPixelDisplay.setCharacterSize(60);

    //list of all groups
    for (int i = 0; i < listOfMovesByGroup.size(); i++)
    {
        while(currentMoveHasntChanged)
        { 
        //one group of moves
            for (int j = 0; j < listOfMovesByGroup[i].moveGroup.size(); j++)
            {
                //json to png of a move in the group
                string jsonToPng = listOfMovesByGroup[i].moveGroup[j].nameOfFile;
                jsonToPng = jsonToPng.substr(0, jsonToPng.length() - 10);
                jsonToPng += ".png";
                jsonToPng = "Animations/" + jsonToPng;


                //loads texture 
                //player1SpriteTexture.loadFromFile(jsonToPng);
                //loads texture to sprite
                player1Sprite.setTexture(listOfTextures[j]);
                currentMoveHasntChanged = true;

                //loops through one move in the group
                for (int k = 0; k < listOfMovesByGroup[i].moveGroup[j].move.size(); k++)
                {

                    //handles input check for buttons
                    eventTrigger = readInputForButtons(renderWindow, event);


                    //moves animation around as a whole
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) xAxis -= 5;
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) xAxis += 5;
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) yAxis -= 5;
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) yAxis += 5;
                    else if (eventTrigger == 2)
                    {
                        eventTrigger = 0;
                        singleFrame = true;
                    }
                    //when the nextAnimation button is pressed
                    else if (eventTrigger == 6)
                    {
                        currentMoveHasntChanged = false;
                    }
                    //when the prevAnimation button is pressed(bugged)
                    else if (eventTrigger == 7)
                    {
                        currentMoveHasntChanged = false;
                        i--;
                        i--;
                    }
                    



                    //pause to allow edit of a single frames position in the overall animation
                    while (singleFrame)
                    {
                        currentFrame = k + 1;
                        //for loop to get current frames number in the group
                        for (int c = j; c >= 1; c--)
                        {
                            if (c >= 1) currentFrame += listOfMovesByGroup[i].moveGroup[c-1].move.size();                          
                        }

                        stringStream << "Frame: " << currentFrame << " / " << getTotalFrameCount(listOfMovesByGroup[i].moveGroup);
                        //sets the text for the current frame count
                        currentFrameDisplay.setString(stringStream.str());
                        stringStream.str("");
                        currentFrame = 0;


                        stringStream << "x: " << listOfMovesByGroup[i].moveGroup[j].move[k].moveLeft * -1 << "       " << "Y:" << listOfMovesByGroup[i].moveGroup[j].move[k].moveUp;
                        //sets the text for the current pixel count
                        currentPixelDisplay.setString(stringStream.str());
                        stringStream.str("");

                        eventTrigger = readInputForButtons(renderWindow, event);
                        renderWindow.draw(backgroundImage);
                        renderWindow.draw(pauseButton);
                        renderWindow.draw(TurnOnGhost);

                        renderWindow.draw(nextFrame);
                        renderWindow.draw(prevFrame);

                        renderWindow.draw(upButton);
                        renderWindow.draw(downButton);
                        renderWindow.draw(leftButton);
                        renderWindow.draw(rightButton);

                        renderWindow.draw(currentFrameDisplay);
                        renderWindow.draw(currentPixelDisplay);

                        renderWindow.pollEvent(event);
                        //moves a single frame around
                        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) listOfMovesByGroup[i].moveGroup[j].move[k].moveLeft += 1;
                        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))listOfMovesByGroup[i].moveGroup[j].move[k].moveLeft -= 1;
                        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) listOfMovesByGroup[i].moveGroup[j].move[k].moveUp += 1;
                        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) listOfMovesByGroup[i].moveGroup[j].move[k].moveUp -= 1;
                        //handles changing single frames up or down
                        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::PageUp))
                        {
                            if (k < listOfMovesByGroup[i].moveGroup[j].move.size() - 1) k++;
                            else if (k == listOfMovesByGroup[i].moveGroup[j].move.size() - 1)
                            {
                                if (j < listOfMovesByGroup[i].moveGroup.size() - 1)
                                {
                                    j++;
                                    k = 0;
                                    player1Sprite.setTexture(listOfTextures[j]);
                                }
                            }
                        }
                        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::PageDown))
                        {
                            if (k > 0) k--;
                            else //if (k == listOfMovesByGroup[i].moveGroup[j].move.size() - 1)
                            {
                                if (j > 0)
                                {
                                    j--;
                                    k = listOfMovesByGroup[i].moveGroup[j].move.size() - 1;
                                    player1Sprite.setTexture(listOfTextures[j]);
                                }
                            }
                        }
                        else if (eventTrigger == 2)
                        {
                            eventTrigger = 0;
                            singleFrame = false;
                        }
                        //next frame button
                        else if (eventTrigger == 4)
                        {
                            if (k < listOfMovesByGroup[i].moveGroup[j].move.size() - 1) k++;
                            else if (k == listOfMovesByGroup[i].moveGroup[j].move.size() - 1)
                            {
                                if(j < listOfMovesByGroup[i].moveGroup.size() - 1)
                                {
                                    j++;
                                    k = 0;
                                    player1Sprite.setTexture(listOfTextures[j]);
                                }
                            }
                        }
                        //previous frame button
                        else if (eventTrigger == 5)
                        {
                            if (k > 0) k--;
                            else //if (k == listOfMovesByGroup[i].moveGroup[j].move.size() - 1)
                            {
                                if (j > 0)
                                {
                                    j--;
                                    k = listOfMovesByGroup[i].moveGroup[j].move.size() - 1;
                                    player1Sprite.setTexture(listOfTextures[j]);
                                }
                            }
                        }
                        //when up button is clicked
                        else if (eventTrigger == 8)
                        {
                            listOfMovesByGroup[i].moveGroup[j].move[k].moveUp += 1;
                        }
                        //when down button is clicked
                        else if (eventTrigger == 9)
                        {
                            listOfMovesByGroup[i].moveGroup[j].move[k].moveUp -= 1;
                        }
                        //when left button is clicked
                        else if (eventTrigger == 10)
                        {
                            listOfMovesByGroup[i].moveGroup[j].move[k].moveLeft += 1;
                        }
                        //when right button is clicked
                        else if (eventTrigger == 11)
                        {
                            listOfMovesByGroup[i].moveGroup[j].move[k].moveLeft -= 1;
                        }


                        //makes sure you cant draw alpha of an image at index 0
                        if (drawPrevFrame)
                        {
                            if (k > 0)
                            {
                                player1Sprite.setTextureRect(sf::IntRect(listOfMovesByGroup[i].moveGroup[j].move[k-1].x, listOfMovesByGroup[i].moveGroup[j].move[k-1].y, 
                                    listOfMovesByGroup[i].moveGroup[j].move[k-1].width, listOfMovesByGroup[i].moveGroup[j].move[k-1].height));

                                player1Sprite.setPosition(xAxis - listOfMovesByGroup[i].moveGroup[j].move[k-1].moveLeft, yAxis - listOfMovesByGroup[i].moveGroup[j].move[k-1].moveUp);
                                player1Sprite.setColor(sf::Color(255, 255, 255, 128));

                                stringStream << "Previous Frame:  x: " << listOfMovesByGroup[i].moveGroup[j].move[k-1].moveLeft * -1 << "       " << "Y:" << listOfMovesByGroup[i].moveGroup[j].move[k-1].moveUp;
                                //sets the text for the current pixel count
                                previousPixelDisplay.setString(stringStream.str());
                                stringStream.str("");

                                renderWindow.draw(player1Sprite);
                                renderWindow.draw(previousPixelDisplay);
                            }
                            //draws the last frame from the previous move as a ghost
                            else if (j > 0)
                            {
                                int frame = listOfMovesByGroup[i].moveGroup[j - 1].move.size() - 1;
                                                                                                                     //23                                                  //23
                                player1Sprite.setTextureRect(sf::IntRect(listOfMovesByGroup[i].moveGroup[j - 1].move[frame].x, listOfMovesByGroup[i].moveGroup[j - 1].move[frame].y,
                                    listOfMovesByGroup[i].moveGroup[j - 1].move[frame].width, listOfMovesByGroup[i].moveGroup[j].move[frame].height));

                                player1Sprite.setTexture(listOfTextures[j - 1]);
                                player1Sprite.setPosition(xAxis - listOfMovesByGroup[i].moveGroup[j - 1].move[frame].moveLeft, yAxis - listOfMovesByGroup[i].moveGroup[j - 1].move[frame].moveUp);
                                player1Sprite.setColor(sf::Color(255, 255, 255, 128));

                                stringStream << "Previous Frame:  x: " << listOfMovesByGroup[i].moveGroup[j - 1].move[frame].moveLeft * -1 << "       " << "Y:" << listOfMovesByGroup[i].moveGroup[j - 1].move[frame].moveUp;
                                //sets the text for the current pixel count
                                previousPixelDisplay.setString(stringStream.str());
                                stringStream.str("");

                                renderWindow.draw(player1Sprite);
                                renderWindow.draw(previousPixelDisplay);
                                player1Sprite.setTexture(listOfTextures[j]);
                            }
                        }


                        //turns on Opacity mode for the previous frame
                        if (eventTrigger == 3)
                        {
                            eventTrigger = 0;
                            drawPrevFrame = true;
                        }
                        //turns off shadow frame
                        else if (event.key.code == sf::Keyboard::S)
                        {
                            drawPrevFrame = false;
                        }

                        player1Sprite.setTextureRect(sf::IntRect(listOfMovesByGroup[i].moveGroup[j].move[k].x, listOfMovesByGroup[i].moveGroup[j].move[k].y, 
                            listOfMovesByGroup[i].moveGroup[j].move[k].width, listOfMovesByGroup[i].moveGroup[j].move[k].height));

                        player1Sprite.setPosition(xAxis - listOfMovesByGroup[i].moveGroup[j].move[k].moveLeft, yAxis - listOfMovesByGroup[i].moveGroup[j].move[k].moveUp);
                        player1Sprite.setColor(sf::Color(255, 255, 255, 255));
                        renderWindow.draw(player1Sprite);

                        renderWindow.display();
                        renderWindow.clear();
                    }


                    //listOfAllMoves[i].move.
                    player1Sprite.setTextureRect(sf::IntRect(listOfMovesByGroup[i].moveGroup[j].move[k].x, listOfMovesByGroup[i].moveGroup[j].move[k].y,
                        listOfMovesByGroup[i].moveGroup[j].move[k].width, listOfMovesByGroup[i].moveGroup[j].move[k].height));
                    player1Sprite.setPosition(xAxis - listOfMovesByGroup[i].moveGroup[j].move[k].moveLeft, yAxis - listOfMovesByGroup[i].moveGroup[j].move[k].moveUp);

                    renderWindow.draw(backgroundImage);
                    renderWindow.draw(player1Sprite);
                    //button
                    renderWindow.draw(nextAnimation);

                    //only draws prev animation button if you are not displaying the first move in a list
                    if (i > 0)
                    {
                        renderWindow.draw(prevAnimation);
                    }

                    renderWindow.draw(Save);
                    renderWindow.draw(TurnOnGhost);

                    //renderWindow.draw(moveAllFrames);
                    //renderWindow.draw(moveSingleFrame);
                    renderWindow.draw(pauseButton);

                    renderWindow.display();
                    renderWindow.clear();

                    frameClock.restart();

                }
            }
        }
    }
}

void Animator::drawBackground()
{

}

//references the directory for where to find the json files and adds every json file into a list
void Animator::list_dir()
{
    string temp = "";
    struct dirent* entry;
    DIR* dir = opendir("Animations/");

    if (dir == NULL) return;
    while ((entry = readdir(dir)) != NULL) 
    {
        temp = entry->d_name;
        temp.length();
        if (temp.length() > 5)
        {
            if (temp.substr(temp.length() - 4, temp.length()) == ".png") nameOfImageFiles.push_back(temp);
            else if (temp.substr(temp.length() - 5, temp.length()) == ".json") nameOfJSONFiles.push_back(temp);
        }
    }
    closedir(dir);
}

//loads each JSON file into a move, then stores every move in a container called listOfEveryMove
void Animator::loadAllFiles()
{
    //sets up json 
    using json = nlohmann::json;


    for (int i = 0; i < nameOfJSONFiles.size(); i++)
    {
        string strForStream = "Animations/" + nameOfJSONFiles[i];
        std::ifstream inputStream(strForStream);
        json jsonFile;
        json frameKey;
        json onlyCoord;
        inputStream >> jsonFile;


        for (auto iterator = jsonFile.begin(); iterator != jsonFile.end(); iterator++)
        {
            if (iterator.key() == "frames")
            {
                frameKey = iterator.value();
            }
        }

        oneMove tempMove;

        //runs through
        for (int i = 0; i < frameKey.size(); i++)
        {
            for (auto it = frameKey[i].begin(); it != frameKey[i].end(); it++)
            {
                std::cout << "key: " << it.key() << " : " << it.value() << endl << endl;
                if (it.key() == "frame")
                {
                    onlyCoord = it.value();
                    cout << onlyCoord;
                    frame coord;
                    for (auto textFile = onlyCoord.begin(); textFile != onlyCoord.end(); textFile++)
                    {
                        if (textFile.key() == "h")coord.height = textFile.value();
                        else if (textFile.key() == "w")coord.width = textFile.value();
                        else if (textFile.key() == "x")coord.x = textFile.value();
                        else if (textFile.key() == "y")coord.y = textFile.value();
                        else if (textFile.key() == "moveLeft")coord.moveLeft = textFile.value();
                        else if (textFile.key() == "moveUp")coord.moveUp = textFile.value();
                    }
                    tempMove.move.push_back(coord);                            
                }
            }
        }
        tempMove.nameOfFile = nameOfJSONFiles[i];
        listOfAllMoves.push_back(tempMove);
    }


}


void Animator::fillAllMoves()
{
    //fill one frame

    //fill one move

    //loop that fills all moves
    oneMove * listOfAllMoves = new oneMove[60];
}

vector<sf::Texture> Animator::loadAllTextures(vector<MoveGroup> moveGroups)
{
    vector<sf::Texture> listOfTextures;
    for (size_t i = 0; i < moveGroups.size(); i++)
    {
        for (size_t j = 0; j <  moveGroups[i].moveGroup.size(); j++)
        {
            

            //json to png
            string jsonToPng = moveGroups[i].moveGroup[j].nameOfFile;
            jsonToPng = jsonToPng.substr(0, jsonToPng.length() - 10);
            jsonToPng += ".png";
            jsonToPng = "Animations/" + jsonToPng;
            
            
            //loads texture 
            player1SpriteTexture.loadFromFile(jsonToPng);
            listOfTextures.push_back(player1SpriteTexture);
        }
    }
    return listOfTextures;
}

void Animator::SaveMove(oneMove currentMove)
{
    /*string temp = "";
    struct dirent* entry;
    DIR* dir = opendir("Animations/");

    if (dir == NULL) return;
    while ((entry = readdir(dir)) != NULL)
    {
        temp = entry->d_name;
        temp.length();
        if (temp.length() > 5)
        {
            if (temp.substr(temp.length() - 4, temp.length()) == ".png") nameOfImageFiles.push_back(temp);
            else if (temp.substr(temp.length() - 5, temp.length()) == ".json") nameOfJSONFiles.push_back(temp);
        }
    }
    closedir(dir);*/

}
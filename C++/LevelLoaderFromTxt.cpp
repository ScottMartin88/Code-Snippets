
//Reads the data from a text document.

std::vector<std::string> loadLevel(std::string Level){
	std::ifstream file;
	file.open(Level);
	std::vector<std::string> _loadLevel;
	
	std::string line;

	while (getline(file, line)){
		_loadLevel.push_back(line);
	}
	file.close();
	return _loadLevel;
}

//Reads through the data from the text document	and will place the tile that is writen in the document
//in the right place to draw a level designed in notepad. this made creating levels quicker and easier than
//truing to place everything in the game manually and allowed for each tile to work howit should.
//for example walk on grass and ignore the sky.

void levelSetup(gameData* newGame, std::vector<std::string> Level) 
{
	for (int j = 0; j < (int)Level.size(); j++)
	{

		for (int i = 0; i < (int)Level[j].length(); i++)
		{
			if (Level[j][i] == 'U'){
				newGame->newSky[newGame->skyCount].wallY = (float)-j / 8.0f;
				newGame->newSky[newGame->skyCount].wallX = (float)-i / 8.0f;
				newGame->skyCount += 1;
			}
			else if (Level[j][i] == 'G'){
				newGame->newWall[newGame->grassCount].wallY = (float)-j / 8.0f;
				newGame->newWall[newGame->grassCount].wallX = (float)-i / 8.0f;
				newGame->grassCount += 1;
			}
			else if (Level[j][i] == 'F'){
				newGame->newDirtGrass[newGame->dirtGrassCount].wallY = (float)-j / 8.0f;
				newGame->newDirtGrass[newGame->dirtGrassCount].wallX = (float)-i / 8.0f;
				newGame->dirtGrassCount += 1;
			}
			else if (Level[j][i] == 'B'){
				newGame->newDirt[newGame->dirtCount].wallY = (float)-j / 8.0f;
				newGame->newDirt[newGame->dirtCount].wallX = (float)-i / 8.0f;
				newGame->dirtCount += 1;
			}
			else if (Level[j][i] == 'C'){
				newGame->newCloud[newGame->cloudCount].wallY = (float)-j / 8.0f;
				newGame->newCloud[newGame->cloudCount].wallX = (float)-i / 8.0f;
				newGame->cloudCount += 1;
			}
			else if (Level[j][i] == 'P'){
				newGame->newFlower[newGame->flowerCount].wallY = (float)-j / 8.0f;
				newGame->newFlower[newGame->flowerCount].wallX = (float)-i / 8.0f;
				newGame->flowerCount += 1;
			}
			else if (Level[j][i] == 'L'){
				newGame->newFlowerStem[newGame->flowerStemCount].wallY = (float)-j / 8.0f;
				newGame->newFlowerStem[newGame->flowerStemCount].wallX = (float)-i / 8.0f;
				newGame->flowerStemCount += 1;
			}
			else if (Level[j][i] == 'A'){
				newGame->newHillLeft[newGame->hillLeftCount].wallY = (float)-j / 8.0f;
				newGame->newHillLeft[newGame->hillLeftCount].wallX = (float)-i / 8.0f;
				newGame->hillLeftCount += 1;
			}
			else if (Level[j][i] == 'S'){
				newGame->newHillMiddle[newGame->hillMiddleCount].wallY = (float)-j / 8.0f;
				newGame->newHillMiddle[newGame->hillMiddleCount].wallX = (float)-i / 8.0f;
				newGame->hillMiddleCount += 1;
			}
			else if (Level[j][i] == 'D'){
				newGame->newHillRight[newGame->hillRightCount].wallY = (float)-j / 8.0f;
				newGame->newHillRight[newGame->hillRightCount].wallX = (float)-i / 8.0f;
				newGame->hillRightCount += 1;
			}
			else if (Level[j][i] == 'Q'){
				newGame->newMountLeft[newGame->MountLeftCount].wallY = (float)-j / 8.0f;
				newGame->newMountLeft[newGame->MountLeftCount].wallX = (float)-i / 8.0f;
				newGame->MountLeftCount += 1;
			}
			else if (Level[j][i] == 'W'){
				newGame->newMountMiddle[newGame->MountMiddleCount].wallY = (float)-j / 8.0f;
				newGame->newMountMiddle[newGame->MountMiddleCount].wallX = (float)-i / 8.0f;
				newGame->MountMiddleCount += 1;
			}
			else if (Level[j][i] == 'E'){
				newGame->newMountRight[newGame->MountRightCount].wallY = (float)-j / 8.0f;
				newGame->newMountRight[newGame->MountRightCount].wallX = (float)-i / 8.0f;
				newGame->MountRightCount += 1;
			}


			else {
				newGame->newError[newGame->errorCount].wallY = (float)-j / 8.0f;
				newGame->newError[newGame->errorCount].wallX = (float)-i / 8.0f;
				newGame->errorCount += 1;
			}
		}
	}
}
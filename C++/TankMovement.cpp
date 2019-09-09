	for (int j = 0; j < PLAYER_SIZE; j++){
			//This updates the positions of the tanks and the bullets.
			float oldX = newGame->tankArr[j].xPosition;
			float oldY = newGame->tankArr[j].yPosition;
			float bulletOldX = newGame->tankArr[j].firedBullet->getXPosition();
			float bulletOldY = newGame->tankArr[j].firedBullet->getYPosition();

			newGame->tankArr[j].xPosition = oldX + (newGame->tankArr[j].speed * (cos(newGame->tankArr[j].dirRadions)));
			newGame->tankArr[j].yPosition = oldY + (newGame->tankArr[j].speed * (sin(newGame->tankArr[j].dirRadions)));

			
			newGame->tankArr[j].firedBullet->moveXPosition(bulletOldX); 
			newGame->tankArr[j].firedBullet->moveYPosition(bulletOldY);


			//Here is the update function on whether a powerup is active and when to turn it off.
			if (newGame->tankArr[j].speedPowerUpActive == true){
				newGame->tankArr[j].powerUpCounter += 0.00001 * newGame->scaleFactor;
				if (newGame->tankArr[j].powerUpCounter >= 500)
				{
					newGame->tankArr[j].speedPowerUpActive = false;
					newGame->tankArr[j].maxSpeed = newGame->tankArr[j].maxSpeed / 2;
					newGame->tankArr[j].acceleration = newGame->tankArr[j].acceleration / 2;
					newGame->tankArr[j].powerUpCounter = 0;
				}
			}
			else if (newGame->tankArr[j].godModePowerUpActive == true){
				newGame->tankArr[j].powerUpCounter += 0.00001 * newGame->scaleFactor;
				if (newGame->tankArr[j].powerUpCounter >= 500)
				{
					newGame->tankArr[j].godModePowerUpActive = false;
					newGame->tankArr[j].powerUpCounter = 0;
				}
			}
			//@@@@@@@@@@@@@@@@@@@@@
			//@@@ Tank Map wrap @@@
			//@@@@@@@@@@@@@@@@@@@@@
			if (newGame->tankArr[j].xPosition > 2.8f){
				newGame->tankArr[j].xPosition = -3.0f;
			}
			else if (newGame->tankArr[j].xPosition < -3.0f){
				newGame->tankArr[j].xPosition = 2.8f;
			}
			else if (newGame->tankArr[j].yPosition > 2.0f){
				newGame->tankArr[j].yPosition = -2.2f;
			}
			else if (newGame->tankArr[j].yPosition < -2.2f){
				newGame->tankArr[j].yPosition = 2.0f;
			}

			//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			//@@@ Tank forward key is pressed @@@
			//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			if (newGame->tankArr[j].accelerating == true){
				if ((newGame->tankArr[j].speed) < (newGame->tankArr[j].maxSpeed)){
					(newGame->tankArr[j].speed) += (newGame->tankArr[j].acceleration * newGame->scaleFactor);
				}
				else {
					newGame->tankArr[j].speed = newGame->tankArr[j].maxSpeed;
				}
			}
			//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			//@@@ deceleration to a stop @@@
			//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			else if ((newGame->tankArr[j].accelerating == false) && (newGame->tankArr[j].deccelerating == false) && (newGame->tankArr[j].speed > 0.0f)){
				newGame->tankArr[j].speed -= (newGame->tankArr[j].acceleration * newGame->scaleFactor);
				if (newGame->tankArr[j].speed < newGame->tankArr[j].acceleration * newGame->scaleFactor){
					newGame->tankArr[j].speed = 0.0f;
				}
			}
			
			//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			//@@@ Tank backwards key is pressed @@@
			//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			if (newGame->tankArr[j].deccelerating == true){
				if ((newGame->tankArr[j].speed) > (newGame->tankArr[j].reverseSpeed)){
					newGame->tankArr[j].speed -= (newGame->tankArr[j].acceleration * newGame->scaleFactor);
				}
				else {
					newGame->tankArr[j].speed = (newGame->tankArr[j].reverseSpeed);
				}
			}
			//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			//@@@ deceleration to a stop @@@
			//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			else if ((newGame->tankArr[j].accelerating == false) && (newGame->tankArr[j].deccelerating == false) && (newGame->tankArr[j].speed < 0.0f)){
				newGame->tankArr[j].speed += (newGame->tankArr[j].acceleration * newGame->scaleFactor);
				if (newGame->tankArr[j].speed > -newGame->tankArr[j].acceleration * newGame->scaleFactor){
					newGame->tankArr[j].speed = 0.0f;
				}
			}
			//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			//@@@ Left turn Key is pressed @@@
			//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			if (newGame->tankArr[j].turningLeft == true){
				newGame->tankArr[j].direction += (0.00004 * newGame->scaleFactor);
				if (newGame->tankArr[j].direction >= 360){
					newGame->tankArr[j].direction = 0;
				}
				newGame->tankArr[j].dirRadions = newGame->tankArr[j].direction * newGame->tankArr[j].radions;
			}
			//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			//@@@ right turn Key is pressed @@@
			//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			if (newGame->tankArr[j].turningRight == true){
				newGame->tankArr[j].direction -= (0.00004 * newGame->scaleFactor);
				if (newGame->tankArr[j].direction <= -360){
					newGame->tankArr[j].direction = 0;
				}
				newGame->tankArr[j].dirRadions = newGame->tankArr[j].direction * newGame->tankArr[j].radions;
			}
			//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			//@@@ Turret left turn Key is pressed @@@
			//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			if (newGame->tankArr[j].turretTurningLeft == true){
				newGame->tankArr[j].turretDirection += (0.00008 * newGame->scaleFactor);
				if (newGame->tankArr[j].turretDirection >= 360){
					newGame->tankArr[j].turretDirection = 0;
				}
				newGame->tankArr[j].turretRadions = newGame->tankArr[j].turretDirection * newGame->tankArr[j].radions;
			}
			//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			//@@@ Turret right turn Key is pressed @@@
			//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			if (newGame->tankArr[j].turretTurningRight == true){
				newGame->tankArr[j].turretDirection -= (0.00008 * newGame->scaleFactor);
				if (newGame->tankArr[j].turretDirection <= -360){
					newGame->tankArr[j].turretDirection = 0;
				}
				newGame->tankArr[j].turretRadions = newGame->tankArr[j].turretDirection * newGame->tankArr[j].radions;
			}
			
			//@@@@@@@@@@@@@@@@@@@@@@@@@@@
			//@@@ Fire Key is pressed @@@
			//@@@@@@@@@@@@@@@@@@@@@@@@@@@
			if (newGame->tankArr[j].firing == true){
				newGame->tankArr[j].firedBullet->setXPosition(newGame->tankArr[j].xPosition);
				newGame->tankArr[j].firedBullet->setYPosition(newGame->tankArr[j].yPosition);
				newGame->tankArr[j].firedBullet->setDirRadions(newGame->tankArr[j].turretRadions, newGame->tankArr[j].dirRadions);
				newGame->tankArr[j].firedBullet->setDirection(newGame->tankArr[j].turretDirection, newGame->tankArr[j].direction);
				newGame->tankArr[j].firedBullet->setActive(true);
				newGame->tankArr[j].firing = false;
			}
			bool active = newGame->tankArr[j].firedBullet->getActive();
			if (active = true){
				newGame->tankArr[j].firedBullet->setSpeed(newGame->scaleFactor);
			}
			//Collision detection for powerups
			bool playerPowerUpCollide = detectCollision(newGame->tankArr[j].xPosition, newGame->tankArr[j].yPosition, newGame->gamePowerUp->getXPosition(), newGame->gamePowerUp->getYPosition(), newGame->bulletCollision);
			if (playerPowerUpCollide == true)
			{
				switch (newGame->gamePowerUp->getPowerType())
				{
					case true:{
						newGame->gamePowerUp->hidePowerUp();
						newGame->tankArr[j].maxSpeed = newGame->tankArr[j].maxSpeed * 2;
						newGame->tankArr[j].acceleration = newGame->tankArr[j].acceleration * 2;
						newGame->powerUpTimer = 0;
						newGame->tankArr[j].speedPowerUpActive = true;
						newGame->tankArr[j].powerUpCounter = 0;
						break;
					}
					case false:{
						newGame->gamePowerUp->hidePowerUp();
						newGame->powerUpTimer = 0;
						newGame->tankArr[j].godModePowerUpActive = true;
						newGame->tankArr[j].powerUpCounter = 0;
						break;
					}
				}
			}
	}
	
	
	

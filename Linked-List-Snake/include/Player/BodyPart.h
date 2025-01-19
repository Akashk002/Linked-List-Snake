#pragma once
#include <UI/LevelSelection/LevelSelectionUIController.h>
#include <SFML/System/Vector2.hpp>
#include "Direction.h"
#include <SFML/Graphics.hpp>

namespace Player
{
	class BodyPart
	{
	private:
		UI::UIElement::ImageView* bodypart_image;

		sf::Vector2i grid_position;
		Direction direction;

		float bodypart_width;
		float bodypart_height;
	public:
		BodyPart();
		~BodyPart();

		void initialize(float width, float height, sf::Vector2i pos, Direction dir);
		void update();
		void render();

		void destroy();

		void createBodyPartImage();
		void initializeBodyPartImage();
		 float getRotationAngle() ;
		sf::Vector2f getBodyPartScreenPosition();
		void setDirection(Direction direction);
		Direction GetDirection();
		sf::Vector2i getPosition();
		void updatePosition();
		sf::Vector2i getNextPositionUp();
		sf::Vector2i getNextPositionDown();
		sf::Vector2i getNextPositionLeft();
		sf::Vector2i getNextPositionRight();
		sf::Vector2i getNextPosition();
		void setPosition(sf::Vector2i position)

	};
}
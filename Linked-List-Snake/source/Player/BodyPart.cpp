#include "../../include/Player/BodyPart.h"
#include "../../include/Global/Config.h"
#include "../../include/Level/LevelView.h"
#include "../../include/Level/LevelModel.h"

namespace Player
{
	using namespace Level;

	BodyPart::BodyPart()
	{
		grid_position = sf::Vector2i(0, 0);
		bodypart_image = nullptr;
		createBodyPartImage();
	}

	BodyPart::~BodyPart()
	{
		destroy();
	}

	void BodyPart::createBodyPartImage()
	{
		bodypart_image = new UI::UIElement::ImageView();
	}

	void BodyPart::initialize(float width, float height, sf::Vector2i pos, Direction dir)
	{
		bodypart_width = width;
		bodypart_height = height;
		direction = dir;
		grid_position = pos;

		initializeBodyPartImage();
	}

	void BodyPart::update()
	{
	
	}

	void BodyPart::render()
	{
		bodypart_image->render();
	}
	void BodyPart::initializeBodyPartImage()
	{

	}

	sf::Vector2f BodyPart::getBodyPartScreenPosition()
	{
		float x_screen_position = LevelView::border_offset_left + (grid_position.x * bodypart_width) + (bodypart_width / 2);
		float y_screen_position = LevelView::border_offset_top + (grid_position.y * bodypart_height) + (bodypart_height / 2);

		return sf::Vector2f(x_screen_position, y_screen_position);
	}

	float BodyPart::getRotationAngle()
	{
		switch (direction)
		{
		case Direction::UP:
			return 270.f;
		case Direction::DOWN:
			return 90.f;
		case Direction::RIGHT:
			return 0;
		case Direction::LEFT:
			return 180.f;
		}
	}

	void BodyPart::setDirection(Direction direction)
	{
		this->direction = direction;
	}

	void BodyPart::destroy()
	{
		delete (bodypart_image);
	}
}
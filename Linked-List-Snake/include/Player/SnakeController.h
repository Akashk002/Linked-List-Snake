#pragma once
#include <Graphics/GraphicService.h>
#include "./Player/Direction.h"
#include "../LinkedList/SingleLinkedList.h"

namespace Player
{
	enum class SnakeState
	{
		ALIVE,
		DEAD,
	};

	enum class InputState
	{
		WAITING,
		PROCESSING
	};
	class SnakeController
	{
	private:
		const int initial_snake_length = 10;

		const sf::Vector2i default_position = sf::Vector2i(25, 13);
		const Direction default_direction = Direction::RIGHT;
		const float movement_frame_duration = 0.1f;
		const float restart_duration = 2.f;
		 float restart_counter;

		SnakeState current_snake_state;
		float elapsed_duration = 0.f;
		Direction current_snake_direction;
		InputState current_input_state;

		void processPlayerInput();
		void updateSnakeDirection();
		void moveSnake();
		void processSnakeCollision();
		void handleRestart();
		void reset();
		void destroy();

	public:
		SnakeController();
		~SnakeController();

		void initialize();
		void update();
		void render();

		void spawnSnake();
		void respawnSnake();
		void setSnakeState(SnakeState state);
		SnakeState getSnakeState();
		LinkedList::SingleLinkedList* single_linked_list;
		void createLinkedList();
		void delayedUpdate();
	};
}
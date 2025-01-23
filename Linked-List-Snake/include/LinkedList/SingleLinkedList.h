#pragma once
#include <SFML/System/Vector2.hpp>
#include "LinkedList/Node.h"
#include <Player/Direction.h>

namespace LinkedList
{
	struct Node;

	class SingleLinkedList
	{
	private:
		Node* head_node;

		float node_width;
		float node_height;

		sf::Vector2i default_position;
		Player::Direction default_direction;

		Node* createNode();
		sf::Vector2i getNewNodePosition(Node* reference_node);
		
	public:
		void insertNodeAtTail();


		void createHeadNode();

	
		SingleLinkedList();
		~SingleLinkedList();

		void initialize(float width, float height, sf::Vector2i position, Player::Direction direction);
		void render();
		void updateNodePosition();
		void updateNodeDirection(Player::Direction direction_to_set);
		bool processNodeCollision();
		void removeNodeAtHead();
		void removeAllNodes();
	};
}
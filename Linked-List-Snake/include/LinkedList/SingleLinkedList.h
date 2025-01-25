#pragma once
#include <SFML/System/Vector2.hpp>
#include "LinkedList/Node.h"
#include <Player/Direction.h>

namespace LinkedList
{
	struct Node;

	enum class Operation
	{
		HEAD,
		MID,
		TAIL,
	};

	class SingleLinkedList
	{
	private:
		Node* head_node;

		float node_width;
		float node_height;

		sf::Vector2i default_position;
		Player::Direction default_direction;
		int linked_list_size = 0;

		Node* createNode();
		sf::Vector2i getNewNodePosition(Node* reference_node, Operation operation);
		
	public:
		void insertNodeAtTail();

		void insertNodeAtIndex(int index);

		void shiftNodesAfterInsertion(Node* new_node, Node* cur_node, Node* prev_node);

		int findMiddleNode();

		void insertNodeAtMiddle();

		void initializeNode(Node* new_node, Node* reference_node, Operation operation);


		void createHeadNode();

	
		SingleLinkedList();
		~SingleLinkedList();

		void initialize(float width, float height, sf::Vector2i position, Player::Direction direction);
		void render();
		void updateNodePosition();
		void updateNodeDirection(Player::Direction direction_to_set);
		bool processNodeCollision();
		void removeNodeAtHead();
		std::vector<sf::Vector2i> getNodesPositionList();
		void insertNodeAtHead();
		void removeAllNodes();

		Node* getHeadNode();
	};
}